#include "PreCompile.h"
#include "BackStage.h"
#include"Animatronics.h"
#include <EngineBase/EngineRandom.h>
#include"MyCore.h"


BackStage::BackStage()
{


}

BackStage::~BackStage()
{
}


void BackStage::BeginPlay()
{
	Super::BeginPlay();
	Camera = CreateWidget<UImage>(GetWorld(), "BackStage");
	Camera->SetSprite("Cam5.png", 0);
	Camera->CreateAnimation("BackStageAni", "Cam5.png", 0.5f, true, 0, 0);
	Camera->CreateAnimation("CBackStageAni", "Cam5.png", 0.5f, true, 0, 1);
	Camera->SetPosition(FVector{ 220,-60 });
	Camera->SetAutoSize(1.0f, true);
	Camera->AddToViewPort(3);

	RoomStatename = { "BackStage","BackStageBonni","BackStageBonni1" };
	SettingSpriteName(0); // �̰ɷ� ���� �ȿ� �ִ� �ε��� �̸��� ������ ������ 

}


void BackStage::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	

}




void BackStage::ChangeRoomCamera(Animatronics* _Monster)
{//�ش� ������ ������ �����ͼ� �� �̸��� �ٲ��ִ� ������ �ϰ� 
	// �ش� �� �̹����� ����Ǿ� �ִ� ������ �̹����� ������ �ش�. 
	std::string MonsterName = _Monster->GetName();
	if (GetMonster() != nullptr)
	{
		if (MonsterName == "Bonni")
		{
			RoomRender->SetSprite(RoomStatename[2] + ".png");
		}

	}


}

void BackStage::MapChangeSprite(Animatronics* _Monster)
{
	std::string setSprite = this->GetName().append(_Monster->GetName());

	RoomRender->SetSprite(setSprite);
}

void BackStage::SettingSpriteName(int _Index = 0)
{

	CurRoomSpriteName = RoomStatename[_Index];
}

void BackStage::MapUpdate()
{
	Monster = GetMonster();

	if (Monster != nullptr)
	{
		std::string CheckName = Monster->GetName();
		if (CheckName == "Bonni")
		{
			SettingSpriteName(2);
			PrevMonster = Monster;

			// ���࿡ ���Ͱ� ������ �ٽ� ���� ���·� �̹��� �����°� 
			// ���� Ŭ���� ���ο��� ����
			return;
		}

	}

	//SettingSpriteName(0);




}





