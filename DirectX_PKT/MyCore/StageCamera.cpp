#include "PreCompile.h"
#include "StageCamera.h"
#include<EngineCore/Collision.h>
#include"MyCore.h"
#include<EngineCore/DefaultSceneComponent.h>
#include"CCTVBackGround.h"
#include "Stage.h"

StageCamera::StageCamera()
{
	StageCameraRender = CreateDefaultSubObject<USpriteRenderer>("StageCameraRender");
	StageCameraRender->SetAutoSize(1.0f, true);
	StageCameraRender->CreateAnimation("CameraAnimtaion", "StageCam.png", 0.05f, false);
	StageCameraRender->CreateAnimation("CloseCameraAnimation", "CCTVClose", 0.05f, false, 1, 10);
	StageCameraRender->SetOrder(22);

	CCTVCam = CreateDefaultSubObject<USpriteRenderer>("CCTVCam");
	CCTVCam->SetSprite("TestCamBackGround.png");
	CCTVCam->SetAutoSize(1.0f, true);
	CCTVCam->SetupAttachment(StageCameraRender);
	CCTVCam->SetOrder(20);
	CCTVCam->SetActive(false);


	SetRoot(StageCameraRender);

}

StageCamera::~StageCamera()
{
}
void StageCamera::BeginPlay()
{	
	//stageLevel에서 내가 선언한 엑터를 가져와서 사용하는 방법 
	StageLevel = dynamic_cast<Stage*>(GetWorld()->GetGameMode().get());
	CCTVBackGrounds = StageLevel->GetCCTVBack();

	
	Super::BeginPlay();

}
void StageCamera::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	StageCameraRender->SetFrameCallback("CameraAnimtaion", 8, [&]
		{
			if (isCamOn == false)
			{
				isCamOn = true;
				CCTVBackGrounds->CCTVON();


			}

			// 여기에 CCTV 배경을 넣을것이다. 
		}
	);

}
void StageCamera::CamCCTVOn()
{
	StageCameraRender->AnimationReset();
	StageCameraRender->ChangeAnimation("CameraAnimtaion");

	//bool Check = StageCameraRender->IsCurAnimationEnd();
	

}


void StageCamera::CamCCTVOff()
{

	StageCameraRender->SetActive(true);
	StageCameraRender->ChangeAnimation("CloseCameraAnimation");
	CCTVBackGrounds->CCTVOFF();
	StageCameraRender->SetLastFrameCallback("CloseCameraAnimation", [=]
		{
			if (isCamOn == true)
			{
			isCamOn = false;
			StageCameraRender->SetActive(false);
			}

		});
	
}
