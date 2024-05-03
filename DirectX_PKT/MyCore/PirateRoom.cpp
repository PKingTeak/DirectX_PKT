#include "PreCompile.h"
#include "PirateRoom.h"
#include <EngineBase/EngineRandom.h>
#include"MyCore.h"
#include"Animatronics.h"

PirateRoom::PirateRoom()
{

	UDefaultSceneComponent* Default = CreateDefaultSubObject<UDefaultSceneComponent>("Default");


	RoomRender = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	RoomRender->SetSprite("PirateRoom.png");
	RoomRender->SetAutoSize(1.0f, true);
	RoomRender->SetupAttachment(Default);
	RoomRender->SetOrder(105);
	RoomRender->SetActive(true);
	
	

	SetRoot(Default);


}

PirateRoom::~PirateRoom()
{
}


void PirateRoom::BeginPlay()
{
	Camera = CreateWidget<UImage>(GetWorld(), "PirateRoom");
	Camera->SetSprite("Cam1C.png", 0);
	Camera->CreateAnimation("PirateRoomAni", "Cam1C.png", 0.5f, true, 0, 0);
	Camera->CreateAnimation("CPirateRoomAni", "Cam1C.png", 0.5f, true, 0, 1);
	Camera->SetPosition(FVector{ 280,-100 });
	Camera->SetAutoSize(1.0f, true);
	Camera->AddToViewPort(2);

}


void PirateRoom::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}


void PirateRoom::SetMonster(Animatronics* _Monster)
{
	if (Monster != nullptr)
	{
		isMonster = false;
		return;
	}
	isMonster = true;
	Monster = _Monster;
}









