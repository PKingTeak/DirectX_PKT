#include"PreCompile.h"
#include "Bonni.h"
#include"Stage.h"

bool Bonni::isLobby = false;
Bonni::Bonni()
{
}

Bonni::~Bonni()
{
}

void Bonni::BeginPlay()
{
	Super::BeginPlay();
	SetLevel(10);
	

}


void Bonni::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
}




void Bonni::SetCurLocation()
{
	// 보니 위치 보내주고 
	int MoveNum = Animatronics::MoveChance(40);

	switch (CurState)
	{
	case BonniLocation::ShowRoom:


		if (MoveNum == 0)
		{
			CurState = BonniLocation::BackStage;
			
			//MainStage->GetCCTVBack()->ChangeCam("DiningArea_Bonnie0");
		}
			// 이걸 바로 하면 안됨
		if(MoveNum != 0)
		{
		//	CurState = BonniLocation::Cam1B;

		}

		break;
	case BonniLocation::HallDining:
		if (MoveNum == 0)
		{
			CurState = BonniLocation::BackStage;
			CurLocation = "BackStage";
			//MainStage->GetCCTVBack()->ChangeCam("DiningArea_Bonnie1");
		}
		// 이걸 바로 하면 안됨
		else
		{
			CurState = BonniLocation::WestHall;
			CurLocation = "WestHall";
		}

		break;
	case BonniLocation::BackStage:
		if (MoveNum == 0)
		{
			CurState = BonniLocation::HallDining;
			CurLocation = "HallDining";
			//MainStage->GetCCTVBack()->ChangeCam("DiningArea_Bonnie1");
		}
		// 이걸 바로 하면 안됨
		else
		{
			CurState = BonniLocation::WestHall;
			CurLocation = "WestHall";
		}
		break;
	case BonniLocation::WestHall:
		if (MoveNum == 0)
		{
			CurState = BonniLocation::WestHallCorner;
			CurLocation = "WestHallCorner";
		}
		// 이걸 바로 하면 안됨
		else
		{
			CurState = BonniLocation::Lobby;
			CurLocation = "Lobby";

		}
		break;
	case BonniLocation::WestHallCorner:
		if (MoveNum == 0)
		{
			CurState = BonniLocation::Lobby;
			CurLocation = "Lobby";
		}
		// 이걸 바로 하면 안됨
		else
		{
			CurState = BonniLocation::WestHall;
			CurLocation = "WestHall";

		}
		break;
	case BonniLocation::SupplyCloset:

		if (MoveNum == 0)
		{
			CurState = BonniLocation::Lobby;
			CurLocation = "Lobby";
		}
		// 이걸 바로 하면 안됨
		else
		{
			CurState = BonniLocation::SupplyCloset;
			CurLocation = "SupplyCloset";

		}


		break;
	case BonniLocation::Lobby:

		isLobby = true;
		break;
	default:
		break;




	



		//Map->find()
	}

}

BonniLocation Bonni::GetCurLocation()
{
	return CurState;
}


//std::string _CamName

void Bonni::AutoMove(float _DeltaTime)
{

	TestTime += _DeltaTime;
	if (TestTime > 5)
	{
		Ismove = ACTOpportunity(Level);
		if (Ismove == true)
		{
			SetCurLocation();
			TestTime = 0;
		}
	}

}

std::string Bonni::GetCurLocationString()
{
	return CurLocation;
}
