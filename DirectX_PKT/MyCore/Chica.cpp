#include"PreCompile.h"
#include "Chica.h"
#include"Stage.h"
#include"RoomManager.h"
#include"Door.h"
#include"StageBackGroundClass.h"

Chica::Chica()
{
}

Chica::~Chica()
{
}

void Chica::BeginPlay()
{
	Super::BeginPlay();
	SetLevel(10); //50�� 

	MainStage = dynamic_cast<Stage*>(GetWorld()->GetGameMode().get());
}


void Chica::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}




void Chica::SetCurLocation()
{
	MainStage = dynamic_cast<Stage*>(GetWorld()->GetGameMode().get());
	CurRoomInfo = MainStage->GetCamActor();

	FindMonsterIndex();

	LobbyDoor = MainStage->GetStageDoor();
	LobbyBackGround = MainStage->GetLobbyBackGround();
	// ���� ��ġ �����ְ� 
	int MoveNum = Animatronics::MoveChance(90);


	switch (CurState)
	{
	case ChicaLocation::ShowRoom:
	
	{
		MainStage = dynamic_cast<Stage*>(GetWorld()->GetGameMode().get());
		CurRoomInfo = MainStage->GetCamActor();

		Animatronics* CurMonster = CurRoomInfo[1]->GetMonster();
	

	if (CurRoomInfo[1]->GetMonster() != nullptr)
	{
		break;
	}


	if (CurRoomInfo[1]->GetMonster() == nullptr)
	{
		CurState = ChicaLocation::HallDining;
		CurRoomInfo[1]->SetMonster(this);
		break;

	}
	}
	break;


	case ChicaLocation::HallDining:
	{
		CurState = ChicaLocation::RestRoom;
		CurRoomInfo[10]->SetMonster(this);
		//RestRoom

		break;
	}
	case ChicaLocation::RestRoom:

		if (MoveNum == 0)
		{
			CurState = ChicaLocation::HallDining;
			CurRoomInfo[1]->SetMonster(this);
			//�ٽ� ���ư��� ���

		}
		// �̰� �ٷ� �ϸ� �ȵ�
		else
		{
			CurState = ChicaLocation::Kitten;
			CurRoomInfo[9]->SetMonster(this);
		}

		break;
	case ChicaLocation::EastHall:

		// �ִϸ��̼� ����� ������ �뿡 
		if (MoveNum == 0)
		{
			CurState = ChicaLocation::RestRoom;
			CurRoomInfo[10]->SetMonster(this);
		}
		// �̰� �ٷ� �ϸ� �ȵ�
		else
		{
			CurState = ChicaLocation::EastHallCorner;
			CurRoomInfo[6]->SetMonster(this);

		}
		break;
	case ChicaLocation::EastHallCorner:


		if (MoveNum == 0)
		{
			CurState = ChicaLocation::Lobby;
		}
		// �̰� �ٷ� �ϸ� �ȵ�
		else
		{
			CurState = ChicaLocation::Kitten;
			CurRoomInfo[9]->SetMonster(this);
			CurLocation = "Kitten";

		}
		break;
	case ChicaLocation::Kitten:

		if (MoveNum == 0)
		{
			CurState = ChicaLocation::RestRoom;
			CurRoomInfo[10]->SetMonster(this);
		}
		// �̰� �ٷ� �ϸ� �ȵ�
		else
		{
			CurState = ChicaLocation::EastHall;
			CurRoomInfo[5]->SetMonster(this);

		}


		break;
	case ChicaLocation::Lobby:
		//���������� �̵��ϴ� ���� 
		if (LobbyBackGround->BlockChecker() == true)
		{
			//���� �����ִٸ� 
			if (MoveNum == 2)
			{
				CurRoomInfo[9]->SetMonster(this);
				return;
			}
			else
			{
				CurRoomInfo[1]->SetMonster(this);
				return;
			}


		}
		LobbyBackGround->SetLobbyMonster(this);
		// ���࿡ �Ȱɷȴٸ� �־��ְ� �ɷ����� �ٸ������� �����ֱ�	
		break;
	default:
		break;
	}

}

ChicaLocation Chica::GetCurLocation()
{
	return CurState;
}


//std::string _CamName

void Chica::AutoMove(float _DeltaTime)
{

	TestTime += _DeltaTime;

	if (TestTime >= 5)
	{
		Ismove = ACTOpportunity(Level);
		if (Ismove == true)
		{
			SetCurLocation();


		}
		TimeCount = 0;
		PrevTime = TestTime;
		TestTime = TestTime - PrevTime;
	}



}

std::string Chica::GetCurLocationString()
{
	return CurLocation;
}



void Chica::FindMonsterIndex()
{
	//�ʱ�ȭ�� ���ִ� �� 
	MainStage = dynamic_cast<Stage*>(GetWorld()->GetGameMode().get());
	CurRoomInfo = MainStage->GetCamActor();

	for (int i = 0; i < CurRoomInfo.size(); i++)
	{
		if (CurRoomInfo[i]->GetMonster() != nullptr)
		{
			CurRoomInfo[i]->SetMonster(nullptr);
		}
	}

}
