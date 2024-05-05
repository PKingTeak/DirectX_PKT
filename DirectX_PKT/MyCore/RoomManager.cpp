#include"PreCompile.h"
#include "RoomManager.h"
#include"Animatronics.h"
RoomManager::RoomManager()
{
}

RoomManager::~RoomManager()
{
}

void RoomManager::BeginPlay()
{
	Super::BeginPlay();
}
void RoomManager::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}


bool RoomManager::CheckRoom()
{
	if (Monster != nullptr)
	{
		return true;
	}
	return false;
}


void RoomManager::SetMonter(Animatronics* _Monster)
{
	//만약 이동하면 이전에 있던곳은 nullptr로 바꿔줘야 함
	Monster = _Monster;

}

Animatronics* RoomManager::GetMonster()
{
	return Monster;
}

void RoomManager::ChangeRoomCamera(Animatronics* _Monster) //해당 랜더러를 바꿔주면 될듯
{
	if (CheckRoom() == true)
	{
		int a = 0;
	}

}


UImage* RoomManager::GetUI()
{
	return Camera;
}

void RoomManager::SetMonster(Animatronics* _Monster)
{
	Monster = _Monster;
}


std::string RoomManager::GetCurRoomSpriteName()
{
	return CurRoomSpriteName;
}

void RoomManager::SettingSpriteName(int _Index)
{
	CurRoomSpriteName[_Index];
}

void RoomManager::MapUpdate()
{
	CurRoomSpriteName;
}