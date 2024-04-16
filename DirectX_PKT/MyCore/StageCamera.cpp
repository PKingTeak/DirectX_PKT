#include "PreCompile.h"
#include "StageCamera.h"
#include<EngineCore/Collision.h>
#include"MyCore.h"
#include<EngineCore/DefaultSceneComponent.h>

StageCamera::StageCamera()
{
	StageCameraRender = CreateDefaultSubObject<USpriteRenderer>("StageCameraRender");
	StageCameraRender->SetAutoSize(1.0f, true);
	StageCameraRender->CreateAnimation("CameraAnimtaion", "StageCam.png", 0.05f, false);
	
	StageCameraRender->SetOrder(200);
	
	SetRoot(StageCameraRender);

}

StageCamera::~StageCamera()
{
}
void StageCamera::BeginPlay()
{
	Super::BeginPlay();

}
void StageCamera::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	//if (UEngineInput::IsDown('Z'))
	//{
	//	StageCameraRender->ChangeAnimation("CameraAnimtaion");
	//
	//}
	//
}
void StageCamera::ChangeAnimation()
{
	StageCameraRender->ChangeAnimation("CameraAnimtaion");
}
