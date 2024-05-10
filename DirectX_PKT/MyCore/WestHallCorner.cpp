#include"PreCompile.h"
#include "WestHallCorner.h"

WestHallCorner::WestHallCorner()
{

	
}

WestHallCorner::~WestHallCorner()
{
}

void WestHallCorner::BeginPlay()
{
	Super::BeginPlay();
	Camera = CreateWidget<UImage>(GetWorld(), "WestHallCorner");
	Camera->SetSprite("Cam2B.png",0);
	Camera->CreateAnimation("WestHallCornerAni", "Cam2B.png", 0.5f, true, 0, 0);
	Camera->CreateAnimation("CWestHallCornerAni", "Cam2B.png", 0.5f, true, 0, 1);
	Camera->SetAutoSize(1.0f, true);
	Camera->SetPosition(FVector{ 320,-280 });
	Camera->AddToViewPort(3);


	RoomStatename = { "WestHallCorner","WestCornerBonni","WestCornerBonni2","WestCornerBonni3" };
	SettingSpriteName(0);
} 

void WestHallCorner::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
}
void WestHallCorner::SettingSpriteName(int _Index = 0)
{

	CurRoomSpriteName = RoomStatename[_Index];
}

void WestHallCorner::MapUpdate()
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

	SettingSpriteName(0);
	//SettingSpriteName(0);




}
