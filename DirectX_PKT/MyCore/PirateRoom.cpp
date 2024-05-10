#include "PreCompile.h"
#include "PirateRoom.h"
#include"Animatronics.h"
#include <EngineBase/EngineRandom.h>
#include"MyCore.h"


PirateRoom::PirateRoom()
{

	

}

PirateRoom::~PirateRoom()
{
}


void PirateRoom::BeginPlay()
{
	Super::BeginPlay();
	Camera = CreateWidget<UImage>(GetWorld(), "PirateRoom");
	Camera->SetSprite("Cam1C.png", 0);
	Camera->CreateAnimation("PirateRoomAni", "Cam1C.png", 0.5f, true, 0, 0);
	Camera->CreateAnimation("CPirateRoomAni", "Cam1C.png", 0.5f, true, 0, 1);
	Camera->SetPosition(FVector{ 280,-100 });
	Camera->SetAutoSize(1.0f, true);
	Camera->AddToViewPort(3);
	RoomStatename = { "PirateRoom","PirateRoom2","PirateRoomBonni","PirateRoomBonnie2","PirateRoomBonni","PirateRoomBonni2" };


	SettingSpriteName(0); // �̰ɷ� ���� �ȿ� �ִ� �ε��� �̸��� ������ ������ 

}


void PirateRoom::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
}





void PirateRoom::ChangeRoomCamera(Animatronics* _Monster)
{//�ش� ������ ������ �����ͼ� �� �̸��� �ٲ��ִ� ������ �ϰ� 
	// �ش� �� �̹����� ����Ǿ� �ִ� ������ �̹����� ������ �ش�. 
	std::string MonsterName = _Monster->GetName();
	if (GetMonster() != nullptr)
	{
		if (MonsterName == "Bonni")
		{
			RoomRender->SetSprite(RoomStatename[2] + ".png");
		}

		if (MonsterName == "Chica")
		{
			RoomRender->SetSprite(RoomStatename[4] + ".png");
		}
	}



}

void PirateRoom::MapChangeSprite(Animatronics* _Monster)
{
	std::string setSprite = this->GetName().append(_Monster->GetName());

	RoomRender->SetSprite(setSprite);
}

void PirateRoom::SettingSpriteName(int _Index = 0)
{

	CurRoomSpriteName = RoomStatename[_Index];
}

void PirateRoom::MapUpdate()
{
	Monster = GetMonster();

	if (Monster != nullptr)
	{
		std::string CheckName = Monster->GetName();
		if (CheckName == "Bonni")
		{
			SettingSpriteName(2);
			PrevMonster = Monster;
			return;
		}

	}

	if (PrevMonster != Monster)
	{
		SettingSpriteName(0);
		//���Ͱ� ���������� �ٽ� ���� �������� ����
		//ƽ���� ������ ī�޶� �ٶ󺼶� �ﰢ ������� ���� 
	}




}





