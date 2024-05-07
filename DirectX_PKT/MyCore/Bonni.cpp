#include"PreCompile.h"
#include "Bonni.h"
#include"Stage.h"
#include"RoomManager.h"
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
	//StageLevel = dynamic_cast<Stage*>(GetWorld()->GetGameMode().get());
	SetLevel(10); //50�� 
	
	MainStage = dynamic_cast<Stage*>(GetWorld()->GetGameMode().get());
}


void Bonni::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
}




void Bonni::SetCurLocation()
{
	
	CurRoomInfo = MainStage->GetCamActor();
	// ���� ��ġ �����ְ� 
	int MoveNum = Animatronics::MoveChance(90);

	switch (CurState)
	{
	case BonniLocation::ShowRoom:

		CurRoomInfo[0]->SetMonster(nullptr);
		CurRoomInfo[0]->GetMonster();
		if (MoveNum == 0)
		{
			CurState = BonniLocation::BackStage;
			CurRoomInfo[8]->SetMonster(this);
			//  ���⿡�� �׳� ���� setMonster�ؼ� Room�� ���� �������ִ°��� ������ �ϴ�. 
			
			
		}
			// �̰� �ٷ� �ϸ� �ȵ�
		if(MoveNum != 0)
		{
		
			CurState = BonniLocation::HallDining;
			CurRoomInfo[1]->SetMonster(this);
			CurRoomInfo[1]->GetMonster();
		}

		break;
	case BonniLocation::HallDining:
		CurRoomInfo[1]->SetMonster(nullptr);
		CurRoomInfo[1]->SettingSpriteName(0);
		if (MoveNum == 0)
		{
			CurState = BonniLocation::BackStage;
			//CurRoomInfo[8]->SetMonster(this);
			CurLocation = "BackStage";
			//MainStage->GetCCTVBack()->ChangeCam("DiningArea_Bonnie1");
		}
		// �̰� �ٷ� �ϸ� �ȵ�
		else
		{
			CurState = BonniLocation::WestHall;
			CurRoomInfo[3]->SetMonster(this);
			CurLocation = "WestHall";
		}

		break;

	case BonniLocation::BackStage:
		CurRoomInfo[8]->SetMonster(nullptr);
		if (MoveNum == 0)
		{
			CurState = BonniLocation::HallDining;
			//CurRoomInfo[1]->SetMonster(this);
			CurLocation = "HallDining";
			//MainStage->GetCCTVBack()->ChangeCam("DiningArea_Bonnie1");
		}
		// �̰� �ٷ� �ϸ� �ȵ�
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
		// �̰� �ٷ� �ϸ� �ȵ�
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
		// �̰� �ٷ� �ϸ� �ȵ�
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
		// �̰� �ٷ� �ϸ� �ȵ�
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

std::string Bonni::GetCurLocationString()
{
	return CurLocation;
}
