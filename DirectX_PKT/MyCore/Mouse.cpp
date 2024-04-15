#include "PreCompile.h"
#include "Mouse.h"
#include<EngineCore/Collision.h>

Mouse::Mouse()
{
	
	MouseCollision = CreateDefaultSubObject<UCollision>("MouseCollision");
	MouseCollision->SetupAttachment(MouseCollision);
	MouseCollision->SetScale(FVector{ 50,50,50 });
	MouseCollision->SetCollisionGroup(OrderType::UI);
	MouseCollision->SetCollisionType(ECollisionType::CirCle);
}

Mouse::~Mouse()
{
}
void Mouse::BeginPlay()
{
	Super::BeginPlay();
	
}
	
void Mouse::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	SetMousePos();
}

void Mouse::SetMousePos()
{
	MousePos = GEngine->EngineWindow.GetScreenMousePos();
}
