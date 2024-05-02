#include "PreCompile.h"
#include "ShowRoom.h"
#include <EngineBase/EngineRandom.h>
#include"MyCore.h"


ShowRoom::ShowRoom()
{

	UDefaultSceneComponent* Default = CreateDefaultSubObject<UDefaultSceneComponent>("Default");
	
	
//	RoomRender = CreateDefaultSubObject<USpriteRenderer>("Renderer");
//	RoomRender->SetSprite("ShowRoom.png");
//	RoomRender->SetAutoSize(1.0f, true);
//	RoomRender->SetupAttachment(Default);
//	RoomRender->SetOrder(100);
//	RoomRender->SetActive(true);
//	
		
	SetRoot(Default);

	//InitCCTVBackGround();

	
}

ShowRoom::~ShowRoom()
{
}


void ShowRoom::BeginPlay()
{
	

	Super::BeginPlay();
}


void ShowRoom::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	CheckRoom(nullptr); //방안에 몬스터가 존재하는가?

}
