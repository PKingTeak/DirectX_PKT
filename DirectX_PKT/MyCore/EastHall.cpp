#include "PreCompile.h"
#include "EastHall.h"
#include"Animatronics.h"
#include <EngineBase/EngineRandom.h>
#include"MyCore.h"


EastHall::EastHall()
{


}

EastHall::~EastHall()
{


}


void EastHall::BeginPlay()
{
	Super::BeginPlay();
	Camera = CreateWidget<UImage>(GetWorld(), "EestHall");
	Camera->SetSprite("Cam4A.png", 0);
	Camera->CreateAnimation("EestHallAni", "Cam4A.png", 0.5f, true, 0, 0);
	Camera->CreateAnimation("CEestHallAni", "Cam4A.png", 0.5f, true, 0, 1);
	Camera->SetPosition(FVector{ 440,-240 });
	Camera->SetAutoSize(1.0f, true);
	Camera->AddToViewPort(3);

	RoomStatename = { "EastHall","EastHallChica" };
	SettingSpriteName(0); // 이걸로 벡터 안에 있는 인덱스 이름에 접근이 가능함 

}


void EastHall::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}




void EastHall::ChangeRoomCamera(Animatronics* _Monster)
{//해당 몬스터의 정보를 갸져와서 방 이름을 바꿔주는 역할을 하고 
	// 해당 방 이미지가 저장되어 있는 벡터의 이미지를 변경해 준다. 
	std::string MonsterName = _Monster->GetName();
	if (GetMonster() != nullptr)
	{
		if (MonsterName == "Chica")
		{
			RoomRender->SetSprite(RoomStatename[2] + ".png");
		}

	}


	SettingSpriteName(0);


}

void EastHall::MapChangeSprite(Animatronics* _Monster)
{
	std::string setSprite = this->GetName().append(_Monster->GetName());

	RoomRender->SetSprite(setSprite);
}

void EastHall::SettingSpriteName(int _Index = 0)
{

	CurRoomSpriteName = RoomStatename[_Index];
}

void EastHall::MapUpdate()
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





