#include "PreCompile.h"
#include "RestRoom.h"
#include"Animatronics.h"
#include <EngineBase/EngineRandom.h>
#include"MyCore.h"


RestRoom::RestRoom()
{


}

RestRoom::~RestRoom()
{
}


void RestRoom::BeginPlay()
{
	Super::BeginPlay();
	Camera = CreateWidget<UImage>(GetWorld(), "RestRoom");
	Camera->SetSprite("Cam7.png", 0);
	Camera->CreateAnimation("RestRoomAni", "Cam7.png", 0.5f, true, 0, 0);
	Camera->CreateAnimation("CRestRoom", "Cam7.png", 0.5f, true, 0, 1);
	Camera->SetPosition(FVector{ 250,-50 });
	Camera->SetAutoSize(1.0f, true);
	Camera->AddToViewPort(3);


	SettingSpriteName(0); // 이걸로 벡터 안에 있는 인덱스 이름에 접근이 가능함 

}


void RestRoom::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	MapUpdate();

}




void RestRoom::ChangeRoomCamera(Animatronics* _Monster)
{//해당 몬스터의 정보를 갸져와서 방 이름을 바꿔주는 역할을 하고 
	// 해당 방 이미지가 저장되어 있는 벡터의 이미지를 변경해 준다. 
	std::string MonsterName = _Monster->GetName();
	if (GetMonster() != nullptr)
	{
		if (MonsterName == "Bonni")
		{
			RoomRender->SetSprite(RoomStatename[2] + ".png");
		}

	}


}

void RestRoom::MapChangeSprite(Animatronics* _Monster)
{
	std::string setSprite = this->GetName().append(_Monster->GetName());

	RoomRender->SetSprite(setSprite);
}

void RestRoom::SettingSpriteName(int _Index = 0)
{

	CurRoomSpriteName = RoomStatename[_Index];
}

void RestRoom::MapUpdate()
{
	Monster = GetMonster();

	if (Monster != nullptr)
	{
		std::string CheckName = Monster->GetName();
		if (CheckName == "Bonni")
		{
			SettingSpriteName(2);
			PrevMonster = Monster;

			// 만약에 몬스터가 떠나면 다시 원래 상태로 이미지 돌리는건 
			// 보니 클래스 내부에서 진행
			return;
		}

	}

	//SettingSpriteName(0);




}





