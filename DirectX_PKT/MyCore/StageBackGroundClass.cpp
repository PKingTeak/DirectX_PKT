#include "PreCompile.h"
#include "StageBackGroundClass.h"
#include<EngineCore/DefaultSceneComponent.h>



StageBackGroundClass::StageBackGroundClass()
{
	UDefaultSceneComponent* Default = CreateDefaultSubObject<UDefaultSceneComponent>("Defualt");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	Renderer->SetupAttachment(Default);
	StageUIRenderer = CreateDefaultSubObject<USpriteRenderer>("UIRender");
	StageUIRenderer->SetupAttachment(Default);
	StageBackRender = CreateDefaultSubObject<USpriteRenderer>("StageBackRender");
	StageBackRender->SetupAttachment(Default);
	SetRoot(Default);
}
StageBackGroundClass::~StageBackGroundClass()
{


}
void StageBackGroundClass::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(1280.0f, 720.0f, 100.0f)); //직교 투영에서는 의미가 없다. 
	
	StageBackRender->SetSprite("OneOffice.png");
	StageBackRender->SetAutoSize(1.0f,true);
	StageBackRender->SetOrder(5);


	//UIInfo.push_back()
	StageUIRenderer->SetSprite("Arrow.png"); // 화살표 UI 
	StageUIRenderer->AddPosition({ 0,-320,0 });
	StageUIRenderer->SetAutoSize(1.0f, true);
	StageUIRenderer->SetOrder(10);
}

/*
	StageBackRender->CreateAnimation("FanAnimation" , "Fan.png",1,3,0.1f, true);
	StageBackRender->ChangeAnimation("FanAnimation");
*/

void StageBackGroundClass::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
}