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

 // 이거 왜 안따라 가는지 모르겠습니다.
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
			
			std::string objectType = _Collision->GetName(); // 이걸로 해야 collsion을 읽어올수 있다. 
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
	//마우스 역할을 하는 충돌체를 만들어서 사용할것
	SetActorLocation(TargetPos);
	

}

void Mouse::MouseActive()
{
	

}

void Mouse::MouseClick(OrderType _OrderType)
{
	
}

