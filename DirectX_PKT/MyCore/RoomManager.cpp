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
	//���� �̵��ϸ� ������ �ִ����� nullptr�� �ٲ���� ��
	Monster = _Monster;

}

Animatronics* RoomManager::GetMonster()
{
	return Monster;
}

void RoomManager::ChangeRoomCamera(Animatronics* _Monster) //�ش� �������� �ٲ��ָ� �ɵ�
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