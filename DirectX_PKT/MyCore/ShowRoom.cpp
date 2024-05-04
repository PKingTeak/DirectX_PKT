#include "PreCompile.h"
#include "ShowRoom.h"
#include <EngineBase/EngineRandom.h>
#include"Animatronics.h"
#include"MyCore.h"


ShowRoom::ShowRoom()
{

	//UDefaultSceneComponent* Default = CreateDefaultSubObject<UDefaultSceneComponent>("Default");
	//
	//
	//RoomRender = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	//RoomRender->SetSprite("ShowStageBonni.png");
	//RoomRender->SetAutoSize(1.0f, true);
	//RoomRender->SetupAttachment(Default);
	//RoomRender->SetOrder(100);
	//RoomRender->SetActive(false);
	//
	//
	//
	//
	//SetRoot(Default);
	//
	//InitCCTVBackGround();

	
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
	Camera->AddToViewPort(2);

	Super::BeginPlay();

	
}


void ShowRoom::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	//CheckRoom(); //방안에 몬스터가 존재하는가?

}


void ShowRoom::ChangeRoomCamera(Animatronics* _Monster)
{


	int a = 0;


}