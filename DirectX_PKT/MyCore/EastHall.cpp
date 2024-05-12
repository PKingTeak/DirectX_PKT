#include "PreCompile.h"
#include "EastHall.h"
#include"Animatronics.h"
#include <EngineBase/EngineRandom.h>
#include"MyCore.h"


EastHall::EastHall()
{


}

EastHall::~EastHall()
{


}


void EastHall::BeginPlay()
{
	Super::BeginPlay();
	Camera = CreateWidget<UImage>(GetWorld(), "EestHall");
	Camera->SetSprite("Cam4A.png", 0);
	Camera->CreateAnimation("EestHallAni", "Cam4A.png", 0.5f, true, 0, 0);
	Camera->CreateAnimation("CEestHallAni", "Cam4A.png", 0.5f, true, 0, 1);
	Camera->SetPosition(FVector{ 440,-240 });
	Camera->SetAutoSize(1.0f, true);
	Camera->AddToViewPort(3);

	RoomStatename = { "EastHall","EastHallChica" };
	SettingSpriteName(0); // �̰ɷ� ���� �ȿ� �ִ� �ε��� �̸��� ������ ������ 

}


void EastHall::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}




void EastHall::ChangeRoomCamera(Animatronics* _Monster)
{//�ش� ������ ������ �����ͼ� �� �̸��� �ٲ��ִ� ������ �ϰ� 
	// �ش� �� �̹����� ����Ǿ� �ִ� ������ �̹����� ������ �ش�. 
	std::string MonsterName = _Monster->GetName();
	if (GetMonster() != nullptr)
	{
		if (MonsterName == "Chica")
		{
			RoomRender->SetSprite(RoomStatename[2] + ".png");
		}

	}


	SettingSpriteName(0);


}

void EastHall::MapChangeSprite(Animatronics* _Monster)
{
	std::string setSprite = this->GetName().append(_Monster->GetName());

	RoomRender->SetSprite(setSprite);
}

void EastHall::SettingSpriteName(int _Index = 0)
{

	CurRoomSpriteName = RoomStatename[_Index];
}

void EastHall::MapUpdate()
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





