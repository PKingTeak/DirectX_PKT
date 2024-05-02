#include "PreCompile.h"
#include "HallDining.h"
#include <EngineBase/EngineRandom.h>
#include"MyCore.h"


HallDining::HallDining()
{

	UDefaultSceneComponent* Default = CreateDefaultSubObject<UDefaultSceneComponent>("Default");


	RoomRender = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	RoomRender->SetSprite("HallDining.png");
	RoomRender->SetAutoSize(1.0f, true);
	RoomRender->SetupAttachment(Default);
	RoomRender->SetOrder(105);
	RoomRender->SetActive(true);



	SetRoot(Default);


}

HallDining::~HallDining()
{
}


void HallDining::BeginPlay()
{



}


void HallDining::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}


void HallDining::SetMonster(Animatronics* _Monster)
{
	if (Monster != nullptr)
	{
		return;
	}
	Monster = _Monster;
}


bool HallDining::CheckRoom()
{
	if (Monster != nullptr)
	{
		return true;
	}
	return true;
}