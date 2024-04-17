#include "PreCompile.h"
#include "Mouse.h"
#include<EngineCore/Collision.h>
#include<EngineCore/Camera.h>
#include<EngineCore/DefaultSceneComponent.h>
#include<string.h>

Mouse::Mouse()
{


	MouseCollision = CreateDefaultSubObject<UCollision>("MouseCollision");
	//MouseCollision->SetupAttachment(MouseCollision);
	MouseCollision->SetScale(FVector{ 50,50 });
	MouseCollision->SetCollisionGroup(OrderType::Mouse);
	MouseCollision->SetCollisionType(ECollisionType::CirCle);

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
	
}
	
void Mouse::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	SetMousePos();

	MouseCollision->CollisionEnter(OrderType::UI, [=](std::shared_ptr<UCollision>_Collision)
		{
			std::string objectType = _Collision->GetActor()->GetName();

			if ("Arrow" == _Collision->GetActor()->GetName())
			{
				int b  = _Collision->GetActor()->GetOrder();
				std::shared_ptr<Arrow> Actor = GetWorld()->SpawnActor<Arrow>("Arrow");
				Actor->ChangeCam();
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

