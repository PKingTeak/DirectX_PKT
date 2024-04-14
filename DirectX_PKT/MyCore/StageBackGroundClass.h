#pragma once

#include<EngineCore/Actor.h>
#include<EngineCore/Renderer.h>
#include<EngineCore/SpriteRenderer.h>
class StageBackGroundClass : public AActor
{
	GENERATED_BODY(AActor)
public:
	StageBackGroundClass();
	~StageBackGroundClass();

	// delete Function
	StageBackGroundClass(const StageBackGroundClass& _Other) = delete;
	StageBackGroundClass(StageBackGroundClass&& _Other) noexcept = delete;
	StageBackGroundClass& operator=(const StageBackGroundClass& _Other) = delete;
	StageBackGroundClass& operator=(StageBackGroundClass&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();
private:
	
	USpriteRenderer* Renderer = nullptr;
	USpriteRenderer* StageBackRender = nullptr;
	USpriteRenderer* StageUIRenderer = nullptr;

};

