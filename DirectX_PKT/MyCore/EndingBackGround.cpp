#include "PreCompile.h"
#include "EndingBackGround.h"
#include <EngineBase/EngineRandom.h>

EndingBackGround::EndingBackGround()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	SetRoot(Renderer);
}

EndingBackGround::~EndingBackGround()
{
}


void EndingBackGround::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(1280.0f, 720.0f, 100.0f));



}

void EndingBackGround::Tick(float _DeltaTime)
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

void EndingBackGround::ChangeBackGround(float _DeltaTime)
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

