#include"PreCompile.h"
#include "Bonni.h"
#include"Stage.h"
#include"RoomManager.h"
#include"Door.h"
#include"StageBackGroundClass.h"

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
	MainStage = dynamic_cast<Stage*>(GetWorld()->GetGameMode().get());
	CurRoomInfo = MainStage->GetCamActor();
	
	FindMonsterIndex();

	LobbyDoor = MainStage->GetStageDoor();
	LobbyBackGround = MainStage->GetLobbyBackGround();
	// ���� ��ġ �����ְ� 
	int MoveNum = Animatronics::MoveChance(90);

	switch (CurState)
	{
	case BonniLocation::ShowRoom:

		//CurRoomInfo[0]->SetMonster(nullptr);
		//CurRoomInfo[0]->GetMonster();
		if (MoveNum == 0)
		{
			CurState = BonniLocation::BackStage;
			CurRoomInfo[8]->SetMonster(this);
			//  ���⿡�� �׳� ���� setMonster�ؼ� Room�� ���� �������ִ°��� ������ �ϴ�. 
			
			
		}
			// �̰� �ٷ� �ϸ� �ȵ�
		if(MoveNum != 0)
		{
			if (CurRoomInfo[1]->GetMonster() != nullptr)
			{
				return;
			}
		
			CurState = BonniLocation::HallDining;
			CurRoomInfo[1]->SetMonster(this);
			CurRoomInfo[1]->GetMonster();
		}

		break;
	case BonniLocation::HallDining:

		if (MoveNum == 0)
		{
			CurState = BonniLocation::BackStage;
			CurRoomInfo[8]->SetMonster(this);
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
		
		if (MoveNum == 0)
		{
			if (CurRoomInfo[1]->GetMonster() != nullptr)
			{
				return;
			}
			CurState = BonniLocation::HallDining;

			CurRoomInfo[1]->SetMonster(this);
			CurLocation = "HallDining";
			
		}
		// �̰� �ٷ� �ϸ� �ȵ�
		else
		{
			CurState = BonniLocation::WestHall;
			CurRoomInfo[3]->SetMonster(this);
			CurLocation = "WestHall";
		}
		break;
	case BonniLocation::WestHall:
		

		if (MoveNum == 0)
		{
			CurState = BonniLocation::WestHallCorner;
			CurRoomInfo[4]->SetMonster(this);
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
			//�������� �κ� ������ 
			CurLocation = "Lobby";
		}
		// �̰� �ٷ� �ϸ� �ȵ�
		else
		{
			CurState = BonniLocation::WestHall;
			CurRoomInfo[3]->SetMonster(this);
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
			CurState = BonniLocation::WestHallCorner;
			CurRoomInfo[3]->SetMonster(this);
			CurLocation = "SupplyCloset";

		}


		break;
	case BonniLocation::Lobby:
 		
		if (LobbyBackGround->BlockChecker() == true)
		{
			//���� �����ִٸ� 
			if (MoveNum == 2)
			{
				CurRoomInfo[3]->SetMonster(this);
				return;
			}
			else if (MoveNum == 1)
			{
				CurRoomInfo[4]->SetMonster(this);
				return;
			}
			CurRoomInfo[7]->SetMonster(this);



		}
		
		LobbyBackGround->SetLobbyMonster(this);
		// ���࿡ �Ȱɷȴٸ� �־��ְ� �ɷ����� �ٸ������� �����ֱ�	
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



void Bonni::FindMonsterIndex()
{
	//�ʱ�ȭ�� ���ִ� �� 
	MainStage = dynamic_cast<Stage*>(GetWorld()->GetGameMode().get());
	CurRoomInfo = MainStage->GetCamActor();

	for (int i = 0; i < CurRoomInfo.size(); i++)
	{
		if (CurRoomInfo[i]->GetMonster() != nullptr)
		{
			CurRoomInfo[i]->SetMonster(nullptr);
			//�̹��� �ʱ�ȭ
		}
	}
	
}
