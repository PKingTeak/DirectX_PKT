#pragma once
#include <EngineCore/GameMode.h>
#include<EngineCore/SpriteRenderer.h>
#include<EngineCore/Image.h>

// Ό³Έν :
class TitleBackGround;
class MainTitleLevel : public AGameMode
{
	GENERATED_BODY(AGameMode)

public:
	// constrcuter destructer
	MainTitleLevel();
	~MainTitleLevel();

	// delete Function
	MainTitleLevel(const MainTitleLevel& _Other) = delete;
	MainTitleLevel(MainTitleLevel&& _Other) noexcept = delete;
	MainTitleLevel& operator=(const MainTitleLevel& _Other) = delete;
	MainTitleLevel& operator=(MainTitleLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);

private:
	void SetTitleSound();
	std::shared_ptr<TitleBackGround> TitleBack = nullptr;
	UImage* StartButton = nullptr;
	UImage* ExitButton = nullptr;

	UEngineSoundPlayer TitleSound;
//	USpriteRenderer* Renderer = nullptr;
	
};

