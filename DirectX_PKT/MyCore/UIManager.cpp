#include "PreCompile.h"
#include "UIManager.h"
#include<EngineCore/Camera.h>
#include<EngineCore/EngineDebugMsgWindow.h>
#include"MyCore.h"

UIManager::UIManager()
{
}

UIManager::~UIManager()
{
}
void UIManager::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetMainCamera();

	
}

void UIManager::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	

}

