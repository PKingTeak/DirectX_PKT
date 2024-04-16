#include "PreCompile.h"
#include "CamLevel.h"
#include<EngineCore/Camera.h>
#include<EngineCore/EngineDebugMsgWindow.h>
#include<EngineCore/DefaultSceneComponent.h>
#include"MyCore.h"
#include"Mouse.h"
#include"CCTVBackGround.h"
#include "StageCamera.h"
CamLevel::CamLevel()
{

}

CamLevel::~CamLevel()
{
}


void CamLevel::BeginPlay()
{
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<CCTVBackGround>("CCTVBackGround");
}

void CamLevel::Tick(float _DetaTIme)
{
	Super::Tick(_DetaTIme);

	
}


void CamLevel::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void CamLevel::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

}
