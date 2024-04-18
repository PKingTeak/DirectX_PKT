#pragma once
#include<EngineCore/GameMode.h>
#include<EngineCore/SpriteRenderer.h>
#include<EngineCore/Widget.h>
#include<EngineCore/GameMode.h>
#include<EngineCore/Image.h>
#include"StageCamera.h"
// Ό³Έν :
class UIManager : public AGameMode
{
	GENERATED_BODY(AGameMode)

public:
	
	UIManager();
	~UIManager();

	// delete Function
	UIManager(const UIManager& _Other) = delete;
	UIManager(UIManager&& _Other) noexcept = delete;
	UIManager& operator=(const UIManager& _Other) = delete;
	UIManager& operator=(UIManager&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImage* ArrowUi = nullptr;
	

};

