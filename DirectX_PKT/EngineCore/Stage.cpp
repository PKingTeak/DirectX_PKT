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
	//GetWorld()->SpawnActor<> \��ǳ��

}

void Stage::Tick(float _DetaTIme)
{
	Super::Tick(_DetaTIme);

}
