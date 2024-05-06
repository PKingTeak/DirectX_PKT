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
