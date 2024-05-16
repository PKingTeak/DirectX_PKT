#include "PreCompile.h"
#include "StageBackGroundClass.h"
#include<EngineCore/DefaultSceneComponent.h>
#include"MyCore.h"
#include<iostream>
#include"Animatronics.h"
#include"Door.h"
#include<EngineBase/EngineRandom.h>
#include"Stage.h"
#include"Lobby.h"
StageBackGroundClass* StageBackGroundClass::MainStageBackGround = nullptr;



StageBackGroundClass::StageBackGroundClass()
{

	
	MainStageBackGround = this;
	UDefaultSceneComponent* Default = CreateDefaultSubObject<UDefaultSceneComponent>("Defualt");
	Default->SetPosition(FVector{ 0,0 });

	JumpScare = CreateDefaultSubObject<USpriteRenderer>("Render");
	JumpScare->SetAutoSize(1.0f, true);
	JumpScare->CreateAnimation("BonniAni", "Bonni", 0.05f, false, 0, 10);
	JumpScare->CreateAnimation("ChicaAni", "ChicaImage", 0.05f, false, 0, 15);
	JumpScare->SetupAttachment(Default);
	JumpScare->SetOrder(200);


	StageBackRender = CreateDefaultSubObject<USpriteRenderer>("StageBackRender");
	StageBackRender->SetScale({ 1600,720 });
	StageBackRender->SetSprite("OneOffice.png");
	StageBackRender->SetOrder(OrderType::BackGround);
	StageBackRender->CreateAnimation("LeftLightAnimation", "Office.png", 0.1f, true, 1, 2);
	StageBackRender->CreateAnimation("NoElecAnimation", "NoElec", 0.1f, true, 0, 1);

	TurnoffLobby = CreateDefaultSubObject<USpriteRenderer>("TurnoffLobbyRender");
	TurnoffLobby->SetScale({ 1600,720 });
	TurnoffLobby->SetSprite("NoElecStatic.png");
	TurnoffLobby->SetOrder(20);
	TurnoffLobby->CreateAnimation("FreddyAni", "NoElec", 0.1f, true, 0, 1);
	TurnoffLobby->CreateAnimation("BlinkAni", "NoElecBlink", 0.4f, false ,0, 4);
	TurnoffLobby->CreateAnimation("BlinkFreddyAni", "NoElecFreddy", 0.05f, false, 0, 20);

	TurnoffLobby->SetActive(false);
	

	
	//SetAutoSize(1.0f, true);
	//

	StageBackRender->SetupAttachment(Default);



	LobbySound = UEngineSound::SoundPlay("Office.wav");
	LobbySound.SetVolume(0.4f);
	LobbySound.Loop();
	LobbySound.Off();


	JumpScareSound = UEngineSound::SoundPlay("JumpScare.wav");
	JumpScareSound.SetVolume(0.7f);
	JumpScareSound.Off();

	LightSound = UEngineSound::SoundPlay("DoorLight.wav");
	LightSound.SetVolume(1.0f);
	LightSound.Off();

	TurnOffSound = UEngineSound::SoundPlay("PowerDown.wav");
	TurnOffSound.SetVolume(1.0f);
	TurnOffSound.Off();

	ToyMusicSound = UEngineSound::SoundPlay("MusicBox.wav");
	ToyMusicSound.SetVolume(1.0f);
	ToyMusicSound.Off();

	MonsterLightSound = UEngineSound::SoundPlay("WindowScare.wav");
	MonsterLightSound.Off();

	SetRoot(Default);

	TurnoffLobby->SetLastFrameCallback("BlinkFreddyAni", [=]
		{
			GEngine->ChangeLevel("EndingLevel");
		});
}
StageBackGroundClass::~StageBackGroundClass()
{


}
void StageBackGroundClass::BeginPlay()
{
	MainStageBackGround = this;
	MainStage = dynamic_cast<Stage*>(GetWorld()->GetGameMode().get());
	Super::BeginPlay();
	
	
}

void StageBackGroundClass::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	CountMonsterTime(_DeltaTime);
	SetLobbySound();
	BatteryOff();
	
	
	TickTimeChecker += _DeltaTime;
	if (TickTimeChecker > 5)
	{
		

		

		if (StageLightCheck == true)
		{
			TurnoffLobby->ChangeAnimation("FreddyAni");
			ToyMusicSound.On();
			AniCount++;
		}
		
		if (AniCount >= 3)
		{
			ToyMusicSound.Off();
			TurnoffLobby->ChangeAnimation("BlinkFreddyAni");
			JumpScareSound.On();

		}

		TickTimeChecker = 0;
	}

}

StageBackGroundClass* StageBackGroundClass::GetMainStageBackGround()
{
	return MainStageBackGround;
}

void StageBackGroundClass::ChangeBackGround(std::string _RoomState)
{


}
void StageBackGroundClass::LightOn(std::string _Dir)
{
	LightSound.On();
	LightSound.Replay();
	std::string Dir = _Dir;

	if (LeftLight == false && Dir == "Left")
	{
		if (Monster != nullptr)
		{
			StageBackRender->SetSprite("Office.png", 4); //보니가 나온 라이트 
			MonsterLightSound.On();
			MonsterLightSound.Replay();
			LeftLight = true;
			return;
		}
		//조명 켜기
		StageBackRender->SetSprite("Office.png", 2);
		LeftLight = true;
	}

	else if (LeftLight == true)
	{
		// 조명 끄기
		StageBackRender->SetSprite("Office.png", 0);
		LeftLight = false;
		LightSound.Off();
	}


	else if (RightLight == false && Dir == "Right")
	{
		if (Monster != nullptr)
		{
			StageBackRender->SetSprite("Office.png", 5);
			MonsterLightSound.On();
			MonsterLightSound.Replay();
			RightLight = true;
			return;
		}
		StageBackRender->SetSprite("Office.png", 3);
		RightLight = true;
	}

	else if (RightLight == true)
	{
		StageBackRender->SetSprite("Office.png", 0);
		RightLight = false;
		LightSound.Off();
	}


}


void StageBackGroundClass::PlayJumpScare(std::string _Name)

{
	//원하는 몬스터 가 나오도록 
	JumpScare->ChangeAnimation(_Name.append("Ani"));
	JumpScareSound.On();
	JumpScare->SetLastFrameCallback("BonniAni",[=]
		{
			GEngine->ChangeLevel("EndingLevel");
		 //엔딩 GameOver올려줘야될듯
		}
	
	
	);

	JumpScare->SetLastFrameCallback("ChicaAni", [=]
		{
			GEngine->ChangeLevel("EndingLevel");
			LobbySound.Off();
			//엔딩 GameOver올려줘야될듯
		}


	);
}

void StageBackGroundClass:: SetLobbyMonster(Animatronics* _Monster)
{
	
	Monster = _Monster;
}

void StageBackGroundClass::CountMonsterTime(float _DeltaTime)
{

	LobbyDoor = MainStage->GetStageDoor();


	if (Monster != nullptr)
	{
		

		if (Monster->GetName() == "Bonni")
		{
			Time += _DeltaTime;
			if (Time > 7)
			{


			if (LobbyDoor->GetLeftDoorState() == false)
			{
				//문이 닫혀있다. 
				BlockCheck = true;
				SetLobbyMonster(nullptr); // 몬스터 빼준다. 
				Time = 0;
				return;
				//여기서 돌아가는 기능이 작동을 안한다. 

			}
			else
			{
				PlayJumpScare(Monster->GetName());
				BlockCheck = false;
			}
			}

		}
		if (Monster->GetName() == "Chica")
		{
			Time += _DeltaTime;
			if (Time > 5)
			{
				if (LobbyDoor->GetRightDoorState() == false)
				{
					RBlockCheck = true;
					SetLobbyMonster(nullptr); // 몬스터 빼준다. 
					Time = 0;
					return;
				}

				else
				{
					PlayJumpScare(Monster->GetName());
					
				}


			}

		}

		

	}
}
void StageBackGroundClass::BatteryOff()
{
	MainStage = dynamic_cast<Stage*>(GetWorld()->GetGameMode().get());
	BatteryUI = MainStage->GetStageLobbyUI();
	int BatteryP = BatteryUI->GetBatteryPower();
	if (BatteryP <= 0)
	{
		TurnoffLobby->SetActive(true);
		TurnOffSound.On();
		StageLightCheck = true;
	}
	
}

bool StageBackGroundClass::BlockChecker()
{
	return BlockCheck;
}

bool StageBackGroundClass::RightBlockChecker()
{
	return RBlockCheck;
}
bool StageBackGroundClass::LeftLightChecker()
{
	return LeftLight;
}

bool StageBackGroundClass::RightLightChecker()
{
	return RightLight;
}

void StageBackGroundClass::SetLobbySound()
{
	if (true == this->IsActive())
	{

		LobbySound.On();
	
	}
	else
	{
		LobbySound.Off();
	}
}