#include "PreCompile.h"
#include "Mouse.h"
#include<EngineCore/Collision.h>
#include<EngineCore/Camera.h>
#include<EngineCore/DefaultSceneComponent.h>
#include<string.h>
#include"StageBackGroundClass.h"
#include<EnginePlatform/EngineInput.h>
#include"Button.h"

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
	MSprite->SetSprite("Arrow.png");

	SetRoot(MouseCollision);

 // �̰� �� �ȵ��� ������ �𸣰ڽ��ϴ�.
}

Mouse::~Mouse()
{
}
void Mouse::BeginPlay()
{

	Super::BeginPlay();
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
				

				int a = 0;

			}
			if (objectType._Equal("LeftLightButton"))
			{
				if (UEngineInput::IsDown(VK_LBUTTON))
				{

				StageBackGround->GetMainStageBackGround()->ChangeBackGround();
				ButtonClass->GetMainButton()->ButtonLight(objectType);
				}
				int a = 0;
			
				
			}

			
		}
	);
		

	

	


}

void Mouse::SetMousePos()
{
	FVector CamPos = GetWorld()->GetMainCamera()->GetActorLocation();
	FVector MPos = GEngine->EngineWindow.GetScreenMousePos();
	FVector WindowScale = GEngine->EngineWindow.GetWindowScale();
	FVector TargetPos = FVector(CamPos.X, CamPos.Y, 0.0f) + FVector(MPos.X - WindowScale.hX(),- (MPos.Y - WindowScale.hY()), 0.0f);
	//���콺 ������ �ϴ� �浹ü�� ���� ����Ұ�
	SetActorLocation(TargetPos);
	

}

void Mouse::MouseActive()
{
	

}

void Mouse::MouseClick(OrderType _OrderType)
{
	
}

