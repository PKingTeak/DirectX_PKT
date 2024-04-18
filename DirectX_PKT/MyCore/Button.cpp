#include "PreCompile.h"
#include "Button.h"
#include "Stage.h"
Button::Button()
{
	ObjectRender = CreateDefaultSubObject<USpriteRenderer>("ObjectRender");
	SetRoot(ObjectRender);

}
Button::~Button()
{


}
void Button::BeginPlay()
{
	Super::BeginPlay();

	//SetActorScale3D(FVector(132.0f, 200.0f, 100.0f)); //직교 투영에서는 의미가 없다. 

	ObjectRender->SetAutoSize(1.0f, true);
	ObjectRender->CreateAnimation("ButtonAnimation", "Button.png", 0, 2, 0.001f, true);
	ObjectRender->ChangeAnimation("ButtonAnimation");
	ObjectRender->SetOrder(10);


}


void Button::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

void ButtonLight()
{
}

void ButtonDoor()
{

}