#include "PreCompile.h"
#include "ShowRoom.h"
#include <EngineBase/EngineRandom.h>
#include"Animatronics.h"
#include"MyCore.h"


ShowRoom::ShowRoom()
{

	
}

ShowRoom::~ShowRoom()
{
}


void ShowRoom::BeginPlay()
{

	Camera = CreateWidget<UImage>(GetWorld(), "ShowRoom");
	Camera->CreateAnimation("ShowRoomAni", "Cam1A.png", 0.5f, true, 0, 0);
	Camera->CreateAnimation("CShowRoomAni", "Cam1A.png", 0.5f, true, 0, 1);
	Camera->ChangeAnimation("CShowRoomAni");
	Camera->SetPosition(FVector{ 370,0 });
	Camera->SetAutoSize(1.0f, true);
	Camera->AddToViewPort(3);

	Super::BeginPlay();
	SettingSpriteName(0);
	
}


void ShowRoom::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	//CheckRoom(); //방안에 몬스터가 존재하는가?

}


void ShowRoom::SettingSpriteName(int _index = 0)
{
	CurRoomSpriteName = RoomStatename[_index];
}

void ShowRoom::MapUpdate()
{
	if (Monster == nullptr)
	{
		//여기만  표현을 못하겟음
	}
}