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
	case BonniLocation::Cam1A:


		if (MoveNum == 0)
		{
			CurState = BonniLocation::Cam5;


			//MainStage->GetCCTVBack()->ChangeCam("DiningArea_Bonnie0");
		}
			// 이걸 바로 하면 안됨
		if(MoveNum != 0)
		{
		//	CurState = BonniLocation::Cam1B;

		}

		break;
	case BonniLocation::Cam1B:
		if (MoveNum == 0)
		{
			CurState = BonniLocation::Cam5;
			//MainStage->GetCCTVBack()->ChangeCam("DiningArea_Bonnie1");
		}
		// 이걸 바로 하면 안됨
		else
		{
			CurState = BonniLocation::Cam2A;

		}

		break;
	case BonniLocation::Cam5:
		if (MoveNum == 0)
		{
			CurState = BonniLocation::Cam1B;
			//MainStage->GetCCTVBack()->ChangeCam("DiningArea_Bonnie1");
		}
		// 이걸 바로 하면 안됨
		else
		{
			CurState = BonniLocation::Cam2A;

		}
		break;
	case BonniLocation::Cam2A:
		if (MoveNum == 0)
		{
			CurState = BonniLocation::Cam2B;
			
		}
		// 이걸 바로 하면 안됨
		else
		{
			CurState = BonniLocation::Lobby;


		}
		break;
	case BonniLocation::Cam3:
		if (MoveNum == 0)
		{
			CurState = BonniLocation::Lobby;

		}
		// 이걸 바로 하면 안됨
		else
		{
			CurState = BonniLocation::Cam2A;


		}
		break;
	case BonniLocation::Cam2B:

		if (MoveNum == 0)
		{
			CurState = BonniLocation::Lobby;

		}
		// 이걸 바로 하면 안됨
		else
		{
			CurState = BonniLocation::Cam3;


		}


		break;
	case BonniLocation::Lobby:

		isLobby = true;
		break;
	default:
		break;




		//Map = MainStage->GetCCTVMap();




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
