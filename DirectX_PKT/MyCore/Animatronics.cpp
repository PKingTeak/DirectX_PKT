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
	//난수로 행동 기회
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
		return 0; //희소성
	}
	else if(RandomNum % 2 == 1)
	{
		// _Num보다 큰데 홀수일경우 1
	return 1; //확률 높은거
	}
	return 2;//아무것도 해당안되면 2
}// w

void Animatronics::LobbyCallBackCheck()
{
	//콜백할 행동 넣어주기 
}

void Animatronics::RoomUpdate()
{
	// 방 전체를 순회하면서 돌고 
	for (std::shared_ptr<RoomManager> Room : CurRoomInfo)
	{
	///	std::string RoomName = Room->GetName();
		std::string RoomName = Room->GetCurRoomSpriteName();
		//RoomName = RoomName.substr(2);
		if (Room->GetMonster() != nullptr)
		{
			//std::string ResultName = RoomName + ".png";
			//Stage::CCTVPtr->GetRenderer()->SetSprite(ResultName);
			////결과 값을 CCTVBackGround에 넣어준다. 
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