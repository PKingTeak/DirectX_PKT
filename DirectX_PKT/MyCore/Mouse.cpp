#include "PreCompile.h"
#include "Mouse.h"
#include<EngineCore/Collision.h>
#include<EngineCore/Camera.h>
#include<EngineCore/DefaultSceneComponent.h>
#include<string.h>
#include"StageBackGroundClass.h"
#include<EnginePlatform/EngineInput.h>
#include"Button.h"
#include"Door.h"
#include"Stage.h"

Mouse::Mouse()
{


	MouseCollision = CreateDefaultSubObject<UCollision>("MouseCollision");
	//MouseCollision->SetupAttachment(MouseCollision);
	MouseCollision->SetScale(FVector{ 50,50 });
	MouseCollision->SetCollisionGroup(OrderType::Mouse);
	MouseCollision->SetCollisionType(ECollisionType::Rect);
	MouseCollision->SetOrder(OrderType::Mouse);

	MSprite = CreateDefaultSubObject<USpriteRenderer>("MouseRender");
	MSprite->SetupAttachment(MouseCollision);
	MSprite->SetOrder(100);
	//MSprite->SetSprite("Arrow.png");

	SetRoot(MouseCollision);

	// �̰� �� �ȵ��� ������ �𸣰ڽ��ϴ�.
}

Mouse::~Mouse()
{
}
void Mouse::BeginPlay()
{

	Super::BeginPlay();
	MainStage = dynamic_cast<Stage*>(GetWorld()->GetGameMode().get());


	//StageBackGround->GetMainStageBackGround();

}

void Mouse::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	SetMousePos();
	MouseCollision->CollisionStay(OrderType::Object, [=](std::shared_ptr<UCollision>_Collision)
		{

			std::string objectType = _Collision->GetName(); // �̰ɷ� �ؾ� collsion�� �о�ü� �ִ�. 
			if (objectType._Equal("LeftDoorButton"))
			{
				if (UEngineInput::IsDown(VK_LBUTTON))
				{
					//Door �ϳ� ���ͷ� ���� ����ؾߵɵ� �ϴ�. 
					ButtonClass->GetMainButton()->ButtonDoor(objectType);

					if (ButtonClass->GetMainButton()->LDoorButtonCheck() == true)
					{

						DoorActor = MainStage->GetStageDoor();
						DoorActor->DoorOpen(objectType);
					}
				
				}

				int a = 0;

			}
			if (objectType._Equal("LeftLightButton"))
			{
				if (UEngineInput::IsDown(VK_LBUTTON))
				{

					StageBackGround->GetMainStageBackGround()->ChangeBackGround("LeftLightButton");
					ButtonClass->GetMainButton()->ButtonLight(objectType);
				}


			}




		}
	);







}

void Mouse::SetMousePos()
{
	FVector CamPos = GetWorld()->GetMainCamera()->GetActorLocation();
	FVector MPos = GEngine->EngineWindow.GetScreenMousePos();
	FVector WindowScale = GEngine->EngineWindow.GetWindowScale();
	FVector TargetPos = FVector(CamPos.X, CamPos.Y, 0.0f) + FVector(MPos.X - WindowScale.hX(), -(MPos.Y - WindowScale.hY()), 0.0f);
	//���콺 ������ �ϴ� �浹ü�� ���� ����Ұ�
	SetActorLocation(TargetPos);


}

void Mouse::MouseActive()
{


}

void Mouse::MouseClick(OrderType _OrderType)
{

}

