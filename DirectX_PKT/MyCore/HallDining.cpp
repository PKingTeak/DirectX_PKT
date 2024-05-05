#include "PreCompile.h"
#include "HallDining.h"
#include"Animatronics.h"
#include <EngineBase/EngineRandom.h>
#include"MyCore.h"


HallDining::HallDining()
{

	//UDefaultSceneComponent* Default = CreateDefaultSubObject<UDefaultSceneComponent>("Default");
	//
	//
	//RoomRender = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	//RoomRender->SetSprite("HallDining.png");
	//RoomRender->SetAutoSize(1.0f, true);
	//RoomRender->SetupAttachment(Default);
	//RoomRender->SetOrder(100);
	//RoomRender->SetActive(false);
	//
	//
	//
	//SetRoot(Default);


}

HallDining::~HallDining()
{
}


void HallDining::BeginPlay()
{
	Super::BeginPlay();
	Camera = CreateWidget<UImage>(GetWorld(), "HallDining");
	Camera->SetSprite("Cam1B.png", 0);
	Camera->CreateAnimation("HallDiningAni", "Cam1B.png", 0.5f, true, 0, 0);
	Camera->CreateAnimation("CHallDiningAni", "Cam1B.png", 0.5f, true, 0, 1);
	Camera->SetPosition(FVector{ 370,-50 });
	Camera->SetAutoSize(1.0f, true);
	Camera->AddToViewPort(3);

	SettingSpriteName(0); // �̰ɷ� ���� �ȿ� �ִ� �ε��� �̸��� ������ ������ 

}


void HallDining::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	MapUpdate();
}




void HallDining::ChangeRoomCamera(Animatronics* _Monster)
{//�ش� ������ ������ �����ͼ� �� �̸��� �ٲ��ִ� ������ �ϰ� 
	// �ش� �� �̹����� ����Ǿ� �ִ� ������ �̹����� ������ �ش�. 
	std::string MonsterName = _Monster->GetName();
	if (GetMonster() != nullptr)
	{
		if (MonsterName == "Bonni")
		{
			RoomRender->SetSprite(RoomStatename[2]+".png");
		}

		if (MonsterName == "Chica")
		{
			RoomRender->SetSprite(RoomStatename[4] + ".png");
		}
	}
	

}

void HallDining::MapChangeSprite(Animatronics* _Monster)
{
	std::string setSprite = this->GetName().append(_Monster->GetName());

	RoomRender->SetSprite(setSprite);
}

void HallDining::SettingSpriteName(int _Index = 0)
{

	CurRoomSpriteName = RoomStatename[_Index];
}

void HallDining::MapUpdate()
{	
	Monster = GetMonster();
	
	if (Monster != nullptr)
	{
		std::string CheckName = Monster->GetName();
		if (CheckName == "Bonni")
		{
			SettingSpriteName(2);
			return;
		}

	}

	SettingSpriteName(0);

	


}





