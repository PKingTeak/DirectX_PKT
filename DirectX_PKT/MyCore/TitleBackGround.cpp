#include "PreCompile.h"
#include "TitleBackGround.h"
#include <EngineBase/EngineRandom.h>
#include <EngineCore/DefaultSceneComponent.h>
#include<EngineCore/Image.h>
TitleBackGround::TitleBackGround()
{

	UDefaultSceneComponent* Default = CreateDefaultSubObject<UDefaultSceneComponent>("Default");
	Default->SetPosition(FVector{ 0,0 });

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Default);
	Renderer->SetOrder(1);
	
	TitleText = CreateDefaultSubObject<USpriteRenderer>("GameTitle");
	TitleText->SetupAttachment(Default);
	
	


	SetRoot(Default);
}

TitleBackGround::~TitleBackGround()
{
	
}


void TitleBackGround::BeginPlay()
{
	Super::BeginPlay();
	SetActorScale3D(FVector(1280.0f, 720.0f, 100.0f));
	
	TitleText->SetSprite("TitleName.png");
	TitleText->SetAutoSize(1.0f, true);
	TitleText->SetOrder(5);
	TitleText->SetPosition(FVector{ 0.0f,0.0f,10.0f });
	
	
}

void TitleBackGround::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	AniTime -= _DeltaTime;
	if (AniTime >= 0)
	{
		Renderer->SetSprite("Title.png", 0);
		RandomNum = UEngineRandom::MainRandom.RandomInt(1, 3);
	}
	if (AniTime < 0)
	{
	ChangeBackGround(_DeltaTime);
	}
	int a = 0;
}

void TitleBackGround::ChangeBackGround(float _DeltaTime)
{//랜덤으로 배경 화면 바꾸기 
	//DelayCallBack()
	Time += _DeltaTime;
	Renderer->SetSprite("Title.png", RandomNum);
	if (Time > 1)
	{
	AniTime = RandomNum * 2;
	Time = 0;
	}
}

