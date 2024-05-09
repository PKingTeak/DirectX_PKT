#include "PreCompile.h"
#include "SupplyCloset.h"
#include"Animatronics.h"
#include <EngineBase/EngineRandom.h>
#include"MyCore.h"


SupplyCloset::SupplyCloset()
{


}

SupplyCloset::~SupplyCloset()
{
}


void SupplyCloset::BeginPlay()
{
	Super::BeginPlay();
	Camera = CreateWidget<UImage>(GetWorld(), "SupplyCloset");
	Camera->SetSprite("Cam3.png", 0);
	Camera->CreateAnimation("SupplyClosetAni", "Cam3.png", 0.5f, true, 0, 0);
	Camera->CreateAnimation("CSupplyClosetAni", "Cam3.png", 0.5f, true, 0, 1);
	Camera->SetPosition(FVector{ 250,-250 });
	Camera->SetAutoSize(1.0f, true);
	Camera->AddToViewPort(3);

	RoomStatename = { "SupplyCloset","SupplyBonni" };
	SettingSpriteName(0); // �̰ɷ� ���� �ȿ� �ִ� �ε��� �̸��� ������ ������ 

}


void SupplyCloset::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	MapUpdate();

}




void SupplyCloset::ChangeRoomCamera(Animatronics* _Monster)
{//�ش� ������ ������ �����ͼ� �� �̸��� �ٲ��ִ� ������ �ϰ� 
	// �ش� �� �̹����� ����Ǿ� �ִ� ������ �̹����� ������ �ش�. 
	std::string MonsterName = _Monster->GetName();
	if (GetMonster() != nullptr)
	{
		if (MonsterName == "Bonni")
		{
			RoomRender->SetSprite(RoomStatename[1] + ".png");
		}

	}


}

void SupplyCloset::MapChangeSprite(Animatronics* _Monster)
{
	std::string setSprite = this->GetName().append(_Monster->GetName());

	RoomRender->SetSprite(setSprite);
}

void SupplyCloset::SettingSpriteName(int _Index = 0)
{

	CurRoomSpriteName = RoomStatename[_Index];
}

void SupplyCloset::MapUpdate()
{
	Monster = GetMonster();

	if (Monster != nullptr)
	{
		std::string CheckName = Monster->GetName();
		if (CheckName == "Bonni")
		{
			SettingSpriteName(1);
			PrevMonster = Monster;

			// ���࿡ ���Ͱ� ������ �ٽ� ���� ���·� �̹��� �����°� 
			// ���� Ŭ���� ���ο��� ����
			return;
		}

		SettingSpriteName(0);

	}

	//SettingSpriteName(0);




}





