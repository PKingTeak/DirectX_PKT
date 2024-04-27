#pragma once
#include <EngineCore/Actor.h>
#include<EngineCore/SpriteRenderer.h>
#include<EngineCore/Collision.h>
#include"StageCamera.h"
#include<EngineCore/Image.h>
// Ό³Έν :

class ScanLine : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ScanLine();
	~ScanLine();

	// delete Function
	ScanLine(const ScanLine& _Other) = delete;
	ScanLine(ScanLine&& _Other) noexcept = delete;
	ScanLine& operator=(const ScanLine& _Other) = delete;
	ScanLine& operator=(ScanLine&& _Other) noexcept = delete;

	void ScanLineLoad();
	
	inline ScanLine* GetScanLine()
	{
		return this;
	}


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();


private:
	UImage* ScanLineUIImage = nullptr;
	USpriteRenderer* ScanLineRender = nullptr;
};

