#include "PreCompile.h"
#include "Stage.h"
#include<EngineCore/Camera.h>

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
	//GetWorld()->SpawnActor<> \¼±Ç³±â

}

void Stage::Tick(float _DetaTIme)
{
	Super::Tick(_DetaTIme);

}

void Stage::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void Stage::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

}
