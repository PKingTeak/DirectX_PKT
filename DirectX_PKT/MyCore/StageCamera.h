#pragma once
#include <EngineCore/Actor.h>
#include<EngineCore/SpriteRenderer.h>
#include<EngineCore/Collision.h>

// Ό³Έν :
class StageCamera : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	StageCamera();
	~StageCamera();

	// delete Function
	StageCamera(const StageCamera& _Other) = delete;
	StageCamera(StageCamera&& _Other) noexcept = delete;
	StageCamera& operator=(const StageCamera& _Other) = delete;
	StageCamera& operator=(StageCamera&& _Other) noexcept = delete;


	void ChangeAnimation();
	
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();
private:
	USpriteRenderer* StageCameraRender = nullptr;
	
	

};

