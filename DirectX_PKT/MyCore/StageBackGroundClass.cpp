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

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	Renderer->SetupAttachment(Default);


	StageBackRender = CreateDefaultSubObject<USpriteRenderer>("StageBackRender");
	StageBackRender->SetScale({ 1600,720 });
	StageBackRender->SetSprite("OneOffice.png");
	//StageBackRender->SetPosition({ 0,0 });
	StageBackRender->SetOrder(OrderType::BackGround);
	StageBackRender->CreateAnimation("LeftLightAnimation", "Office.png", 0.1f, false, 0, 2);



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

void StageBackGroundClass::ChangeBackGround()
{
	StageBackRender->ChangeAnimation("LeftLightAnimation");
	StageBackRender->SetFrameCallback("LeftLightAnimation", 2, [=]
		{
			
			while (DelayTime < 5)
			{
				DelayTime += 1;
				StageBackRender->SetSprite("Office.png", 2);
				if (DelayTime >= 3)
				{
					StageBackRender->SetSprite("Office.png", 1);
					break;
				}
			}
			
			
			
			
		});


}

