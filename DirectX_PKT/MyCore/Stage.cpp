#include "PreCompile.h"
#include "Stage.h"
#include<EngineCore/Camera.h>
#include"StageBackGroundClass.h"
#include"Fan.h"
#include"MyCore.h"
#include<EngineCore/EngineDebugMsgWindow.h>
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
	GetWorld()->SpawnActor<Fan>("Fan");
	GetWorld()->SpawnActor<StageBackGroundClass>("StageBackGroundClass");
	
	
}

void Stage::Tick(float _DetaTIme)
{
	Super::Tick(_DetaTIme);
	DebugGUI();
	//DebugGUI();
}
void Stage::DebugGUI()
{
	{
		std::string Msg = std::format("MousePos : {}\n", GEngine->EngineWindow.GetScreenMousePos().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

}

void Stage::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void Stage::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

}
