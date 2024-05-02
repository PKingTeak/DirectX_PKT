#include"PreCompile.h"
#include "RoomManager.h"

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


bool RoomManager::CheckRoom(Animatronics* _Monster)
{
	Monster = _Monster;
	if (Monster != nullptr)
	{
		return true;
	}
	return false;
}
