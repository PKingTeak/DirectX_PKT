#include "PreCompile.h"
#include "EndingBackGround.h"
#include <EngineBase/EngineRandom.h>
#include"MyCore.h"
EndingBackGround::EndingBackGround()
{
	UDefaultSceneComponent* Default = CreateDefaultSubObject<UDefaultSceneComponent>("EndDefault");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Default);
	Renderer->SetAutoSize(1.0f, true);
	Renderer->SetOrder(OrderType::BackGround);
	Renderer->CreateAnimation("EndingNoiseAni", "EndingNoise", 0.1f, false,0,7);

	GameOverRenderer = CreateDefaultSubObject<USpriteRenderer>("GameOverRenderer");
	GameOverRenderer->SetupAttachment(Default);
	GameOverRenderer->SetSprite("GameOverBackground.png");
	GameOverRenderer->SetAutoSize(1.0f, true);
	GameOverRenderer->SetOrder(OrderType::BackGround);

	GameOvertext = CreateDefaultSubObject<USpriteRenderer>("GameOvertext");
	GameOvertext->SetupAttachment(Default);
	GameOvertext->SetSprite("GameOverText.png");
	GameOvertext->SetAutoSize(1.0f, true);
	GameOvertext->AddPosition(FVector{ 0,100 });
	GameOvertext->SetOrder(OrderType::Object);
	GameOvertext->SetActive(false);

	SetRoot(Default);
}

EndingBackGround::~EndingBackGround()
{
}


void EndingBackGround::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector{ 0,0 });
	

	Renderer->ChangeAnimation("EndingNoiseAni");
	

	Renderer->SetLastFrameCallback("EndingNoiseAni", [=]

		{
			Renderer->SetActive(false);
			GameOverRenderer->SetActive(true);
			GameOvertext->SetActive(true);
		}
	);
	
}

void EndingBackGround::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}


