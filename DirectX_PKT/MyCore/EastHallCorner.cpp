#include "PreCompile.h"
#include "EastHallCorner.h"
#include"Animatronics.h"
#include <EngineBase/EngineRandom.h>
#include"MyCore.h"


EastHallCorner::EastHallCorner()
{


}

EastHallCorner::~EastHallCorner()
{
}


void EastHallCorner::BeginPlay()
{
	Super::BeginPlay();
	Camera = CreateWidget<UImage>(GetWorld(), "EastHallConer");
	Camera->SetSprite("Cam4B.png", 0);
	Camera->CreateAnimation("EastHallConerAni", "Cam4B.png", 0.5f, true, 0, 0);
	Camera->CreateAnimation("CEastHallConerAni", "Cam4B.png", 0.5f, true, 0, 1);
	Camera->SetPosition(FVector{ 440,-280 });
	Camera->SetAutoSize(1.0f, true);
	Camera->AddToViewPort(3);
	RoomStatename = { "EastHallCorner","EastHallCornerBonni" };

	SettingSpriteName(0); // �̰ɷ� ���� �ȿ� �ִ� �ε��� �̸��� ������ ������ 

}


void EastHallCorner::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	MapUpdate();

}




void EastHallCorner::ChangeRoomCamera(Animatronics* _Monster)
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

void EastHallCorner::MapChangeSprite(Animatronics* _Monster)
{
	std::string setSprite = this->GetName().append(_Monster->GetName());

	RoomRender->SetSprite(setSprite);
}

void EastHallCorner::SettingSpriteName(int _Index = 0)
{

	CurRoomSpriteName = RoomStatename[_Index];
}

void EastHallCorner::MapUpdate()
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





