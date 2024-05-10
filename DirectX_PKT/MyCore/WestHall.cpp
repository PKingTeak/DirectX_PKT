#include"PreCompile.h"
#include "WestHall.h"

WestHall::WestHall()
{
}

WestHall::~WestHall()
{
}

void WestHall::BeginPlay()
{
	Super::BeginPlay();
	Camera = CreateWidget<UImage>(GetWorld(), "WestHall");
	Camera->SetSprite("Cam2A.png", 0);
	Camera->CreateAnimation("WestHallAni", "Cam2A.png", 0.5f, true, 0, 0);
	Camera->CreateAnimation("CWestHallAni", "Cam2A.png", 0.5f, true, 0, 1);
	Camera->SetPosition(FVector{ 320,-240 });
	Camera->SetAutoSize(1.0f, true);
	Camera->AddToViewPort(3);
	RoomStatename = { "WestHall","WestHallBonnie" };

	SettingSpriteName(0);
}

void WestHall::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}
void WestHall::SettingSpriteName(int _Index = 0)
{

	CurRoomSpriteName = RoomStatename[_Index];
}

void WestHall::MapUpdate()
{
	Monster = GetMonster();

	if (Monster != nullptr) 
	{
		std::string CheckName = Monster->GetName();
		if (CheckName == "Bonni")
		{
			SettingSpriteName(1);
			PrevMonster = Monster;
			return;
		}

	}

	//SettingSpriteName(0);




}
