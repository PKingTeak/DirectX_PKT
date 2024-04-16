#include "PreCompile.h"
#include "StageCam.h"
#include<EngineCore/Collision.h>
#include<EngineCore/Camera.h>
#include<EngineCore/DefaultSceneComponent.h>

StageCam::StageCam()
{
	CameraRender = CreateDefaultSubObject<USpriteRenderer>("CameraRender");
	CameraRender->SetAutoSize(1.0f, true);
	CameraRender->SetOrder(20);

	SetRoot(CameraRender);

	
}

StageCam::~StageCam()
{
}
void StageCam::BeginPlay()
{
	Super::BeginPlay();
	
	CameraRender->CreateAnimation("CamAnimation","Camera.png",0.1f);

}

void StageCam::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	







}
