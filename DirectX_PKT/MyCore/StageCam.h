#pragma once
#include <EngineCore/Actor.h>
#include<EngineCore/SpriteRenderer.h>
#include<EngineCore/Collision.h>
#include"MyCore.h"
// Ό³Έν :
class StageCam : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	StageCam();
	~StageCam();

	// delete Function
	StageCam(const StageCam& _Other) = delete;
	StageCam(StageCam&& _Other) noexcept = delete;
	StageCam& operator=(const StageCam& _Other) = delete;
	StageCam& operator=(StageCam&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void RendererOff();
	void RendererOn();
private:
	USpriteRenderer* CameraRender = nullptr;
};

