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
	//ȿ��
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


	}//����[i]  =GetWorld()->SpawnActor<>();


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


		// CCTV���� UI
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

				//Cam6 �� ���� ���� ȭ�鸸 ���̰� ������ ���� 
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
		//	//Map�� insert �ؼ� �� ����
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
						StageCam->CamCCTVOn(); //���⼭ ���ǹ��� �ɾ on��off�� �����ؾߵɵ� �ϴ� .
						
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

					//ī�޶� on �϶� CamMode�� true�� ���� ���������Ѵ�. 
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




		//�κ񿡼� ī�޶� �¿�� �����ϼ� �ְ� �ϱ� ����
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
	//�κ� ȭ�� ������
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
	//ī�޶� ��ġ �ʱ�ȭ
	Camera->SetActorLocation({ 0,0,-100 });
	CamMove = false;
	CamLeftMove = false;
}

void Stage::ClickCamUI(std::string _CamName)
{
	//���콺�� �������� UI ī�޶� �̸�  Ȯ�� 
	//���� �Ÿ��� �Լ�
	CurCamInfo = _CamName; //����
	CCTVUIGreenCheck(_CamName);


}

void Stage::ChageCam()
{
	if (PrevCam == nullptr)
	{
		return;
		//���� ī�޶� ������ �Լ� ���� 
	}

	std::string CamName = PrevCam->GetName();
	int num = FindIndex(CamName);
	//CCTVPtr->SetCamBackInfo(RoomActor[num].get());
	//	if (LocationName == CamName)
	//	{
	//		RoomActor[num]->SetMonter();
	//		ChageCam(); //ī�޶� ����
		//}
		//���� äũ
	//CCTVPtr->ChangeCam(CamName);
	CCTVPtr->ChangeCam(RoomActor[num].get());

	IsCamOn = false; //�ٸ� ī�޶� �Է¹����� �ְ� �ʱ�ȭ ����

}

//void Stage::CamInteract()
//{
//
//	for (std::string NameFirst : Name)
//	{
//		UImage* NewImage = CCTVCamUI[NameFirst]; // ���⼭ for������ ���鼭 ã���ִ°�
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
//						PrevCam = CCTVCamUI[NameFirst]; //������ ������ ������ ķ�� �ٲ��ִ� ���� ������ �ϴ�. 
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
//						ChageCam(); //ī�޶� ����
//					}
//
//
//					//ķȭ�� ��ȯ
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
			{// �������� ȭ�� �����ֱ� 


				CurCCTVCamUI = RoomCameraUI[i]; // ���� ī�޶� ���� UI
				CurCCTVCamActor = RoomActor[i].get(); // ���� ī�޶� ���� ���� 
				CCTVPtr->SetCamBackInfo(CurCCTVCamActor, true); //��濡 ī�޶� ������ ��
				if (IsCamOn == false)
				{

					if (PreCamName != CurCamName)
					{


						PrevCam = RoomCameraUI[i]; //������ ������ ������ ķ�� �ٲ��ִ� ���� ������ �ϴ�. 
						ClickCamUI(RoomCameraUI[i]->GetName());
						ChageCam();
						PreCCTVCamUIActor->SetActive(false);
					//	CurCCTVCamActor->SetActive(true);
					std::string ImageName =	CurCCTVCamActor->GetName();
						//CCTVPtr->ChangeSprite(ImageName);
						IsCamOn = true;
					}
					CCTVPtr->ScanLineON(); // ȭ�� ��ȯ�Ҷ� ������ �Ÿ��� ȿ�� 
					if (LocationName == CurCCTVCamUI->GetName())
					{

						CCTVPtr->SetCamBackInfo(CurCCTVCamActor, true);
						// ���ο��� �ڵ����� ó���Ҳ��� ������ �׳� ȭ�� ��ȯ�� �ϴ°ɷ� �ٲ��ֱ�


					}



					//ķȭ�� ��ȯ

				}
				IsCamOn = false;
				PreCCTVCamUIActor = CurCCTVCamActor;
				PreCCTVCamUI = CurCCTVCamUI; // ���� ī�޶� ���� ī�޶� �����ϰ� �Լ� ���� 

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
	//�̰� ���ڷ� �޾Ƽ� ����ҰŴ�
	switch (CurLocation)
	{

	case 0:
		// ShowRoom
		if (BShowRoom->CheckRoom() == false) //�ȿ� ����
		{
			LocationName = "ShowRoom";
			BShowRoom->SetMonter(BonniActor.get()); //���� �־��ְ� �׷��� ���� �����ʹ� ���͸� ����Ű�� �ִ�
			BonniActor->GetCurLocationString(); // ���ϴ� �׷��� �ڽ��� ��ġ�� �˷��ش�. 
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
			//BHallDining ȭ�� �ٲٴ°�;
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



int Stage::FindIndex(std::string _Name)	//���Ϳ��� �̸� ã��
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
std::shared_ptr<RoomManager> Stage::FindActorIndex(Animatronics* _Monster)	//���Ϳ��� �̸� ã��
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
	//CPP ������ ���� �Ʒ� ������ ����
	return RoomActor;

}