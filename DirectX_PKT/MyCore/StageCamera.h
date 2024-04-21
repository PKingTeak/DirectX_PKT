#pragma once
#include <EngineCore/Actor.h>
#include<EngineCore/SpriteRenderer.h>
#include<EngineCore/Collision.h>
#include<string_view>
#include"CCTVBackGround.h"
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
	inline bool GetIsCameraOn()
	{
		return isCamOn;
	}



protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();
private:
	USpriteRenderer* StageCameraRender = nullptr;
	USpriteRenderer* CCTVCam = nullptr;
	bool isCamOn = false;

	
	

	

};

