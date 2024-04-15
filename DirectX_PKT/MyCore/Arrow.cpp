#include "PreCompile.h"
#include "Arrow.h"
#include<EngineCore/Collision.h>
#include"MyCore.h"

Arrow::Arrow() 
{
	ArrowRender = CreateDefaultSubObject<USpriteRenderer>("ArrowRender");
	ArrowRender->SetSprite("Arrow.png");
	ArrowRender->AddPosition({ 0,-320,0 });
	ArrowRender->SetAutoSize(1.0f, true);
	ArrowRender->SetOrder(10);


	ArrowCollision = CreateDefaultSubObject<UCollision>("ArrowCollision");
	ArrowCollision->SetupAttachment(ArrowRender);
	ArrowCollision->SetScale(ArrowRender->GetLocalScale());
	ArrowCollision->SetCollisionGroup(OrderType::UI);
	ArrowCollision->SetCollisionType(ECollisionType::Rect);
	
	

	SetRoot(ArrowRender);
}

Arrow::~Arrow() 
{
}
void Arrow::BeginPlay()
{
		
	Super::BeginPlay();

} 
void Arrow::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
