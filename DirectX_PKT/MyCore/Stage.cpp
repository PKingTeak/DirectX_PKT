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
	//GetWorld()->SpawnActor<Arrow>("Arrow");
	GetWorld()->SpawnActor<CCTVBackGround>("CCTVBackGround");
	StageCam = GetWorld()->SpawnActor<StageCamera>("StageCam");

	CCTVPtr = CCTVBackGround::GetCCTVBackGround();


	{

		LeftBox = CreateWidget<UImage>(GetWorld(), "LeftBox");
		ArrowUi = CreateWidget<UImage>(GetWorld(), "ArrowUI");
		RightBox = CreateWidget<UImage>(GetWorld(), "RightBox");



		ArrowUi->SetSprite("Arrow.png");
		ArrowUi->SetAutoSize(1.0f, true);
		ArrowUi->AddToViewPort(2);
		ArrowUi->SetPosition({ -100,-320 });


		LeftBox->SetSprite("Arrow.png");
		LeftBox->SetScale(FVector{ 500,1000 });
		LeftBox->AddToViewPort(2);
		LeftBox->SetPosition({ -400,0 });

		RightBox->SetSprite("Arrow.png");
		RightBox->SetScale(FVector{ 500,1000 });
		RightBox->AddToViewPort(2);
		RightBox->SetPosition({ 440,0 });


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
			}

		);
		LeftBox->SetUnHover([=]()
			{
				CamLeftMove = false;
				Camera->SetActorTransform(Camera->GetActorTransform());
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

		//	ArrowUi->SetDown([=]()
		//		{
		//			//이건 버튼 누를때 사용 
		//			UEngineDebugMsgWindow::PushMsg("Down!!!");
		//		});


	}



}

void Stage::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


	if (true == CCTVPtr->GetCamMode())
	{
		CamMove = true;
		CameraMove(_DeltaTime);
	}

	if (false == StageCam->GetIsCameraOn())
	{
		//ResetCamPos();

	}
	DebugGUI();
	MainStageMove(_DeltaTime);
	//
	//마우스 위치에 따라서 카메라 움직이는거 구현 할듯


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
	//카메라 좌우로 움직이기 
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