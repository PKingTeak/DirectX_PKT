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


Stage::Stage()
{
}

Stage::~Stage()
{
}


void Stage::BeginPlay()
{
	Super::BeginPlay();
	Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<Fan>("Fan");
	GetWorld()->SpawnActor<StageBackGroundClass>("StageBackGroundClass");
	GetWorld()->SpawnActor<Mouse>("Mouse");
	GetWorld()->SpawnActor<Arrow>("Arrow");
	GetWorld()->SpawnActor<CCTVBackGround>("CCTVBackGround");
	StageCam = GetWorld()->SpawnActor<StageCamera>("StageCam");

	CCTVPtr = CCTVBackGround::GetCCTVBackGround();

	{

		ArrowUi = CreateWidget<UImage>(GetWorld(), "Arrow");

		ArrowUi->AddToViewPort();
		ArrowUi->SetSprite("Arrow.png");
		ArrowUi->SetAutoSize(1.0f, true);
		ArrowUi->SetPosition({ 0,-320 });


		ArrowUi->SetHover([=]()
			{
				StageCam->ChangeAnimation();
			});

		ArrowUi->SetDown([=]()
			{
				UEngineDebugMsgWindow::PushMsg("Down!!!");
			});


	}
}

void Stage::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
	
	if (true == CCTVPtr->GetCamMode())
	{
		CameraMove(_DeltaTime);
	}
	DebugGUI();
	//DebugGUI();
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
	float CamMovepos = 0;
	CamMovepos += _DeltaTime;
	if (true == MoveEnd && Camera->GetActorLocation().X <= 160)
	{
		Camera->AddActorLocation(float4::Right * _DeltaTime * 100);
		if (Camera->GetActorLocation().X >= 160)
		{
			MoveEnd = false;
		}
		//MoveEnd == false;
	}
	if (Camera->GetActorLocation().X >= -160 && MoveEnd == false)
	{
	Camera->AddActorLocation(float4::Left * _DeltaTime * 100);
		if(Camera->GetActorLocation().X <= -160)
		{
			MoveEnd = true;
		}
	}
	
}
