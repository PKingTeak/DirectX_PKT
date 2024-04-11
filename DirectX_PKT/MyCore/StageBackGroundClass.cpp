#include "PreCompile.h"
#include "StageBackGroundClass.h"
StageBackGroundClass::StageBackGroundClass()
{
	StageBackRender = CreateDefaultSubObject<USpriteRenderer>("StageBackRender");
}
StageBackGroundClass::~StageBackGroundClass()
{


}
void StageBackGroundClass::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(1280.0f, 720.0f, 100.0f)); //직교 투영에서는 의미가 없다. 
	StageBackRender->SetSprite("OneOffice.png");
	

}

/*
	StageBackRender->CreateAnimation("FanAnimation" , "Fan.png",1,3,0.1f, true);
	StageBackRender->ChangeAnimation("FanAnimation");
*/

void StageBackGroundClass::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
}