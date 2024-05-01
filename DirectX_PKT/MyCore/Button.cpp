
#include "PreCompile.h"
#include "Button.h"
#include "Stage.h"
#include"Door.h"
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
	//�� Defualt�� �ؾ� ��ġ�� ���� ������ �� �����ΰ��ΰ�
	//����Ʈ �����ϴ°���ü�� �ڽ��� ���͸� ������ ���̰� �� ���͸� �������� ��ġ�������� 
	//�� �������� �ű� �ڸ��� �ᱹ 0,0 �� �Ǵ°��̴�. 
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
	LeftLightButton->SetupAttachment(Defualt); // ������Ʈ ��ġ�� �����ͼ� �ű⼭ �Ʒ��� �����ٴ� ����
	LeftLightButton->SetCollisionGroup(OrderType::Object);
	LeftLightButton->SetCollisionType(ECollisionType::Rect);
	LeftLightButton->SetOrder(OrderType::Object);
	LeftLightButton->SetScale(FVector{ 50,50 });
	LeftLightButton->SetPosition(FVector{ -760,-70 });
	

	
	RightButtonRender = CreateDefaultSubObject<USpriteRenderer>("RightButtonRender");
	RightButtonRender->SetSprite("Button.png",4);
	RightButtonRender->SetPosition(FVector{ 300,-20 });
	RightButtonRender->SetAutoSize(1.0f, true);
	RightButtonRender->SetOrder(OrderType::Object);
	RightButtonRender->SetPosition(FVector{ 740,-20 });
	RightButtonRender->SetupAttachment(Defualt);



	RightDoorButton = CreateDefaultSubObject<UCollision>("RightDoorButton");
	RightDoorButton->SetupAttachment(Defualt);
	RightDoorButton->SetCollisionGroup(OrderType::Object);
	RightDoorButton->SetCollisionType(ECollisionType::Rect);
	RightDoorButton->SetScale(FVector{ 50,50 });
	RightDoorButton->SetPosition(FVector{ 740,30 });
	RightDoorButton->SetOrder(OrderType::Object);



	RightLightButton = CreateDefaultSubObject<UCollision>("RightLightButton");
	RightLightButton->SetupAttachment(Defualt); // ������Ʈ ��ġ�� �����ͼ� �ű⼭ �Ʒ��� �����ٴ� ����
	RightLightButton->SetCollisionGroup(OrderType::Object);
	RightLightButton->SetCollisionType(ECollisionType::Rect);
	RightLightButton->SetOrder(OrderType::Object);
	RightLightButton->SetScale(FVector{ 50,50 });
	RightLightButton->SetPosition(FVector{ 740,-65 });
	
	

	SetRoot(Defualt);

}
Button::~Button()
{


}
void Button::BeginPlay()
{

	Super::BeginPlay();
	MainButton = this;
	
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
		if (LeftLight == true && LeftDoor == false)
		{
			LeftButtonRender->SetSprite("Button.png", 0);
			LeftLight = false;
			//����Ʈ�� �����ְ� ���� ���� ������
		}
		else if (LeftLight == true && LeftDoor == true)
		{
			LeftButtonRender->SetSprite("Button.png", 2);
			LeftLight = false;
			//����Ʈ�� �����ְ� ���� ���������� 

		}



		if (LeftDoor == true)
		{
			LeftButtonRender->SetSprite("Button.png", 3);
			LeftLight = true; 
			return;
			//���� ����������
		}
		
		LeftButtonRender->SetSprite("Button.png",1);
		LeftLight = true;
		//�ƹ��͵� �ƴѻ����϶�

	}
	else if(_ButtonName._Equal("RightLightButton"))
	{

		RightButtonRender->SetSprite("Button.png", 7);
		RightLight = true;
		
	}
	
}

void Button::ButtonDoor(std::string _ButtonName )
{
	
	
	if (_ButtonName._Equal("LeftDoorButton"))
	{

		if (LeftLight == true)
		{
			if (LeftDoor == true)
			{
				LeftButtonRender->SetSprite("Button.png", 1);
				LeftDoor = false;
				return;
			}
			LeftButtonRender->SetSprite("Button.png", 3);
			//����Ʈ�� ���������� ���� ������ 
			LeftDoor = true;

		}

		if (LeftLight == false)
		{
			if (LeftDoor == true)
			{
				LeftButtonRender->SetSprite("Button.png", 0);
				LeftDoor = false;
				return;
			}
			LeftButtonRender->SetSprite("Button.png", 2);
			LeftDoor = true;
			//����Ʈ�� ���� ���·� �������� 
		}


		


	}

	
}
void Button::MoveButton(FVector _SetPos)
{
	SetActorLocation(_SetPos);



}

