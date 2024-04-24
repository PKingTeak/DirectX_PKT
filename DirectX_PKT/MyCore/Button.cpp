#include "PreCompile.h"
#include "Button.h"
#include "Stage.h"
#include<EngineCore/DefaultSceneComponent.h>
#include"MyCore.h"

Button* Button::MainButton = nullptr;
Button::Button()
{

	UDefaultSceneComponent* Defualt = CreateDefaultSubObject<UDefaultSceneComponent>("Defualt");

	LeftButtonRender = CreateDefaultSubObject<USpriteRenderer>("LeftButtonRender");
	LeftButtonRender->SetSprite("Button.png");
	LeftButtonRender->SetAutoSize(1.0f, true);
	LeftButtonRender->SetPosition(FVector{ -760,-20 });
	//왜 Defualt를 해야 위치가 현재 랜더러 인 상태인것인가
	//디폴트 설정하는거자체가 자신의 엑터를 설정한 것이고 그 엑터를 움직여서 위치시켰으니 
	//그 움직여서 옮기 자리가 결국 0,0 이 되는것이다. 
	LeftButtonRender->SetOrder(OrderType::Object);
	LeftButtonRender->SetupAttachment(Defualt);
	

	
	LeftDoorButton = CreateDefaultSubObject<UCollision> ("LeftDoorButton");
	LeftDoorButton->SetCollisionGroup(OrderType::Object);
	LeftDoorButton->SetCollisionType(ECollisionType::Rect);
	LeftDoorButton->SetScale(FVector{ 50,50 });
	LeftDoorButton->SetupAttachment(Defualt);
	LeftDoorButton->SetPosition(FVector{ -760,30 });
	LeftDoorButton->SetOrder(OrderType::Object);
	


	LeftLightButton = CreateDefaultSubObject<UCollision>("LeftLightButton");
	LeftLightButton->SetupAttachment(Defualt); // 오브젝트 위치를 가져와서 거기서 아래로 내린다는 순서
	LeftLightButton->SetCollisionGroup(OrderType::Object);
	LeftLightButton->SetCollisionType(ECollisionType::Rect);
	LeftLightButton->SetOrder(OrderType::Object);
	LeftLightButton->SetScale(FVector{ 50,50 });
	LeftLightButton->SetPosition(FVector{ -760,-70 });
	

	RightButtonRender = CreateDefaultSubObject<USpriteRenderer>("RightButtonRender");
	RightButtonRender->SetSprite("Button.png",4);
	RightButtonRender->SetPosition(FVector{ 300,-20 });
	RightButtonRender->SetAutoSize(1.0f, true);
	//왜 Defualt를 해야 위치가 현재 랜더러 인 상태인것인가
	//디폴트 설정하는거자체가 자신의 엑터를 설정한 것이고 그 엑터를 움직여서 위치시켰으니 
	//그 움직여서 옮기 자리가 결국 0,0 이 되는것이다. 
	RightButtonRender->SetOrder(OrderType::Object);
	RightButtonRender->SetupAttachment(Defualt);


	RightDoorButton = CreateDefaultSubObject<UCollision>("RightDoorButton");
	RightDoorButton->SetupAttachment(Defualt);
	RightDoorButton->SetCollisionGroup(OrderType::Object);
	RightDoorButton->SetCollisionType(ECollisionType::Rect);
	RightDoorButton->SetScale(FVector{ 50,50 });
	RightDoorButton->SetPosition(FVector{ 0,50 });
	RightDoorButton->SetOrder(OrderType::Object);



	RightLightButton = CreateDefaultSubObject<UCollision>("RightLightButton");
	RightLightButton->SetupAttachment(Defualt); // 오브젝트 위치를 가져와서 거기서 아래로 내린다는 순서
	RightLightButton->SetCollisionGroup(OrderType::Object);
	RightLightButton->SetCollisionType(ECollisionType::Rect);
	RightLightButton->SetOrder(OrderType::Object);
	RightLightButton->SetScale(FVector{ 50,50 });
	RightLightButton->SetPosition(FVector{ 0,-50 });
	
	SetRoot(Defualt);

}
Button::~Button()
{


}
void Button::BeginPlay()
{
	MainButton = this;

	Super::BeginPlay();
	
	SetActorLocation(FVector{ 0,0, });


	


}


void Button::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}

void Button::ButtonLight(std::string _ButtonName)
{
	if (_ButtonName._Equal("LeftLightButton"))
	{
		LeftButtonRender->SetSprite("Button.png",1);
		LeftLight = true;

	}
	else if(_ButtonName._Equal("RightLightButton"))
	{
		RightLight = true;
	}
	//BackStageGround::ChageBackGround();
}

void Button::ButtonDoor(std::string _ButtonName)
{
	
}
void Button::MoveButton(FVector _SetPos)
{
	SetActorLocation(_SetPos);

}



