#include "PreCompile.h"
#include "Animatronics.h"
#include "CCTVBackGround.h"
#include "RoomManager.h"
#include "Stage.h"

std::vector<std::shared_ptr<RoomManager>> Animatronics::CurRoomInfo;

Animatronics::Animatronics()
{

}

Animatronics::~Animatronics()
{
}


void Animatronics::BeginPlay()
{
	Super::BeginPlay();
	
}

void Animatronics::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	RoomUpdate();
}

bool Animatronics::ACTOpportunity(int _CurLevel)
{
	//������ �ൿ ��ȸ
	int RandomNum = UEngineRandom::MainRandom.RandomInt(0, 20);
	if (_CurLevel >= RandomNum)
	{
		return true;
	}
	
	return false;

		
}

void Animatronics::SetLevel(int _Level)
{
	Level = _Level;
}







int Animatronics::MoveChance(int _Num)
{
	int RandomNum = UEngineRandom::MainRandom.RandomInt(0, 100);
	
	if (_Num < RandomNum)
	{
		return 0; //��Ҽ�
	}
	else if(RandomNum % 2 == 1)
	{
		// _Num���� ū�� Ȧ���ϰ�� 1
	return 1; //Ȯ�� ������
	}
	return 2;//�ƹ��͵� �ش�ȵǸ� 2
}// w

void Animatronics::LobbyCallBackCheck()
{
	//�ݹ��� �ൿ �־��ֱ� 
}

void Animatronics::RoomUpdate()
{
	// �� ��ü�� ��ȸ�ϸ鼭 ���� 
	for (std::shared_ptr<RoomManager> Room : CurRoomInfo)
	{
	///	std::string RoomName = Room->GetName();
		std::string RoomName = Room->GetCurRoomSpriteName();
		//RoomName = RoomName.substr(2);
		if (Room->GetMonster() != nullptr)
		{
			//std::string ResultName = RoomName + ".png";
			//Stage::CCTVPtr->GetRenderer()->SetSprite(ResultName);
			////��� ���� CCTVBackGround�� �־��ش�. 
			//continue;

			std::string MonsterName = Room->GetMonster()->GetName();
			std::string ResultName = RoomName + ".png";
			//Stage::CCTVPtr->MonsterSpriteChange(ResultName);
		}

	
	}
}

void Animatronics::FindMonsterIndex()
{
	// 
}