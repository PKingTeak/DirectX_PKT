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
#include<vector>
#include"ScanLine.h"


bool Stage::IsCamOn = false;


Stage::Stage()
{
}

Stage::~Stage()
{
}


void Stage::BeginPlay()

{

	GetWorld()->GetMainCamera()->GetCameraTarget()->AddEffect<FishEyes>();
	//효과
	Super::BeginPlay();
	Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<Fan>("Fan");
	GetWorld()->SpawnActor<StageBackGroundClass>("StageBackGroundClass");
	GetWorld()->SpawnActor<Mouse>("Mouse");
	GetWorld()->SpawnActor<CCTVBackGround>("CCTVBackGround");
	GetWorld()->SpawnActor<Button>("LeftButton");
	StageCam = GetWorld()->SpawnActor<StageCamera>("StageCam");
	ScanLineUI = GetWorld()->SpawnActor<ScanLine>("ScanLineUI");


	
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


		// CCTV관련 UI
		CCTVMap = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		CCTVMap->SetSprite("CCTVMap.png");
		CCTVMap->AddToViewPort(2);
		CCTVMap->SetAutoSize(1.0f, true);
		CCTVMap->SetPosition(FVector{ 400,-150 });

		CCTVMap = CreateWidget<UImage>(GetWorld(), "CCTVMap");
		CCTVMap->SetSprite("CCTVMap.png");
		CCTVMap->AddToViewPort(2);
		CCTVMap->SetAutoSize(1.0f, true);
		CCTVMap->SetPosition(FVector{ 400,-150 });
		
		
		
		CCTVCamUI["Cam1A"] = CreateWidget<UImage>(GetWorld(), "ShowRoom");
		CCTVCamUI["Cam1A"]->SetSprite("Cam1A.png", 0);
		CCTVCamUI["Cam1A"]->CreateAnimation("Cam1AAni", "Cam1A.png", 0.5f, true, 0, 1);
		CCTVCamUI["Cam1A"]->SetPosition(FVector{ 370,0 });
		CCTVCamUI["Cam1A"]->SetAutoSize(1.0f, true);
		CCTVCamUI["Cam1A"]->AddToViewPort(2);
		PrevCam = CCTVCamUI["Cam1A"];

		CCTVCamUI["Cam1B"] = CreateWidget<UImage>(GetWorld(), "HallDining");
		CCTVCamUI["Cam1B"]->SetSprite("Cam1B.png", 0);
		CCTVCamUI["Cam1B"]->CreateAnimation("Cam1BAni", "Cam1B.png", 0.5f, true, 0, 1);
		CCTVCamUI["Cam1B"]->SetPosition(FVector{ 370,-50 });
		CCTVCamUI["Cam1B"]->SetAutoSize(1.0f, true);
		CCTVCamUI["Cam1B"]->AddToViewPort(2);

		CCTVCamUI["Cam1C"] = CreateWidget<UImage>(GetWorld(), "PirateRoom");
		CCTVCamUI["Cam1C"]->SetSprite("Cam1C.png", 0);
		CCTVCamUI["Cam1C"]->CreateAnimation("Cam1CAni", "Cam1C.png", 0.5f, true, 0, 1);
		CCTVCamUI["Cam1C"]->SetPosition(FVector{ 280,-100 });
		CCTVCamUI["Cam1C"]->SetAutoSize(1.0f, true);
		CCTVCamUI["Cam1C"]->AddToViewPort(2);

		CCTVCamUI["Cam5"] = CreateWidget<UImage>(GetWorld(), "BackStage");
		CCTVCamUI["Cam5"]->SetSprite("Cam5.png", 0);
		CCTVCamUI["Cam5"]->CreateAnimation("Cam5Ani", "Cam5.png", 0.5f, true, 0, 1);
		CCTVCamUI["Cam5"]->SetPosition(FVector{ 300,-50 });
		CCTVCamUI["Cam5"]->SetAutoSize(1.0f, true);
		CCTVCamUI["Cam5"]->AddToViewPort(2);

		CCTVCamUI["Cam7"] = CreateWidget<UImage>(GetWorld(), "RestRoom");
		CCTVCamUI["Cam7"]->SetSprite("Cam7.png", 0);
		CCTVCamUI["Cam7"]->CreateAnimation("Cam7Ani", "Cam7.png", 0.5f, true, 0, 1);
		CCTVCamUI["Cam7"]->SetPosition(FVector{ 250,-50 });
		CCTVCamUI["Cam7"]->SetAutoSize(1.0f, true);
		CCTVCamUI["Cam7"]->AddToViewPort(2);

		CCTVCamUI["Cam3"] = CreateWidget<UImage>(GetWorld(), "SupplyCloset");
		CCTVCamUI["Cam3"]->SetSprite("Cam3.png", 0);
		CCTVCamUI["Cam3"]->CreateAnimation("Cam3Ani", "Cam3.png", 0.5f, true, 0, 1);
		CCTVCamUI["Cam3"]->SetPosition(FVector{ 250,-250 });
		CCTVCamUI["Cam3"]->SetAutoSize(1.0f, true);
		CCTVCamUI["Cam3"]->AddToViewPort(2);

		//Cam6 은 거의 검은 화면만 보이게 구현할 예정 
		CCTVCamUI["Cam6"] = CreateWidget<UImage>(GetWorld(), "KittenRoom");
		CCTVCamUI["Cam6"]->SetSprite("Cam6.png", 0);
		CCTVCamUI["Cam6"]->CreateAnimation("Cam6Ani", "Cam6.png", 0.5f, true, 0, 1);
		CCTVCamUI["Cam6"]->SetPosition(FVector{ 250,-50 });
		CCTVCamUI["Cam6"]->SetAutoSize(1.0f, true);
		CCTVCamUI["Cam6"]->AddToViewPort(2);

		CCTVCamUI["Cam2A"] = CreateWidget<UImage>(GetWorld(), "WestHall");
		CCTVCamUI["Cam2A"]->SetSprite("Cam2A.png", 0);
		CCTVCamUI["Cam2A"]->CreateAnimation("Cam2AAni", "Cam2A.png", 0.5f, true, 0, 1);
		CCTVCamUI["Cam2A"]->SetPosition(FVector{ 250,-50 });
		CCTVCamUI["Cam2A"]->SetAutoSize(1.0f, true);
		CCTVCamUI["Cam2A"]->AddToViewPort(2);

		CCTVCamUI["Cam2B"] = CreateWidget<UImage>(GetWorld(), "W.HallConer");
		CCTVCamUI["Cam2B"]->SetSprite("Cam2B.png", 0);
		CCTVCamUI["Cam2B"]->CreateAnimation("Cam2BAni", "Cam2B.png", 0.5f, true, 0, 1);
		CCTVCamUI["Cam2B"]->SetPosition(FVector{ 250,-50 });
		CCTVCamUI["Cam2B"]->SetAutoSize(1.0f, true);
		CCTVCamUI["Cam2B"]->AddToViewPort(2);

		CCTVCamUI["Cam4A"] = CreateWidget<UImage>(GetWorld(), "EestHall");
		CCTVCamUI["Cam4A"]->SetSprite("Cam4A.png", 0);
		CCTVCamUI["Cam4A"]->CreateAnimation("Cam4AAni", "Cam4A.png", 0.5f, true, 0, 1);
		CCTVCamUI["Cam4A"]->SetPosition(FVector{ 400,-100 });
		CCTVCamUI["Cam4A"]->SetAutoSize(1.0f, true);
		CCTVCamUI["Cam4A"]->AddToViewPort(2);

		CCTVCamUI["Cam4B"] = CreateWidget<UImage>(GetWorld(), "E.HallConer");
		CCTVCamUI["Cam4B"]->SetSprite("Cam4B.png", 0);
		CCTVCamUI["Cam4B"]->CreateAnimation("Cam4BAni", "Cam4B.png", 0.5f, true, 0, 1);
		CCTVCamUI["Cam4B"]->SetPosition(FVector{ 400,-150 });
		CCTVCamUI["Cam4B"]->SetAutoSize(1.0f, true);
		CCTVCamUI["Cam4B"]->AddToViewPort(2);

		//Map에 insert 해서 값 보관
		CCTVCamUI.insert({ "Cam1A",CCTVCams[0] });
		CCTVCamUI.insert({ "Cam2A",CCTVCams[1] });
		CCTVCamUI.insert({ "Cam3",CCTVCams[2] }); // supply
		CCTVCamUI.insert({ "Cam1C",CCTVCams[3] });
		CCTVCamUI.insert({ "Cam5",CCTVCams[4] });
		CCTVCamUI.insert({ "Cam6",CCTVCams[5] });
		CCTVCamUI.insert({ "Cam7",CCTVCams[6] });
		CCTVCamUI.insert({ "Cam2A",CCTVCams[7] });
		CCTVCamUI.insert({ "Cam2B",CCTVCams[8] });
		CCTVCamUI.insert({ "Cam4A",CCTVCams[9] });
		CCTVCamUI.insert({ "Cam4B",CCTVCams[10] });
		//CCTVCamUI.insert({ "Cam2B",CCTVCams[11] });

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


		CamInteract();

		//로비에서 카메라가 좌우로 움직일수 있게 하기 위함
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


	if (UEngineInput::IsDown(VK_LBUTTON))
	{
		CamInteract();
	}

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
	//CCTV올라오고 난후 움직이는 함수
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
	//로비 화면 움직임
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
	//카메라 위치 초기화
	Camera->SetActorLocation({ 0,0,-100 });
	CamMove = false;
	CamLeftMove = false;
}

void Stage::ClickCamUI(std::string _CamName)
{
	//마우스로 눌렀을때 UI 카메라 이름  확인
	MouseCamInfo = _CamName;
	
	
	std::string UIName = MouseCamInfo.append("Ani");
	CCTVCamUI.find(_CamName)->second->ChangeAnimation(UIName);
	CCTVUIGreenCheck(_CamName);
	PrevMouseCamInfo = _CamName;
	//해당 UI는 애니메이션을 바꿀꺼
}

void Stage::ChageCam()
{
	if (PrevCam == nullptr)
	{
		return;
	}
	std::string CamName = PrevCam->GetName();
	CCTVPtr->ChangeCam(CamName);
	//CCTVCamUI.find(CamName)->second->SetSprite(CamImage);
	IsCamOn = false; //다른 카메라가 입력받을수 있게 초기화 해줌

}

void Stage::CamInteract()
{
	
for (std::string NameFirst : Name)
{
	UImage* NewImage = CCTVCamUI[NameFirst];
	std::string CurCamName = NewImage->GetName();
	std::string PreCamName = PrevCam->GetName();


	NewImage->SetDown([=]()
		{
			if (IsCamOn == false)
			{

				if (PreCamName != CurCamName)
				{

					PrevCam = CCTVCamUI[NameFirst]; //이전껄 가지고 있을때 캠을 바꿔주는 것이 좋을듯 하다. 
					ClickCamUI(NameFirst);
					IsCamOn = true;
				}
				StartScanLine();
				ChageCam();

				//캠화면 전환
				
			}
			
		}

	);
}



	
}

void Stage::CCTVUIGreenCheck(std::string _CamName)
{

	std::string RestCamName = _CamName;
	RestCamName.append(".png");

	if (_CamName != PrevMouseCamInfo)
	{
	
		CCTVCamUI.find(_CamName)->second->SetSprite(RestCamName,0);
		CCTVCamUI.find(_CamName)->second->SetOrder(5);
	}


}

void Stage::StartScanLine()
{
	ScanLineUI->ScanLineLoad();
}
