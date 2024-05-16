#include "PreCompile.h"
#include "MainTitleLevel.h"
#include "TitleBackGround.h"
#include <EngineCore/Camera.h>
#include <EnginePlatform/EngineInput.h>
#include "Stage.h"
#include"Mouse.h"
#include"Noise.h"
#include"TitleBackGround.h"
#include<EnginePlatform/EngineSound.h>
#include"MyCore.h"



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
	TitleBack = GetWorld()->SpawnActor<TitleBackGround>("TitleBackGround",5);
	GetWorld()->SpawnActor<Noise>("Noise", 10);
	GetWorld()->SpawnActor<Mouse>("Mouse", 100);
	
	StartButton = CreateWidget<UImage>(GetWorld(),"StartButtonUI");
	StartButton->SetSprite("TitleNewGame.png");
	StartButton->SetAutoSize(1.0f, true);
	StartButton->AddToViewPort(2);
	StartButton->SetPosition(FVector{ -350.0f,-50.0f });



	TitleSound = UEngineSound::SoundPlay("TitleMusic.wav");
	TitleSound.SetVolume(0.4f);
	TitleSound.Loop();
	

	StartButton->SetDown([=]
		{
			TitleSound.Off();
			GEngine->ChangeLevel("StageLevel");
		});
}

void MainTitleLevel::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (true == UEngineInput::IsDown('P'))
	{
		GEngine->ChangeLevel("StageLevel");
	}

}

void MainTitleLevel::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void MainTitleLevel::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

}


void MainTitleLevel::SetTitleSound()
{
	if (true == this->IsActive())
	{

		TitleSound.On();

	}
	else
	{
		TitleSound.Off();
	}
}