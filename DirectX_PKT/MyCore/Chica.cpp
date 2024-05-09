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
	SetLevel(10); //50퍼 

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
	// 보니 위치 보내주고 
	int MoveNum = Animatronics::MoveChance(90);
	ChicaLocation PrevState = CurState;
	switch (CurState)
	{
	case ChicaLocation::ShowRoom:

		if (CurRoomInfo[1]->GetMonster() == nullptr)
		{
			CurState = ChicaLocation::HallDining;
			CurRoomInfo[1]->SetMonster(this);

		}
		break;
	case ChicaLocation::HallDining:


		CurState = ChicaLocation::RestRoom;
		CurRoomInfo[10]->SetMonster(this);
		//RestRoom


	case ChicaLocation::RestRoom:

		if (MoveNum == 0)
		{
			CurState = ChicaLocation::HallDining;
			CurRoomInfo[1]->SetMonster(this);
			//다시 돌아가는 방법

		}
		// 이걸 바로 하면 안됨
		else
		{
			CurState = ChicaLocation::Kitten;
			CurRoomInfo[9]->SetMonster(this);
			CurLocation = "EastHall";
		}
		break;
	case ChicaLocation::EastHall:

		// 애니메이션 재생후 끝날때 쯤에 
		if (MoveNum == 0)
		{
			CurState = ChicaLocation::RestRoom;
			CurRoomInfo[10]->SetMonster(this);
		}
		// 이걸 바로 하면 안됨
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
		// 이걸 바로 하면 안됨
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
		// 이걸 바로 하면 안됨
		else
		{
			CurState = ChicaLocation::EastHall;
			CurRoomInfo[5]->SetMonster(this);

		}


		break;
	case ChicaLocation::Lobby:
		//오른쪽으로 이동하는 느낌 
		if (LobbyBackGround->BlockChecker() == true)
		{
			//문이 닫혀있다면 
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
		// 만약에 안걸렸다면 넣어주고 걸렸으면 다른곳으로 보내주기	
		break;
	default:
		break;





		if (PrevState != CurState) {

		}


		//Map->find()
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
	//초기화ㅣ 해주는 것 
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
