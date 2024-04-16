#include "PreCompile.h"
#include "UILevel.h"
#include<EngineCore/Camera.h>
#include<EngineCore/EngineDebugMsgWindow.h>
#include"Fan.h"
#include"MyCore.h"
#include"Mouse.h"
UILevel::UILevel()
{
}

UILevel::~UILevel()
{
}


void UILevel::BeginPlay()
{
}

void UILevel::Tick(float _DetaTIme)
{
	Super::Tick(_DetaTIme);



}


void UILevel::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void UILevel::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

}
