#include "PreCompile.h"
#include "StageBackGroundClass.h"
#include<EngineCore/DefaultSceneComponent.h>
#include"MyCore.h"
#include<iostream>

StageBackGroundClass* StageBackGroundClass::MainStageBackGround = nullptr;



StageBackGroundClass::StageBackGroundClass()
{

	MainStageBackGround = this;
	UDefaultSceneComponent* Default = CreateDefaultSubObject<UDefaultSceneComponent>("Defualt");
	Default->SetPosition(FVector{ 0,0 });

	JumpScare = CreateDefaultSubObject<USpriteRenderer>("Render");
	JumpScare->SetAutoSize(1.0f, true);
	JumpScare->CreateAnimation("BonniAnimation", "Bonni", 0.1f, false, 0, 10);
	JumpScare->SetupAttachment(Default);


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
	Super::BeginPlay();


}

void StageBackGroundClass::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


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



}


void StageBackGroundClass::PlayJumpScare(std::string _Name)

{
	//���ϴ� ���� �� �������� 
	JumpScare->ChangeAnimation(_Name.append(".Ani"));
}


