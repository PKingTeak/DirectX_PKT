#include "PreCompile.h"
#include "Stage.h"
#include<EngineCore/Camera.h>
#include<EngineCore/EngineDebugMsgWindow.h>
#include"StageBackGroundClass.h"
#include"Fan.h"
#include"MyCore.h"
#include"Mouse.h"
#include"StageCamera.h"
#include"CCTVBackGround.h"
#include <EngineCore/Image.h>
#include <EngineCore/Camera.h>
#include <EngineBase/EngineSerializer.h>
#include "FishEyes.h"
#include"Button.h"



Stage::Stage()
{
}

Stage::~Stage()
{
}


void Stage::BeginPlay()
{

	GetWorld()->GetMainCamera()->GetCameraTarget()->AddEffect<FishEyes>();
	Super::BeginPlay();
	Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<Fan>("Fan");
	GetWorld()->SpawnActor<StageBackGroundClass>("StageBackGroundClass");
	GetWorld()->SpawnActor<Mouse>("Mouse");
	GetWorld()->SpawnActor<CCTVBackGround>("CCTVBackGround");
	GetWorld()->SpawnActor<Button>("LeftButton");
	StageCam = GetWorld()->SpawnActor<StageCamera>("StageCam");


	CCTVPtr = CCTVBackGround::GetCCTVBackGround();


	{

		
		
		

		//stage UI
		ArrowUi = CreateWidget<UImage>(GetWorld(), "ArrowUI");
		ArrowUi->SetSprite("Arrow.png");
		ArrowUi->SetAutoSize(1.0f, true);
		ArrowUi->AddToViewPort(2);
		ArrowUi->SetPosition({ -100,-320 });

		LeftBox = CreateWidget<UImage>(GetWorld(), "LeftBox");
		LeftBox->SetSprite("Void.png");
		LeftBox->SetScale(FVector{ 500,1000 });
		LeftBox->AddToViewPort(2);
		LeftBox->SetPosition({ -400,0 });

		RightBox = CreateWidget<UImage>(GetWorld(), "RightBox");
		RightBox->SetSprite("Void.png");
		RightBox->SetScale(FVector{ 500,1000 });
		RightBox->AddToViewPort(2);
		RightBox->SetPosition({ 440,0 });


		// CCTV���� UI
		CCTVMap = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		CCTVMap->SetSprite("CCTVMap.png");
		CCTVMap->AddToViewPort(2);
		CCTVMap->SetAutoSize(1.0f, true);
		CCTVMap->SetPosition(FVector{ 400,-150 });
		
		

		CCTVCamUI.insert({ "Cam1A",CCTVCams[0] });
		CCTVCamUI.insert({ "Cam2A",CCTVCams[1] });
		CCTVCamUI.insert({ "Cam3A",CCTVCams[2] });

		CCTVCamUI["Cam1A"] = CreateWidget<UImage>(GetWorld(), "Cam1A");
		CCTVCamUI["Cam1A"]->SetSprite("Cam1A.png",0);
		CCTVCamUI["Cam1A"]->CreateAnimation("Cam1AAni","Cam1A.png",0.5f,true,0,1);
		
		CCTVCamUI["Cam1A"]->SetAutoSize(1.0f, true);
		CCTVCamUI["Cam1A"]->AddToViewPort(2);


		//CCTVCamUI["Cam1A"]->SetPosition(FVector{ 400,-150 });

		{

			ArrowUi->SetHover([=]()
				{

					CamMove = true;
					StageCam->ChangeAnimation();



				});

		}

		LeftBox->SetHover([=]()
			{
				//CamMove = true;
				CamLeftMove = true;
				//MouseCamInfo = leftbox
				
			}

		);
		LeftBox->SetUnHover([=]()
			{
				CamLeftMove = false;
				Camera->SetActorTransform(Camera->GetActorTransform());
			}

		);

		CCTVCamUI["Cam1A"]->SetDown([=]()
			{
				ClickCamUI("Cam1A");
				MouseCamInfo = GetName();
				//CCTVCamUI["Cam1A"]->ChangeAnimation("Cam1AAni");
			}
		);



		RightBox->SetHover([=]()
			{
				//CamMove = true;
				CameRightMove = true;
			}
		);

		RightBox->SetUnHover([=]()
			{
				CamMove = false;
				CameRightMove = false;
			}
		);

		//ClickCamUI();

		


		

	}



}

void Stage::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	float4 Mouse = GEngine->EngineWindow.GetScreenMousePos();


	if (true == CCTVPtr->GetCamMode())
	{
		CamMove = true;
		CameraMove(_DeltaTime);
		LeftBox->SetActive(false);
		RightBox->SetActive(false);
		CCTVMap->SetActive(true);
	}

	if (false == StageCam->GetIsCameraOn())
	{
		//ResetCamPos();
		LeftBox->SetActive(true);
		RightBox->SetActive(true);
		CCTVMap->SetActive(false);
	}
	DebugGUI();
	MainStageMove(_DeltaTime);
	//
	//���콺 ��ġ�� ���� ī�޶� �����̴°� ���� �ҵ�


}


void Stage::DebugGUI()
{
	{
		std::string Msg = std::format("MousePos : {}\n", GEngine->EngineWindow.GetScreenMousePos().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);

	}

	{
		std::string Msg = std::format("CamPos: {}\n", Camera->GetActorLocation().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}


}

void Stage::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void Stage::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

}

void Stage::CameraMove(float _DeltaTime)
{
	//CCTV�ö���� ���� �����̴� �Լ�
	//ī�޶� �¿�� �����̱� 
	if (true == CamMove)
	{

		if (Camera->GetActorLocation().X >= -160 && MoveEnd == false)
		{
			Camera->AddActorLocation(float4::Left * _DeltaTime * 100);
			if (Camera->GetActorLocation().X <= -160)
			{
				MoveEnd = true;
			}
		}

		else if (true == MoveEnd && Camera->GetActorLocation().X <= 160)
		{
			Camera->AddActorLocation(float4::Right * _DeltaTime * 100);
			if (Camera->GetActorLocation().X >= 160)
			{
				MoveEnd = false;

			}

		}



	}




}

void Stage::MainStageMove(float _DeltaTime)
{
	if (true == CamLeftMove || true == CameRightMove)
	{


		if (true == CamLeftMove && Camera->GetActorLocation().X >= -160)
		{
			Camera->AddActorLocation(float4::Left * _DeltaTime * 200);
		}
		else if (true == CameRightMove && Camera->GetActorLocation().X <= 160)
		{
			Camera->AddActorLocation(float4::Right * _DeltaTime * 200);
		}

	}
}


void Stage::ResetCamPos()
{
	Camera->SetActorLocation({ 0,0,-100 });
	CamMove = false;
	CamLeftMove = false;
}

void Stage::ClickCamUI(std::string _CamName)
{

	MouseCamInfo = _CamName;
	std::string UIName = MouseCamInfo.append("Ani");
	
	
	CCTVCamUI.find(_CamName)->second->ChangeAnimation(UIName);
}
