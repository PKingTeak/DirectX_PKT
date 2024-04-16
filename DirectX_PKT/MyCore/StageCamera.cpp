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
	
	CCTVCam = CreateDefaultSubObject<USpriteRenderer>("CCTVCam");
	CCTVCam->SetSprite("TestCamBackGround.png");
	CCTVCam->SetAutoSize(1.0f, true);
	CCTVCam->SetupAttachment(StageCameraRender);
	CCTVCam->SetOrder(210);
	CCTVCam->SetActive(false);


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
	
}
void StageCamera::ChangeAnimation()
{
	StageCameraRender->ChangeAnimation("CameraAnimtaion");
	bool Check = StageCameraRender->IsCurAnimationEnd();
	StageCameraRender->SetFrameCallback("CameraAnimtaion", 8, [=]
		{
			
			GEngine->ChangeLevel("CamLevel");
		}
	);
	
}
