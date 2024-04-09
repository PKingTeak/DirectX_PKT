#include "PreCompile.h"
#include "TitleBackGround.h"
#include <EngineBase/EngineRandom.h>

TitleBackGround::TitleBackGround()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");

}

TitleBackGround::~TitleBackGround()
{
}


void TitleBackGround::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(1280.0f, 720.0f, 100.0f));


	
	//Renderer->CreateAnimation("TitleAnimation", "TITLE.png", 1, 4);
	
	//Renderer->ChangeAnimation("TitleAnimation");
}

void TitleBackGround::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	AniTime -= _DeltaTime;
	ChangeBackGround();
	int a = 0;
}

void TitleBackGround::ChangeBackGround()
{
	
	if (AniTime > 0)
	{
	Renderer->SetSprite( "Title.png", 0);
	}
	else if (AniTime < 0)
	{
		int RandomNum = UEngineRandom::MainRandom.RandomInt(0, 3);
		Renderer->SetSprite("Title.png", RandomNum);
		AniTime = RandomNum * 5;
	}
	int a = 0;
}

