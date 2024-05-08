#include "PreCompile.h"
#include "KittenRoom.h"
#include"Animatronics.h"
#include <EngineBase/EngineRandom.h>
#include"MyCore.h"


KittenRoom::KittenRoom()
{


}

KittenRoom::~KittenRoom()
{
}


void KittenRoom::BeginPlay()
{
	Super::BeginPlay();
	Camera = CreateWidget<UImage>(GetWorld(), "KittenRoom");
	Camera->SetSprite("Cam6.png", 0);
	Camera->CreateAnimation("KittenRoomAni", "Cam6.png", 0.5f, true, 0, 0);
	Camera->CreateAnimation("CKittenRoomAni", "Cam6.png", 0.5f, true, 0, 1);
	Camera->SetPosition(FVector{ 250,-250 });
	Camera->SetAutoSize(1.0f, true);
	Camera->AddToViewPort(3);


	SettingSpriteName(0); // 이걸로 벡터 안에 있는 인덱스 이름에 접근이 가능함 

}


void KittenRoom::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	MapUpdate();

}



void KittenRoom::MapChangeSprite(Animatronics* _Monster)
{
	std::string setSprite = this->GetName().append(_Monster->GetName());

	RoomRender->SetSprite(setSprite);
}

void KittenRoom::SettingSpriteName(int _Index = 0)
{

	CurRoomSpriteName = RoomStatename[_Index];
}







