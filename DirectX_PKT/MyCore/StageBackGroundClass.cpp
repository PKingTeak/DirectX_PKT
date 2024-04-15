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
	StageBackRender->SetOrder(5);


	
}

void StageBackGroundClass::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
}