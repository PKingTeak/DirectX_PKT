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

}
void StageCamera::ChangeAnimation()
{
	StageCameraRender->ChangeAnimation("CameraAnimtaion");

	bool Check = StageCameraRender->IsCurAnimationEnd();
	StageCameraRender->SetFrameCallback("CameraAnimtaion", 8, [=]
		{
			if (isCamOn == false)
			{
				isCamOn = true;
				CCTVBackGrounds->CCTVON();
		
				//CCTVBackGround::GetCCTVBackGround()->CCTVON();
			
			}
			else
			{
				isCamOn = false;
				CCTVBackGrounds->CCTVOFF();
				//CCTVBackGround::GetCCTVBackGround()->CCTVOFF();
				//CCTVCam->SetActive(false);
			}
			StageCameraRender->SetActive(true);
			// 여기에 CCTV 배경을 넣을것이다. 
		}
	);

}
