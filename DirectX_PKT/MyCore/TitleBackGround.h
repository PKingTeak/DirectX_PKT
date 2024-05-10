#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include<iostream>
#include<string>
#include<string_view>
#include<EngineCore/Image.h>
#include<EngineCore/DefaultSceneComponent.h>
// Ό³Έν :
class TitleBackGround : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	TitleBackGround();
	~TitleBackGround();

	// delete Function
	TitleBackGround(const TitleBackGround& _Other) = delete;
	TitleBackGround(TitleBackGround&& _Other) noexcept = delete;
	TitleBackGround& operator=(const TitleBackGround& _Other) = delete;
	TitleBackGround& operator=(TitleBackGround&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();

private:
	
	void ChangeBackGround(float _DeltaTime);
	USpriteRenderer* Renderer = nullptr;
	USpriteRenderer* TitleText = nullptr;
	int RandomNum = 0;
	float  AniTime = 2;
	float Time = 0;

};

