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

bool RoomManager::GetMonster()
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


