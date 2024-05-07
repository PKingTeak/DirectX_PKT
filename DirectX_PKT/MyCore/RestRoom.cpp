#include "PreCompile.h"
#include "RestRoom.h"
#include"Animatronics.h"
#include <EngineBase/EngineRandom.h>
#include"MyCore.h"


RestRoom::RestRoom()
{


}

RestRoom::~RestRoom()
{
}


void RestRoom::BeginPlay()
{
	Super::BeginPlay();
	Camera = CreateWidget<UImage>(GetWorld(), "RestRoom");
	Camera->SetSprite("Cam7.png", 0);
	Camera->CreateAnimation("RestRoomAni", "Cam7.png", 0.5f, true, 0, 0);
	Camera->CreateAnimation("CRestRoom", "Cam7.png", 0.5f, true, 0, 1);
	Camera->SetPosition(FVector{ 250,-50 });
	Camera->SetAutoSize(1.0f, true);
	Camera->AddToViewPort(3);


	SettingSpriteName(0); // �̰ɷ� ���� �ȿ� �ִ� �ε��� �̸��� ������ ������ 

}


void RestRoom::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	MapUpdate();

}




void RestRoom::ChangeRoomCamera(Animatronics* _Monster)
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

void RestRoom::MapChangeSprite(Animatronics* _Monster)
{
	std::string setSprite = this->GetName().append(_Monster->GetName());

	RoomRender->SetSprite(setSprite);
}

void RestRoom::SettingSpriteName(int _Index = 0)
{

	CurRoomSpriteName = RoomStatename[_Index];
}

void RestRoom::MapUpdate()
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





