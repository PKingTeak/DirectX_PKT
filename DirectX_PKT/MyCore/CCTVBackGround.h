#pragma once
#include <EngineCore/Actor.h>
#include<EngineCore/SpriteRenderer.h>
#include<EngineCore/Collision.h>

// Ό³Έν :
class CCTVBackGround : public AActor
{
	GENERATED_BODY(AActor)
private:
	static CCTVBackGround* MainCCTV;
	



	

public:
	// constrcuter destructer
	CCTVBackGround();
	~CCTVBackGround();

	// delete Function
	CCTVBackGround(const CCTVBackGround& _Other) = delete;
	CCTVBackGround(CCTVBackGround&& _Other) noexcept = delete;
	CCTVBackGround& operator=(const CCTVBackGround& _Other) = delete;
	CCTVBackGround& operator=(CCTVBackGround&& _Other) noexcept = delete;

	static CCTVBackGround* GetCCTVBackGround();
	
	void CCTVON();
	void CCTVOFF();
	inline bool GetCamMode()
	{
		return CamMode;
	}
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();
private:
	USpriteRenderer* CCTVBackGroundRender = nullptr;
	bool CamMode;





};

