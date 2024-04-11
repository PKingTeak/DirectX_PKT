#include "PreCompile.h"
#include "MainTitleLevel.h"
#include "TitleBackGround.h"
#include <EngineCore/Camera.h>
#include <EnginePlatform/EngineInput.h>
#include "Stage.h"

#include"Noise.h"

MainTitleLevel::MainTitleLevel()
{
	
	
}
	

MainTitleLevel::~MainTitleLevel()
{
}

void MainTitleLevel::BeginPlay()
{
	Super::BeginPlay();
	
	UEngineSprite::CreateCutting("TITLE.png", 1, 4);
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<TitleBackGround>("TitleBackGround",5);
	GetWorld()->SpawnActor<Noise>("Noise", 10);
	
}

void MainTitleLevel::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (true == UEngineInput::IsDown('P'))
	{
		GEngine->ChangeLevel("StageLevel");
	}
//if (true == UEngineInput::IsDown('P'))
//{
//	GEngine->ChangeLevel("PlayLevel");
//}
}

void MainTitleLevel::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void MainTitleLevel::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

}