#include "PreCompile.h"
#include "StageCamera.h"
#include<EngineCore/Collision.h>
#include"MyCore.h"
#include<EngineCore/DefaultSceneComponent.h>
#include"CCTVBackGround.h"
#include "Stage.h"
#include"Lobby.h"

StageCamera::StageCamera()
{
	StageCameraRender = CreateDefaultSubObject<USpriteRenderer>("StageCameraRender");
	StageCameraRender->SetAutoSize(1.0f, true);
	StageCameraRender->CreateAnimation("CameraAnimtaion", "StageCam.png", 0.05f, false ,0,11);
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
	//stageLevel���� ���� ������ ���͸� �����ͼ� ����ϴ� ��� 
	StageLevel = dynamic_cast<Stage*>(GetWorld()->GetGameMode().get());
	CCTVBackGrounds = StageLevel->GetCCTVBack();
	
	
	
	Super::BeginPlay();

}
void StageCamera::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	

}
void StageCamera::CamCCTVOn()
{
	LobbyUI = StageLevel->GetStageLobbyUI();

	StageCameraRender->SetActive(true);
	StageCameraRender->AnimationReset();
	StageCameraRender->ChangeAnimation("CameraAnimtaion");


	StageCameraRender->SetFrameCallback("CameraAnimtaion", 11, [&]
		{
			isCamOn = true;

			StageCameraRender->SetActive(false);
			LobbyUI->BatteryUserUP();
			CCTVBackGrounds->CCTVON();
			// ���⿡ CCTV ����� �������̴�. 
		}
	);
	bool Check = StageCameraRender->IsCurAnimationEnd();
	

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
			LobbyUI->BatteryUserDown(); // ���͸� ��뷮 ������
			StageCameraRender->SetActive(false);
			}

		});
	
}
