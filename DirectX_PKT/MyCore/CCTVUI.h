#pragma once
#include <EngineCore/Actor.h>
#include<EngineCore/SpriteRenderer.h>
#include<EngineCore/Collision.h>
#include"StageCamera.h"
#include<EngineCore/Image.h>
// Ό³Έν :

class CCTVUI : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	CCTVUI();
	~CCTVUI();

	// delete Function
	CCTVUI(const CCTVUI& _Other) = delete;
	CCTVUI(CCTVUI&& _Other) noexcept = delete;
	CCTVUI& operator=(const CCTVUI& _Other) = delete;
	CCTVUI& operator=(CCTVUI&& _Other) noexcept = delete;

	void CCTVUILoad();
	
	inline CCTVUI* GetCCTVUI()
	{
		return this;
	}


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();


private:
	UImage* CCTVUIImage = nullptr;
	
};

