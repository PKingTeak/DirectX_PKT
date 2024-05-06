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
#include"CCTVUI.h"
#include"Noise.h"
#include"Door.h"
#include"Lobby.h"
#include"Bonni.h"
#include"RoomManager.h"
#include"ShowRoom.h"
#include"HallDining.h"
#include"PirateRoom.h"
#include"BackStage.h"
#include"Animatronics.h"
#include"RoomManager.h"
#include"WestHall.h"
#include"WestHallCorner.h"







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
	LobbyFan = GetWorld()->SpawnActor<Fan>("Fan");
	LobbyBackGround = GetWorld()->SpawnActor<StageBackGroundClass>("StageBackGroundClass");
	GetWorld()->SpawnActor<Mouse>("Mouse");
	CCTVPtr = GetWorld()->SpawnActor<CCTVBackGround>("CCTVBackGround");
	DoorControlButton = GetWorld()->SpawnActor<Button>("DoorControlButton");




	NoiseEffect = GetWorld()->SpawnActor<Noise>("NoiseEffect");
	NoiseEffect->SetActive(false);
	//NoiseEffect->SetOrder(100);

	StageCam = GetWorld()->SpawnActor<StageCamera>("StageCam");
	CCTVRectUI = GetWorld()->SpawnActor<CCTVUI>("CCTVRectUI");
	CCTVRectUI->SetActive(false);



	//LobbyUI
	LobbyUI = GetWorld()->SpawnActor<Lobby>("LobbyUI");
	StageDoor = GetWorld()->SpawnActor<Door>("StageDoor");

	//Monster
	BonniActor = GetWorld()->SpawnActor<Bonni>("Bonni");

	{//BackGround


	}//벡터[i]  =GetWorld()->SpawnActor<>();


	BShowRoom = GetWorld()->SpawnActor<ShowRoom>("CBShowRoom");
	
	RoomActor.push_back(BShowRoom);
	RoomCameraUI.push_back(BShowRoom->GetUI());

	BHallDining = GetWorld()->SpawnActor<HallDining>("CBHallDining"); 
	
	RoomActor.push_back(BHallDining);
	RoomCameraUI.push_back(BHallDining->GetUI());

	BPirateRoom = GetWorld()->SpawnActor<PirateRoom>("CBPirateRoom");
	RoomActor.push_back(BPirateRoom);
	RoomCameraUI.push_back(BPirateRoom->GetUI());

	BWestHall = GetWorld()->SpawnActor<WestHall>("CBWestHall");
	RoomActor.push_back(BWestHall);
	RoomCameraUI.push_back(BWestHall->GetUI());


	RoomActor[1]->SetActive(false);
	//BBackStage = GetWorld()->SpawnActor<BackStage>("CBackStage");
	//RoomActor.push_back(BBackStage);
	//RoomCameraUI.push_back(BBackStage->GetUI());



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


		UImage* NewCam = BShowRoom->GetUI();
		std::string Roomname = NewCam->GetName();

		NewCam = BHallDining->GetUI();
		std::string RoomNameTest = NewCam->GetName();

		//CCTVCamUI["Cam1A"] = CreateWidget<UImage>(GetWorld(), "ShowRoom");
		//CCTVCamUI["Cam1A"]->CreateAnimation("Cam1AAni", "Cam1A.png", 0.5f, true, 0, 0);
		//CCTVCamUI["Cam1A"]->CreateAnimation("CCam1AAni", "Cam1A.png", 0.5f, true, 0, 1);
		//CCTVCamUI["Cam1A"]->ChangeAnimation("CCam1AAni");
		//CCTVCamUI["Cam1A"]->SetPosition(FVector{ 370,0 });
		//CCTVCamUI["Cam1A"]->SetAutoSize(1.0f, true);
		//CCTVCamUI["Cam1A"]->AddToViewPort(2);
		//PrevCam = CCTVCamUI["Cam1A"];











		//CCTVCamUI["Cam5"] = CreateWidget<UImage>(GetWorld(), "BackStage");
		//CCTVCamUI["Cam5"]->SetSprite("Cam5.png", 0);
		//CCTVCamUI["Cam5"]->CreateAnimation("Cam5Ani", "Cam5.png", 0.5f, true, 0, 0);
		//CCTVCamUI["Cam5"]->CreateAnimation("CCam5Ani", "Cam5.png", 0.5f, true, 0, 1);
		//CCTVCamUI["Cam5"]->SetPosition(FVector{ 300,-50 });
		//CCTVCamUI["Cam5"]->SetAutoSize(1.0f, true);
		//CCTVCamUI["Cam5"]->AddToViewPort(2);
		//
		//	CCTVCamUI["Cam7"] = CreateWidget<UImage>(GetWorld(), "RestRoom");
		//CCTVCamUI["Cam7"]->SetSprite("Cam7.png", 0);
		//CCTVCamUI["Cam7"]->CreateAnimation("Cam7Ani", "Cam7.png", 0.5f, true, 0, 0);
		//CCTVCamUI["Cam7"]->CreateAnimation("CCam7Ani", "Cam7.png", 0.5f, true, 0, 1);
		//CCTVCamUI["Cam7"]->SetPosition(FVector{ 250,-50 });
		//CCTVCamUI["Cam7"]->SetAutoSize(1.0f, true);
		//CCTVCamUI["Cam7"]->AddToViewPort(2);
		//
		//	CCTVCamUI["Cam3"] = CreateWidget<UImage>(GetWorld(), "SupplyCloset");
		//CCTVCamUI["Cam3"]->SetSprite("Cam3.png", 0);
		//CCTVCamUI["Cam3"]->CreateAnimation("Cam3Ani", "Cam3.png", 0.5f, true, 0, 0);
		//CCTVCamUI["Cam3"]->CreateAnimation("CCam3Ani", "Cam3.png", 0.5f, true, 0, 1);
		//CCTVCamUI["Cam3"]->SetPosition(FVector{ 250,-250 });
		//CCTVCamUI["Cam3"]->SetAutoSize(1.0f, true);
		//CCTVCamUI["Cam3"]->AddToViewPort(2);

				//Cam6 은 거의 검은 화면만 보이게 구현할 예정 
		//CCTVCamUI["Cam6"] = CreateWidget<UImage>(GetWorld(), "KittenRoom");
		//CCTVCamUI["Cam6"]->SetSprite("Cam6.png", 0);
		//CCTVCamUI["Cam6"]->CreateAnimation("Cam6Ani", "Cam6.png", 0.5f, true, 0, 0);
		//CCTVCamUI["Cam6"]->CreateAnimation("CCam6Ani", "Cam6.png", 0.5f, true, 0, 1);
		//CCTVCamUI["Cam6"]->SetPosition(FVector{ 250,-50 });
		//CCTVCamUI["Cam6"]->SetAutoSize(1.0f, true);
		//CCTVCamUI["Cam6"]->AddToViewPort(2);
		//
		//
		//
		//
		//
		//
		//
		//
		//
		//	CCTVCamUI["Cam2B"] = CreateWidget<UImage>(GetWorld(), "W.HallConer");
		//CCTVCamUI["Cam2B"]->SetSprite("Cam2B.png", 0);
		//CCTVCamUI["Cam2B"]->CreateAnimation("Cam2BAni", "Cam2B.png", 0.5f, true, 0, 0);
		//CCTVCamUI["Cam2B"]->CreateAnimation("CCam2BAni", "Cam2B.png", 0.5f, true, 0, 1);
		//CCTVCamUI["Cam2B"]->SetPosition(FVector{ 320,-280 });
		//CCTVCamUI["Cam2B"]->SetAutoSize(1.0f, true);
		//CCTVCamUI["Cam2B"]->AddToViewPort(2);
		//
		//	CCTVCamUI["Cam4A"] = CreateWidget<UImage>(GetWorld(), "EestHall");
		//CCTVCamUI["Cam4A"]->SetSprite("Cam4A.png", 0);
		//CCTVCamUI["Cam4A"]->CreateAnimation("Cam4AAni", "Cam4A.png", 0.5f, true, 0, 0);
		//CCTVCamUI["Cam4A"]->CreateAnimation("CCam4AAni", "Cam4A.png", 0.5f, true, 0, 1);
		//CCTVCamUI["Cam4A"]->SetPosition(FVector{ 400,-100 });
		//CCTVCamUI["Cam4A"]->SetAutoSize(1.0f, true);
		//CCTVCamUI["Cam4A"]->AddToViewPort(2);
		//
		//	CCTVCamUI["Cam4B"] = CreateWidget<UImage>(GetWorld(), "E.HallConer");
		//CCTVCamUI["Cam4B"]->SetSprite("Cam4B.png", 0);
		//CCTVCamUI["Cam4B"]->CreateAnimation("Cam4BAni", "Cam4B.png", 0.5f, true, 0, 0);
		//CCTVCamUI["Cam4B"]->CreateAnimation("CCam4BAni", "Cam4B.png", 0.5f, true, 0, 1);
		//CCTVCamUI["Cam4B"]->SetPosition(FVector{ 400,-150 });
		//CCTVCamUI["Cam4B"]->SetAutoSize(1.0f, true);
		//CCTVCamUI["Cam4B"]->AddToViewPort(2);
		//
		//	//Map에 insert 해서 값 보관
		//CCTVCamUI.insert({ "Cam1A",CCTVCams[0] });
		//CCTVCamUI.insert({ "Cam2A",CCTVCams[1] });
		//CCTVCamUI.insert({ "Cam3",CCTVCams[2] }); // supply
		//CCTVCamUI.insert({ "Cam1C",CCTVCams[3] });
		//CCTVCamUI.insert({ "Cam5",CCTVCams[4] });
		//CCTVCamUI.insert({ "Cam6",CCTVCams[5] });
		//CCTVCamUI.insert({ "Cam7",CCTVCams[6] });
		//CCTVCamUI.insert({ "Cam2A",CCTVCams[7] });
		//CCTVCamUI.insert({ "Cam2B",CCTVCams[8] });
		//CCTVCamUI.insert({ "Cam4A",CCTVCams[9] });
		//CCTVCamUI.insert({ "Cam4B",CCTVCams[10] });
		//
		{

			ArrowUi->SetHover([=]()
				{
					bool CCTVonoff = StageCam->GetIsCameraOn();
					CamMove = true;


					if (CCTVonoff == false)
					{
						StageCam->CamCCTVOn(); //여기서 조건문을 걸어서 on과off를 구별해야될듯 하다 .
						
						//for (int i = 0; i < RoomActor.size(); i++)
						//{
						//	RoomActor[i]->SetActive(true);
						//}
					}

					else if (CCTVonoff == true)
					{
						StageCam->CamCCTVOff();
					
					
						//for (int i = 0; i < RoomActor.size(); i++)
						//{
						//	RoomActor[i]->SetActive(false);
						//}
						return;
					}

					//카메라가 on 일때 CamMode가 true일 때는 내려가야한다. 
					NoiseCheck();

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




		//로비에서 카메라가 좌우로 움직일수 있게 하기 위함
		RightBox->SetHover([=]()
			{
				CamMove = true;
				CameRightMove = true;
			}
		);

		RightBox->SetUnHover([=]()
			{

				CamMove = false;
				CameRightMove = false;

			}
		);

		
		CamInteract();
	




	}



}

void Stage::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	BonniActor->AutoMove(_DeltaTime);

	FindActorIndex(BonniActor.get());

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

	TestTimer += _DeltaTime;

	BonniActor->AutoMove(_DeltaTime);
	//FindAnimatronicsLocation();
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
	{
		//std::string Msg = std::format("BonniLocation : {}\n", LocationName);
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
	//깜빡 거리는 함수
	CurCamInfo = _CamName; //들어간다
	CCTVUIGreenCheck(_CamName);


}

void Stage::ChageCam()
{
	if (PrevCam == nullptr)
	{
		return;
		//이전 카메라가 없을때 함수 종료 
	}

	std::string CamName = PrevCam->GetName();
	int num = FindIndex(CamName);
	//CCTVPtr->SetCamBackInfo(RoomActor[num].get());
	//	if (LocationName == CamName)
	//	{
	//		RoomActor[num]->SetMonter();
	//		ChageCam(); //카메라 변경
		//}
		//몬스터 채크
	//CCTVPtr->ChangeCam(CamName);
	CCTVPtr->ChangeCam(RoomActor[num].get());

	IsCamOn = false; //다른 카메라가 입력받을수 있게 초기화 해줌

}

//void Stage::CamInteract()
//{
//
//	for (std::string NameFirst : Name)
//	{
//		UImage* NewImage = CCTVCamUI[NameFirst]; // 여기서 for문으로 돌면서 찾아주는것
//		std::string CurCamName = NewImage->GetName();
//		std::string PreCamName = PrevCam->GetName();
//		std::string MonsterLocal = LocationName;
//
//		//if(NewImage->);
//		NewImage->SetDown([=]()
//			{
//				if (IsCamOn == false)
//				{
//					this;
//					if (PreCamName != CurCamName)
//					{
//
//						PrevCam = CCTVCamUI[NameFirst]; //이전껄 가지고 있을때 캠을 바꿔주는 것이 좋을듯 하다. 
//						ClickCamUI(NameFirst);
//						CCTVRectUI->SetActive(true);
//						IsCamOn = true;
//					}
//					CCTVPtr->ScanLineON();
//					if (MonsterLocal == CurCamName)
//					{
//
//						MonsterName = LocationName.append("Booni.png");
//						CCTVPtr->ChangeCam(MonsterName);
//
//
//					}
//					else if (MonsterLocal != CurCamName)
//					{
//						ChageCam(); //카메라 변경
//					}
//
//
//					//캠화면 전환
//
//				}
//
//			}
//		);
//	}
//
//
//
//
//}
//

void Stage::CamInteract()
{

	for (int i = 0; i < RoomCameraUI.size(); i++)

	{


		std::string CurCamName = RoomCameraUI[i]->GetName();
		UImage* NewImage = RoomCameraUI[i];

		if (PrevCam == nullptr)
		{
			PrevCam = NewImage;
			PrevCamInfo = PrevCam->GetName();

		}

		if (PreCCTVCamUI == nullptr)
		{
			PreCCTVCamUI = RoomCameraUI[0];
		}

		if (PreCCTVCamUIActor == nullptr)
		{
			PreCCTVCamUIActor = RoomActor[0].get();
		}
		//if(NewImage->);
		NewImage->SetDown([=]()
			{// 눌렀을때 화면 보여주기 


				CurCCTVCamUI = RoomCameraUI[i]; // 현재 카메라 저장 UI
				CurCCTVCamActor = RoomActor[i].get(); // 현재 카메라 정보 저장 
				CCTVPtr->SetCamBackInfo(CurCCTVCamActor, true); //배경에 카메라 정보가 들어감
				if (IsCamOn == false)
				{

					if (PreCamName != CurCamName)
					{


						PrevCam = RoomCameraUI[i]; //이전껄 가지고 있을때 캠을 바꿔주는 것이 좋을듯 하다. 
						ClickCamUI(RoomCameraUI[i]->GetName());
						ChageCam();
						PreCCTVCamUIActor->SetActive(false);
					//	CurCCTVCamActor->SetActive(true);
					std::string ImageName =	CurCCTVCamActor->GetName();
						//CCTVPtr->ChangeSprite(ImageName);
						IsCamOn = true;
					}
					CCTVPtr->ScanLineON(); // 화면 전환할때 지지직 거리는 효과 
					if (LocationName == CurCCTVCamUI->GetName())
					{

						CCTVPtr->SetCamBackInfo(CurCCTVCamActor, true);
						// 내부에서 자동으로 처리할꺼기 때문에 그냥 화면 전환만 하는걸로 바꿔주기


					}



					//캠화면 전환

				}
				IsCamOn = false;
				PreCCTVCamUIActor = CurCCTVCamActor;
				PreCCTVCamUI = CurCCTVCamUI; // 이전 카메라에 현재 카메라 저장하고 함수 종료 

			}
		);
	}
}



void Stage::CCTVUIGreenCheck(std::string _CamName)
{
	int num = FindIndex(_CamName);


	if (CurCCTVCamUI == nullptr)
	{
		CurCCTVCamUI = RoomActor[num]->GetUI();
		PreCCTVCamUI = RoomActor[0]->GetUI();
	}
	if (CurCCTVCamUI == PreCCTVCamUI)
	{
		return;
	}
	if (_CamName != PreCamName)
	{
		PreCCTVCamUI->ChangeAnimation(PreCCTVCamUI->GetName() + "Ani");
		std::string check = CurCCTVCamUI->GetName();
		CurCCTVCamUI = RoomActor[num]->GetUI();
		CurCCTVCamUI->ChangeAnimation("C" + CurCCTVCamUI->GetName() + "Ani");
		PreCCTVCamUI = CurCCTVCamUI;

	}

	

}



void Stage::NoiseCheck()
{
	CCTVChecker = StageCam->GetIsCameraOn();
	if (CCTVChecker == true)
	{
		NoiseEffect->SetActive(true);
	}

	if (CCTVChecker == false)
	{
		NoiseEffect->SetActive(false);
	}

}


std::string Stage::FindAnimatronicsLocation()
{
	int CurLocation = static_cast<int>(BonniActor->GetCurLocation());
	bool IsBoni = Bonni::isLobby;
	//이걸 인자로 받아서 사용할거다
	switch (CurLocation)
	{

	case 0:
		// ShowRoom
		if (BShowRoom->CheckRoom() == false) //안에 없다
		{
			LocationName = "ShowRoom";
			BShowRoom->SetMonter(BonniActor.get()); //몬스터 넣어주고 그러면 방의 포인터는 몬스터를 가르키고 있다
			BonniActor->GetCurLocationString(); // 보니는 그러면 자신의 위치를 알려준다. 
			return LocationName;
		}
		break;

	case 1:

		if (BHallDining->CheckRoom() == false)
		{
			BHallDining->SetMonter(BonniActor.get());
			BHallDining->ChangeRoomCamera(BonniActor.get());
			BHallDining->MapChangeSprite(BonniActor.get());
			LocationName = "HallDining";
			//BHallDining->SetActive(true);
			//BHallDining 화면 바꾸는것;
			return LocationName;

		}

	case 2:
		if (BBackStage->CheckRoom() == true)
		{
			LocationName = "DiningArea";

			return LocationName;
		}
		return LocationName;
	default:
		break;
	}
	return "0";
}

std::shared_ptr<CCTVBackGround> Stage::GetCCTVBack()
{
	return CCTVPtr;
}

std::shared_ptr<Noise> Stage::GetNoise()
{
	return NoiseEffect;
}

std::shared_ptr<Door> Stage::GetStageDoor()
{
	return StageDoor;
}

std::shared_ptr<StageBackGroundClass> Stage::GetLobbyBackGround()
{
	return LobbyBackGround;
}





std::shared_ptr<Bonni> Stage::GetStageBonni()
{
	return BonniActor;
}

std::vector<std::string> Stage::GetCamName()
{
	return Name;
}



int Stage::FindIndex(std::string _Name)	//벡터에서 이름 찾기
{

	int index = 0;
	for (int i = 0; i < RoomCameraUI.size(); i++)
	{
		std::string CheckName = RoomCameraUI[i]->GetName();
		if (_Name == CheckName)
		{
			index = i;

		}
	}

	return index;
}
std::shared_ptr<RoomManager> Stage::FindActorIndex(Animatronics* _Monster)	//벡터에서 이름 찾기
{

	int index = 0;
	for (int i = 0; i < RoomActor.size(); i++)
	{
		std::string CheckName = RoomActor[i]->GetName();
		if (LocationName == CheckName)
		{
			RoomActor[i]->SetMonter(_Monster);
			return RoomActor[i];
		}
	}
	return RoomActor[0];
}
std::vector<std::shared_ptr<RoomManager>> Stage::GetCamActor()
{
	//CPP 위에서 부터 아래 순으로 넣음
	return RoomActor;

}