#pragma once
#include <EngineCore/Actor.h>
#include<EngineCore/SpriteRenderer.h>
#include<EngineCore/Collision.h>
#include"Noise.h"

class Stage;
// ���� :
class CCTVBackGround : public AActor
{
	GENERATED_BODY(AActor)
private:
	



	

public:
	// constrcuter destructer
	CCTVBackGround();
	~CCTVBackGround();

	// delete Function
	CCTVBackGround(const CCTVBackGround& _Other) = delete;
	CCTVBackGround(CCTVBackGround&& _Other) noexcept = delete;
	CCTVBackGround& operator=(const CCTVBackGround& _Other) = delete;
	CCTVBackGround& operator=(CCTVBackGround&& _Other) noexcept = delete;

	CCTVBackGround* GetCCTVBackGround();
	
	void CCTVON();
	void CCTVOFF();
	void StartScanLine();
	inline bool GetCamMode()
	{
		return CamMode;
	}
	void ChangeCam(std::string _UICamName);
	void ScanLineON();
	



protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();
private:
	
	USpriteRenderer* CCTVBackGroundRender = nullptr;
	USpriteRenderer* CCTVEffect = nullptr;
	USpriteRenderer* ChangeEffect = nullptr;
	bool CamMode;
	bool ScanAniEnd = false;

	Stage* StageLevel = nullptr;
	std::shared_ptr<Noise> NoiseEffect = nullptr;

	void ScanLineEffect();
	



};

