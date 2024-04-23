#include "PreCompile.h"
#include "Button.h"
#include "Stage.h"
#include<EngineCore/DefaultSceneComponent.h>
Button::Button()
{

	UDefaultSceneComponent* Defualt = CreateDefaultSubObject<UDefaultSceneComponent>("Defualt");

	ObjectRender = CreateDefaultSubObject<USpriteRenderer>("ObjectRender");
	ObjectRender->SetSprite("Button.png");
	ObjectRender->SetAutoSize(1.0f, true);
	
	
	ObjectRender->SetOrder(20);
	ObjectRender->SetupAttachment(Defualt);
	
	DoorButton = CreateDefaultSubObject<UCollision> ("DoorButton");
	DoorButton->SetCollisionGroup(ECollisionType::Rect);
	DoorButton->SetPosition(FVector{ 0,50 });
	DoorButton->SetupAttachment(ObjectRender);
	DoorButton->SetScale(FVector{ 50,50 });


	LightButton = CreateDefaultSubObject<UCollision>("LightButton");
	LightButton->SetCollisionGroup(ECollisionType::Rect);
	LightButton->SetupAttachment(ObjectRender);
	LightButton->SetScale(FVector{ 50,50 });
	
	
	
	SetRoot(Defualt);

}
Button::~Button()
{


}
void Button::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector{ -760,-20 });
	//ObjectRender->SetPosition(FVector{ -760,-20 });
	//SetActorScale3D(FVector(132.0f, 200.0f, 100.0f)); //직교 투영에서는 의미가 없다. 



}


void Button::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

void Button::ButtonLight()
{
}

void Button::ButtonDoor()
{

}
void Button::MoveButton(FVector _SetPos)
{
	SetActorLocation(_SetPos);

}


