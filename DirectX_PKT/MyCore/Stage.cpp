#include "PreCompile.h"
#include "Stage.h"
#include <EngineCore/Image.h>
#include <EngineCore/Camera.h>
#include <EngineBase/EngineSerializer.h>
#include<EngineCore/Camera.h>
#include<EngineCore/EngineDebugMsgWindow.h>
#include"StageBackGroundClass.h"
#include"Fan.h"
#include"MyCore.h"
#include"Mouse.h"
#include"StageCamera.h"
#include"CCTVBackGround.h"
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
#include"Animatronics.h"
#include"RoomManager.h"
#include"WestHall.h"
#include"WestHallCorner.h"
#include"SupplyCloset.h"
#include"BackStage.h"
#include"EastHall.h"
#include"EastHallCorner.h"
#include"KittenRoom.h"
#include"RestRoom.h"







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


	//���Ϳ� �ִ� ������ ������Ʈ �ַ��Ž���� �������� �־���. 
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
	
	
	BWestHallCorner = GetWorld()->SpawnActor<WestHallCorner>("CBWestHallCorner");
	RoomActor.push_back(BWestHallCorner);
	RoomCameraUI.push_back(BWestHallCorner->GetUI());

	BEastHall = GetWorld()->SpawnActor<EastHall>("CBEastHall");
	RoomActor.push_back(BEastHall);
	RoomCameraUI.push_back(BEastHall->GetUI());

	BEastHallCorner = GetWorld()->SpawnActor<EastHallCorner>("CBEastHallCorner");
	RoomActor.push_back(BEastHallCorner);
	RoomCameraUI.push_back(BEastHallCorner->GetUI());

	BSupplyCloset = GetWorld()->SpawnActor<SupplyCloset>("CBSupplyCloset");
	RoomActor.push_back(BSupplyCloset);
	RoomCameraUI.push_back(BSupplyCloset->GetUI());


	BBackStage = GetWorld()->SpawnActor<BackStage>("CBBackStage");
	RoomActor.push_back(BBackStage);
	RoomCameraUI.push_back(BBackStage->GetUI());


	BKittenRoom = GetWorld()->SpawnActor<KittenRoom>("CBKitten");
	RoomActor.push_back(BKittenRoom);
	RoomCameraUI.push_back(BKittenRoom->GetUI());

	BRestRoom = GetWorld()->SpawnActor<RestRoom>("CBRestRoom");
	RoomActor.push_back(BRestRoom);
	RoomCameraUI.push_back(BRestRoom->GetUI());
	



	


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
		//
		//
		//
		//
		//
		//
		//
		//
		
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
						StageCam->CamCCTVOn(); 
						

					}

					else if (CCTVonoff == true)
					{
						StageCam->CamCCTVOff();
						
						return;
					}

					//ī�޶� on �϶� CamMode�� true�� ���� ���������Ѵ�. 
				

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
	for (int i = 0; i < RoomActor.size(); i++)
	{
		RoomActor[i]->MapUpdate();
	}
	BonniActor->AutoMove(_DeltaTime);
	
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
	
	CCTVPtr->ChangeCam(RoomActor[num].get());

	IsCamOn = false; //�ٸ� ī�޶� �Է¹����� �ְ� �ʱ�ȭ ����

}

void Stage::CamInteract()
{

	for (int i = 0; i < RoomCameraUI.size(); i++)
		//tick���� �ȵ��Ƽ� 
	{


		std::string CurCamName = RoomCameraUI[i]->GetName();
		UImage* NewImage = RoomCameraUI[i];
		
		if (PrevCam == nullptr) // ���� ī�޶� nullptr�ϰ��
		{
			PrevCam = NewImage; //
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
		
		NewImage->SetDown([=]()
			{// �������� ȭ�� �����ֱ� 


				CurCCTVCamUI = RoomCameraUI[i]; // ���� ī�޶� ���� UI
				CurCCTVCamActor = RoomActor[i].get(); // ���� ī�޶� ���� ���� 
				CCTVPtr->SetCamBackInfo(CurCCTVCamActor, true); //��濡 ī�޶� ������ ��
				if (IsCamOn == false)
				{

					//if (PreCamName != CurCamName)
					//{


						PrevCam = RoomCameraUI[i]; //������ ������ ������ ķ�� �ٲ��ִ� ���� ������ �ϴ�. 
						ClickCamUI(RoomCameraUI[i]->GetName());
						ChageCam();
						PreCCTVCamUIActor->SetActive(false);
					//	CurCCTVCamActor->SetActive(true);
					std::string ImageName =	CurCCTVCamActor->GetName();
						//CCTVPtr->ChangeSprite(ImageName);
						IsCamOn = true;
				//	}
					CCTVPtr->ScanLineON(); // ȭ�� ��ȯ�Ҷ� ������ �Ÿ��� ȿ�� 
					if (LocationName == CurCCTVCamUI->GetName())
					{

						CCTVPtr->SetCamBackInfo(CurCCTVCamActor, true);
						// ���ο��� �ڵ����� ó���Ҳ��� ������ �׳� ȭ�� ��ȯ�� �ϴ°ɷ� �ٲ��ֱ�


					}

					IsCamOn = false;
					PreCCTVCamUIActor = CurCCTVCamActor;
					PreCCTVCamUI = CurCCTVCamUI; // ���� ī�޶� ���� ī�޶� �����ϰ� �Լ� ���� 


					//ķȭ�� ��ȯ

				}
				
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







std::shared_ptr<CCTVBackGround> Stage::GetCCTVBack()
{
	return CCTVPtr;
}

std::shared_ptr<StageNoise> Stage::GetNoise()
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

std::shared_ptr<Lobby> Stage::GetStageLobbyUI()
{
	return LobbyUI;
}