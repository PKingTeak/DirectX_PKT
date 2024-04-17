#include "PreCompile.h"
#include "StageBackGroundClass.h"
#include<EngineCore/DefaultSceneComponent.h>
#include"MyCore.h"



StageBackGroundClass::StageBackGroundClass()
{
	
	UDefaultSceneComponent* Default = CreateDefaultSubObject<UDefaultSceneComponent>("Defualt");
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Render");
	Renderer->SetupAttachment(Default);
	StageUIRenderer = CreateDefaultSubObject<USpriteRenderer>("UIRender");
	StageUIRenderer->SetupAttachment(Default);
	StageBackRender = CreateDefaultSubObject<USpriteRenderer>("StageBackRender");
	StageBackRender->SetupAttachment(Default);

	LeftBox = CreateDefaultSubObject<UCollision>("LeftBoxCol");
	LeftBox->SetCollisionGroup(OrderType::UI);
	LeftBox->SetScale(FVector{ 500,720, });
	LeftBox->SetOrder(100);
	LeftBox->SetCollisionType(ECollisionType::Rect);
	LeftBox->AddPosition({ -200,0 });
	LeftBox->SetupAttachment(Default);
	


	RightBox = CreateDefaultSubObject<UCollision>("RightBoxBoxCol");
	RightBox->SetCollisionGroup(OrderType::UI);
	RightBox->SetScale(FVector{ 500,720,});
	RightBox->AddPosition({ 200,0 });
	RightBox->SetOrder(100);
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
	SetActorScale3D(FVector(1280.0f, 720.0f, 100.0f)); //직교 투영에서는 의미가 없다. 
	
	StageBackRender->SetSprite("OneOffice.png");
	StageBackRender->SetOrder(5);

	
}

void StageBackGroundClass::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
}