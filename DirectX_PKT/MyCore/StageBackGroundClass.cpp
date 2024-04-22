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
	StageUIRenderer = CreateDefaultSubObject<USpriteRenderer>("UIRender");
	StageUIRenderer->SetupAttachment(Default);
	StageBackRender = CreateDefaultSubObject<USpriteRenderer>("StageBackRender");
	StageBackRender->SetAutoSize(1.0f, true);
	StageBackRender->SetupAttachment(Default);

	LeftBox = CreateDefaultSubObject<UCollision>("LeftBoxCol");
	LeftBox->SetCollisionGroup(OrderType::UI);
	LeftBox->SetScale(FVector{ 320,720 });
	LeftBox->SetCollisionType(ECollisionType::Rect);
	LeftBox->AddPosition({ -200,0 });
	LeftBox->SetupAttachment(Default);
	


	RightBox = CreateDefaultSubObject<UCollision>("RightBoxBoxCol");
	RightBox->SetCollisionGroup(OrderType::UI);
	RightBox->SetScale(FVector{ 320,720 });
	RightBox->AddPosition({ 200,0 ,50 });
	RightBox->SetCollisionType(ECollisionType::Rect);
	RightBox->SetupAttachment(Default);




	SetRoot(Default);
}
StageBackGroundClass::~StageBackGroundClass()
{


}
void StageBackGroundClass::BeginPlay()
{
	Super::BeginPlay();
	

	StageBackRender->SetSprite("OneOffice.png");
	StageBackRender->SetOrder(5);

	
	
}

void StageBackGroundClass::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
}

StageBackGroundClass* StageBackGroundClass::GetMainStageBackGround()
{
	return this;
}

void StageBackGroundClass::CheckColBox(UCollision* _ColBox) //마우스 클래스에서 사용할듯
{
	std::string BoxName =  _ColBox->GetName();
	if (BoxName == "LeftBoxCol")
	{
		ColDir = true;
		int a = 0;

	}
	else if (BoxName == "RightBoxCol")
	{


	}
}