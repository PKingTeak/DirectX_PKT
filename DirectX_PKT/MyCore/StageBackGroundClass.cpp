#include "PreCompile.h"
#include "StageBackGroundClass.h"
#include<EngineCore/DefaultSceneComponent.h>
#include"MyCore.h"
#include<iostream>
#include"Animatronics.h"
#include"Door.h"
#include<EngineBase/EngineRandom.h>

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


	
	//SetAutoSize(1.0f, true);
	//

	StageBackRender->SetupAttachment(Default);



	LobbySound = UEngineSound::SoundPlay("Office.wav");
	LobbySound.SetVolume(0.1f);
	LobbySound.Loop();
	LobbySound.Off();

	SetRoot(Default);
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

	std::string Dir = _Dir;

	if (LeftLight == false && Dir == "Left")
	{
		if (Monster != nullptr)
		{
			StageBackRender->SetSprite("Office.png", 4); //���ϰ� ���� ����Ʈ 
			LeftLight = true;
			return;
		}
		//���� �ѱ�
		StageBackRender->SetSprite("Office.png", 2);
		LeftLight = true;
	}

	else if (LeftLight == true)
	{
		// ���� ����
		StageBackRender->SetSprite("Office.png", 0);
		LeftLight = false;
	}


	else if (RightLight == false && Dir == "Right")
	{
		if (Monster != nullptr)
		{
			StageBackRender->SetSprite("Office.png", 5);
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
	}


}


void StageBackGroundClass::PlayJumpScare(std::string _Name)

{
	//���ϴ� ���� �� �������� 
	JumpScare->ChangeAnimation(_Name.append("Ani"));
	JumpScare->SetLastFrameCallback("BonniAni",[=]
		{
			GEngine->ChangeLevel("EndingLevel");
		 //���� GameOver�÷���ߵɵ�
		}
	
	
	);

	JumpScare->SetLastFrameCallback("ChicaAni", [=]
		{
			GEngine->ChangeLevel("EndingLevel");
			//���� GameOver�÷���ߵɵ�
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
				//���� �����ִ�. 
				BlockCheck = true;
				SetLobbyMonster(nullptr); // ���� ���ش�. 
				Time = 0;
				return;
				//���⼭ ���ư��� ����� �۵��� ���Ѵ�. 

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
					SetLobbyMonster(nullptr); // ���� ���ش�. 
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