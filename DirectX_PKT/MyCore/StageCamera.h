#pragma once
#include <EngineCore/Actor.h>
#include<EngineCore/SpriteRenderer.h>
#include<EngineCore/Collision.h>
#include<string_view>
// ���� :
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
	void StageChangeLevel(std::string_view _LevelName);
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();
private:
	USpriteRenderer* StageCameraRender = nullptr;
	USpriteRenderer* CCTVCam = nullptr;
	

	

};

