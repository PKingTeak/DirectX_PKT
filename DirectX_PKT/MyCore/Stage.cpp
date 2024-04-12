#include "PreCompile.h"
#include "Stage.h"
#include<EngineCore/Camera.h>
#include"StageBackGroundClass.h"
#include"Fan.h"
#include"MyCore.h"
Stage::Stage()
{
}

Stage::~Stage()
{
}


void Stage::BeginPlay()
{
	Super::BeginPlay();
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -50.0f));
	GetWorld()->SpawnActor<StageBackGroundClass>("StageBackGroundClass");
	GetWorld()->SpawnActor<Fan>("Fan", 10);
	

}

void Stage::Tick(float _DetaTIme)
{
	Super::Tick(_DetaTIme);
	//DebugGUI();
}

void Stage::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void Stage::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

}
