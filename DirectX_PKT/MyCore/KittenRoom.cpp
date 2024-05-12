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
	Camera->SetPosition(FVector{ 550,-250 });
	Camera->SetAutoSize(1.0f, true);
	Camera->AddToViewPort(3);

	RoomStatename = { "ClearScreen" };
	SettingSpriteName(0); // 이걸로 벡터 안에 있는 인덱스 이름에 접근이 가능함 
	//숨소리 재생해주는 소리넣어야 한다. 
}


void KittenRoom::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	//MapUpdate();

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



void KittenRoom::ChangeRoomCamera(Animatronics* _Monster)
{//해당 몬스터의 정보를 갸져와서 방 이름을 바꿔주는 역할을 하고 
	// 해당 방 이미지가 저장되어 있는 벡터의 이미지를 변경해 준다. 
	std::string MonsterName = _Monster->GetName();
	if (GetMonster() != nullptr)
	{
		if (MonsterName == "Chica")
		{
			RoomRender->SetSprite(RoomStatename[0] + ".png");
			//사운드 재생 넣기 
			//숨소리
		}

	}


}
void KittenRoom::MapUpdate()
{

}





