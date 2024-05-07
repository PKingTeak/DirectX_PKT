#include "PreCompile.h"
#include "StageBackGroundClass.h"
#include<EngineCore/DefaultSceneComponent.h>
#include"MyCore.h"
#include<iostream>
#include"Animatronics.h"
#include"Door.h"

StageBackGroundClass* StageBackGroundClass::MainStageBackGround = nullptr;



StageBackGroundClass::StageBackGroundClass()
{

	MainStageBackGround = this;
	UDefaultSceneComponent* Default = CreateDefaultSubObject<UDefaultSceneComponent>("Defualt");
	Default->SetPosition(FVector{ 0,0 });

	JumpScare = CreateDefaultSubObject<USpriteRenderer>("Render");
	JumpScare->SetAutoSize(1.0f, true);
	JumpScare->CreateAnimation("BonniAni", "Bonni", 0.05f, false, 0, 10);
	JumpScare->SetupAttachment(Default);
	JumpScare->SetOrder(200);


	StageBackRender = CreateDefaultSubObject<USpriteRenderer>("StageBackRender");
	StageBackRender->SetScale({ 1600,720 });
	StageBackRender->SetSprite("OneOffice.png");
	//StageBackRender->SetPosition({ 0,0 });
	StageBackRender->SetOrder(OrderType::BackGround);
	StageBackRender->CreateAnimation("LeftLightAnimation", "Office.png", 0.1f, true, 1, 2);
	//StageBackRender->CreateAnimation("")
	StageBackRender->CreateAnimation("NoElecAnimation", "NoElec", 0.1f, true, 0, 1);



	//SetAutoSize(1.0f, true);
	//

	StageBackRender->SetupAttachment(Default);





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
	if (LeftLight == false)
	{
		if (Monster != nullptr)
		{
			StageBackRender->SetSprite("Office.png", 4);
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
	}



}


void StageBackGroundClass::PlayJumpScare(std::string _Name)

{
	//원하는 몬스터 가 나오도록 
	JumpScare->ChangeAnimation(_Name.append("Ani"));
	JumpScare->SetLastFrameCallback("BonniAni",[=]
		{
			GEngine->ChangeLevel("EndingLevel");
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
		Time += _DeltaTime;
		

		if (Time > 7 )
		{
			if(Monster->GetName() == "Bonni" && LobbyDoor->GetLeftDoorState() == false)
			{
				SetLobbyMonster(nullptr);
				return;
			}

			PlayJumpScare(Monster->GetName());
		}

	}
}
