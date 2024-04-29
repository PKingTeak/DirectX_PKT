#pragma once
#include <EngineCore/Actor.h>
#include<EngineCore/SpriteRenderer.h>
#include<EngineCore/Collision.h>
#include<string_view>
#include"CCTVBackGround.h"
// 설명 :
class CCTVBackGround;
class Stage;
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


	void CamCCTVOn();
	void CamCCTVOff();
	inline bool GetIsCameraOn()
	{
		//CCTV카메라 켜져있는지 채크하는 함수
		return isCamOn;
	}



protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();
private:
	Stage* StageLevel = nullptr;
	std::shared_ptr<CCTVBackGround> CCTVBackGrounds = nullptr;
	USpriteRenderer* StageCameraRender = nullptr;
	USpriteRenderer* CCTVCam = nullptr;
	bool isCamOn = false;

	
	

	

};

