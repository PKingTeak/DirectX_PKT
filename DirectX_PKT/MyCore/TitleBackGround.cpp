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

	SetActorScale3D(FVector(700.0f, 300.0f, 100.0f));


	
	//Renderer->CreateAnimation("TitleAnimation", "TITLE.png", 1, 4);
	int RandomNum = UEngineRandom::MainRandom.RandomInt(0,3);
	Renderer->SetSprite("TITLE.png", RandomNum);
	//Renderer->ChangeAnimation("TitleAnimation");
}

void TitleBackGround::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
	int a = 0;
}
