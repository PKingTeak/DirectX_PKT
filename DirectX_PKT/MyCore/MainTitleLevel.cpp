#include "PreCompile.h"
#include "MainTitleLevel.h"
#include "TitleBackGround.h"
#include <EngineCore/Camera.h>
#include <EnginePlatform/EngineInput.h>

MainTitleLevel::MainTitleLevel()
{
	
	
}
	

MainTitleLevel::~MainTitleLevel()
{
}

void MainTitleLevel::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<TitleBackGround>("TitleBackGround");
	
}

void MainTitleLevel::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

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