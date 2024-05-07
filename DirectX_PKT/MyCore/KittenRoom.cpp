#include "PreCompile.h"
#include "KittenRoom.h"
#include"Animatronics.h"
#include <EngineBase/EngineRandom.h>
#include"MyCore.h"


KittenRoom::KittenRoom()
{


}

KittenRoom::~KittenRoom()
{
}


void KittenRoom::BeginPlay()
{
	Super::BeginPlay();
	Camera = CreateWidget<UImage>(GetWorld(), "KittenRoom");
	Camera->SetSprite("Cam3.png", 0);
	Camera->CreateAnimation("KittenRoomAni", "Cam1B.png", 0.5f, true, 0, 0);
	Camera->CreateAnimation("CKittenRoomAni", "Cam1B.png", 0.5f, true, 0, 1);
	Camera->SetPosition(FVector{ 250,-250 });
	Camera->SetAutoSize(1.0f, true);
	Camera->AddToViewPort(3);


	SettingSpriteName(0); // �̰ɷ� ���� �ȿ� �ִ� �ε��� �̸��� ������ ������ 

}


void KittenRoom::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	MapUpdate();

}




void KittenRoom::ChangeRoomCamera(Animatronics* _Monster)
{//�ش� ������ ������ �����ͼ� �� �̸��� �ٲ��ִ� ������ �ϰ� 
	// �ش� �� �̹����� ����Ǿ� �ִ� ������ �̹����� ������ �ش�. 
	std::string MonsterName = _Monster->GetName();
	if (GetMonster() != nullptr)
	{
		if (MonsterName == "Bonni")
		{
			RoomRender->SetSprite(RoomStatename[2] + ".png");
		}

	}


}

void KittenRoom::MapChangeSprite(Animatronics* _Monster)
{
	std::string setSprite = this->GetName().append(_Monster->GetName());

	RoomRender->SetSprite(setSprite);
}

void KittenRoom::SettingSpriteName(int _Index = 0)
{

	CurRoomSpriteName = RoomStatename[_Index];
}

void KittenRoom::MapUpdate()
{
	Monster = GetMonster();

	if (Monster != nullptr)
	{
		std::string CheckName = Monster->GetName();
		if (CheckName == "Bonni")
		{
			SettingSpriteName(2);
			PrevMonster = Monster;

			// ���࿡ ���Ͱ� ������ �ٽ� ���� ���·� �̹��� �����°� 
			// ���� Ŭ���� ���ο��� ����
			return;
		}

	}

	//SettingSpriteName(0);




}





