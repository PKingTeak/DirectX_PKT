#include"PreCompile.h"
#include "Bonni.h"
#include"Stage.h"
Bonni::Bonni()
{
}

Bonni::~Bonni()
{
}

void Bonni::BeginPlay()
{
	Super::BeginPlay();
	MainStage = dynamic_cast<Stage*>(GetWorld()->GetGameMode().get()); // 스테이지 가져오고
	SetLevel(10);

}


void Bonni::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	TestTime += _DeltaTime;
	if (TestTime > 3)
	{
		Ismove = ACTOpportunity(Level);
		if (Ismove == true)
		{
			SetCurLocation();
		}
	}
}




BonniLocation Bonni::SetCurLocation()
{
	BonniLocation CurState = BonniLocation::Cam1A;

	int MoveNum = Animatronics::MoveChance(30);

	switch (CurState)
	{
	case BonniLocation::Cam1A:


		if (MoveNum == 0)
		{
			CurState = BonniLocation::Cam5;
			MainStage->GetCCTVBack()->ChangeCam("DiningArea_Bonnie0");
		}
			// 이걸 바로 하면 안됨
		else
		{
			CurState = BonniLocation::Cam1B;

		}

		break;
	case BonniLocation::Cam1B:
		break;
	case BonniLocation::Cam5:
		break;
	case BonniLocation::Cam2A:
		break;
	case BonniLocation::Cam3:
		break;
	case BonniLocation::Cam2B:
		break;
	case BonniLocation::Lobby:
		break;
	default:
		break;




		//Map = MainStage->GetCCTVMap();




		return CurState;
		//Map->find()
	}

}


//std::string _CamName