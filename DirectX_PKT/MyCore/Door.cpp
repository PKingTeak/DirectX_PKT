#include "PreCompile.h"
#include "Door.h"
#include"MyCore.h"

Door::Door()
{
	UDefaultSceneComponent* Default = CreateDefaultSubObject<UDefaultSceneComponent>("Default");
	

	
	LDoorRender = CreateDefaultSubObject<USpriteRenderer>("LDoorRender");
	LDoorRender->SetupAttachment(Default);
	LDoorRender->SetAutoSize(1.0f, true);
	LDoorRender->SetOrder(OrderType::Object);
	LDoorRender->SetSprite("LdoorStatic.png");
	LDoorRender->SetPosition(FVector{ -610,-20,-10 });
	LDoorRender->CreateAnimation("LeftDoorAni", "LdoorAnimation.png", 0.1f, false, 14, 0);
	LDoorRender->CreateAnimation("CLeftDoorAni", "LdoorAnimation.png", 0.1f, false, 0, 14);
	//LDoorRender->CreateAnimation("LeftDoorAni", "LdoorAnimation.png",0.1f,false,0,11);
	
	RDoorRender = CreateDefaultSubObject<USpriteRenderer>("RDoorRender");
	RDoorRender->SetupAttachment(Default);
	RDoorRender->SetAutoSize(1.0f, true);
	RDoorRender->SetOrder(OrderType::Object);
	RDoorRender->SetSprite("RdoorStatic.png");
	RDoorRender->CreateAnimation("RightDoorAni", "RdoorAnimation.png", 0.1f, false, 0, 14);
	RDoorRender->CreateAnimation("CRightDoorAni", "RdoorAnimation.png", 0.1f, false, 14, 0);
	RDoorRender->SetPosition(FVector{ 600,-20,-10 });

	SetRoot(Default);
	


}

Door::~Door()
{
}


void Door::BeginPlay()
{
	Super::BeginPlay();
	//LDoorRender->ChangeAnimation("LeftDoorAni");
	//SetActorScale3D(FVector{ 300,-20 });

}


void Door::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}



void Door::DoorOpen(std::string_view _ButtonName)
{
	
	//RDoorRender->AnimationReset();
	if (_ButtonName == "LeftDoorButton")
	{
		LDoorRender->ChangeAnimation("LeftDoorAni");
		isLDoorOpen = true;
		return;
	}

	else if (_ButtonName == "RightDoorButton")
	{
		RDoorRender->ChangeAnimation("RightDoorAni");
	}


	
}

void Door::DoorClose(std::string_view _ButtonName)
{
	if (_ButtonName == "LeftDoorButton")
	{
		LDoorRender->ChangeAnimation("CLeftDoorAni");
		isLDoorOpen = false;
		return;
	}

	else if (_ButtonName == "RightDoorButton")
	{
		//RDoorRender->ChangeAnimation("RightDoorAni");
	}


}


bool Door::GetLeftDoorState() // 문이 열여있으면 true 닫혀있으면 false;
{
	return isLDoorOpen; 

}
bool Door::GetRightDoorState()
{
	return isRDoorOpen;
}