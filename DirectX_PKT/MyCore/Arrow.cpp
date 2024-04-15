#include "PreCompile.h"
#include "Arrow.h"
#include<EngineCore/Collision.h>
#include"MyCore.h"
#include<EngineCore/DefaultSceneComponent.h>

Arrow::Arrow() 
{
	

	//UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");


	ArrowRender = CreateDefaultSubObject<USpriteRenderer>("ArrowRender");
	ArrowRender->SetSprite("Arrow.png");
	ArrowRender->AddPosition({ 0,0,0 });
	ArrowRender->SetAutoSize(1.0f, true);
	ArrowRender->SetOrder(10);


	ArrowCollision = CreateDefaultSubObject<UCollision>("ArrowCollision");
	//ArrowCollision->SetScale(ArrowRender->GetLocalScale());
	ArrowCollision->SetCollisionGroup(OrderType::UI);
	ArrowCollision->SetCollisionType(ECollisionType::Rect);
	ArrowCollision->SetupAttachment(ArrowRender);

	TestRender = CreateDefaultSubObject<USpriteRenderer>("TestRender");
	TestRender->SetSprite("Noise.png");
	TestRender->AddPosition({0,0});
	TestRender->SetOrder(15);
	TestRender->SetupAttachment(ArrowRender);

	

	SetRoot(ArrowRender);
}

Arrow::~Arrow() 
{
}
void Arrow::BeginPlay()
{
	Super::BeginPlay();
	this->SetActorLocation({ 0,-320,0 });

} 
void Arrow::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
