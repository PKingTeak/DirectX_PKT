#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include<iostream>
#include<string>
#include<string_view>
#include<EngineCore/DefaultSceneComponent.h>

// Ό³Έν :
class EndingBackGround : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	EndingBackGround();
	~EndingBackGround();

	// delete Function
	EndingBackGround(const EndingBackGround& _Other) = delete;
	EndingBackGround(EndingBackGround&& _Other) noexcept = delete;
	EndingBackGround& operator=(const EndingBackGround& _Other) = delete;
	EndingBackGround& operator=(EndingBackGround&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();

private:
	void ChangeBackGround(float _DeltaTime);
	USpriteRenderer* Renderer = nullptr;
	USpriteRenderer* GameOverRenderer = nullptr;
	USpriteRenderer* GameOvertext = nullptr;
	bool isAnimationEnd = false;

};

