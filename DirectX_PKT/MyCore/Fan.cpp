#include "PreCompile.h"
#include "Fan.h"
Fan::Fan()
{
	ObjectRender = CreateDefaultSubObject<USpriteRenderer>("ObjectRender");
	SetRoot(ObjectRender);
}
Fan::~Fan()
{


}
void Fan::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(138.0f, 200.0f, 50.0f)); //직교 투영에서는 의미가 없다. 
	
	ObjectRender->CreateAnimation("FanAnimation", "Fan.png", 1, 3, 0.00001f, true);
	ObjectRender->ChangeAnimation("FanAnimation");
	
	//this->SetActorTransform(1280.0f / 2, 720.0f / 2);
	
}


void Fan::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}