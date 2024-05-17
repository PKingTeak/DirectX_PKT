#include "PreCompile.h"
#include "Fan.h"
#include "Stage.h"
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

	//SetActorScale3D(FVector(132.0f, 200.0f, 100.0f)); //���� ���������� �ǹ̰� ����. 

	ObjectRender->SetAutoSize(1.0f, true);
	SetActorLocation(FVector(47.61f, -41.0f));
	ObjectRender->CreateAnimation("FanAnimation", "Fan.png", 0.001f, true ,0,2);
	ObjectRender->ChangeAnimation("FanAnimation");
	ObjectRender->SetOrder(10);

	
}


void Fan::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}