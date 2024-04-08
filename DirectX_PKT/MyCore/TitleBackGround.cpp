#include "PreCompile.h"
#include "TitleBackGround.h"

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


	
	Renderer->CreateAnimation("TitleAnimation", "TITLE.png", 1, 4);
	Renderer->ChangeAnimation("TitleAnimation");
}

void TitleBackGround::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	int a = 0;
}
