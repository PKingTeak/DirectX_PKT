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
	Camera->AddToViewPort(2);


}


void HallDining::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}




void HallDining::ChangeRoomCamera(Animatronics* _Monster)
{//해당 몬스터의 정보를 갸져와서 방 이름을 바꿔주는 역할을 하고 
	// 해당 방 이미지가 저장되어 있는 벡터의 이미지를 변경해 준다. 
	std::string MonsterName = _Monster->GetName();
	if (GetMonster() != nullptr)
	{
		if (MonsterName == "Bonni")
		{
			RoomRender->SetSprite(HallStatename[2]+".png");
		}

		if (MonsterName == "Chica")
		{
			RoomRender->SetSprite(HallStatename[4] + ".png");
		}
	}
	

}

void HallDining::MapChangeSprite(Animatronics* _Monster)
{
	std::string setSprite = this->GetName().append(_Monster->GetName());

	RoomRender->SetSprite(setSprite);
}

//std::string HallDining::FindImageName(std::vector<std::string> _Statename , std::string _MonsterLocal)
//{
//
//
//}







