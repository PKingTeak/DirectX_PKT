#pragma once
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/GameMode.h>
#include<iostream>

class Noise;
class EndingLevel : public AGameMode
{
	GENERATED_BODY(AGameMode)

public:
	// constrcuter destructer
	EndingLevel();
	~EndingLevel();

	// delete Function
	EndingLevel(const EndingLevel& _Other) = delete;
	EndingLevel(EndingLevel&& _Other) noexcept = delete;
	EndingLevel& operator=(const EndingLevel& _Other) = delete;
	EndingLevel& operator=(EndingLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();

private:
	
	void EndingNoiseChecker();
	USpriteRenderer* Renderer = nullptr;
	int RandomNum = 0;
	float  AniTime = 2;
	float Time = 0;

};

