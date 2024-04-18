#include "PreCompile.h"
#include "Arrow.h"
#include<EngineCore/Collision.h>
#include"MyCore.h"
#include<EngineCore/DefaultSceneComponent.h>

Arrow::Arrow() 
{
	

	//UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");


	ArrowRender = CreateDefaultSubObject<USpriteRenderer>("ArrowRender");
	ArrowRender->SetSprite("Arrow.png");
	ArrowRender->AddPosition({ 0,0,0 });
	ArrowRender->SetAutoSize(1.0f, true);
	ArrowRender->SetOrder(2000);


	ArrowCollision = CreateDefaultSubObject<UCollision>("ArrowCollision");
	//ArrowCollision->SetScale(ArrowRender->GetLocalScale());
	ArrowCollision->SetCollisionGroup(OrderType::UI);
	ArrowCollision->SetCollisionType(ECollisionType::Rect);
	ArrowCollision->SetupAttachment(ArrowRender);

	//TestRender = CreateDefaultSubObject<USpriteRenderer>("TestRender");
	//TestRender->SetSprite("Noise.png");
	//TestRender->AddPosition({0,0});
	//TestRender->SetOrder(15);
	//TestRender->SetupAttachment(ArrowRender);

	//Actor의 위치를 기준으로 모두가 그걸 중심으로 움직인게 된다. 

	SetRoot(ArrowRender);
}

Arrow::~Arrow() 
{
}
void Arrow::BeginPlay()
{
	Super::BeginPlay();
	this->SetActorLocation({ 0,-320,0 });
	//StageCam->ChangeAnimation();

	//std::shared_ptr<StageCamera> Actor = GetWorld()->SpawnActor<StageCamera>("StageCamera");
	//Actor->ChangeAnimation();

} 
void Arrow::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
void Arrow::ChangeCam()
{
	StageCam = GetWorld()->SpawnActor<StageCamera>("StageCamera");
	StageCam->ChangeAnimation();
	
	if (true == isCamOpen)
	{
		StageCam->SetActive(false);
		isCamOpen = false;

	}
	else
	{
		isCamOpen = true;
		//함수 넣기 
	}
	
	
	

	
	//Actor->
	//ChangeLevel == 여기서 카메라 감시 하는 부분으로 변경해주는것이 좋을거 같다. 


}