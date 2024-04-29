#pragma once

#include<EngineCore/Actor.h>
#include<EngineCore/Renderer.h>
#include<EngineCore/SpriteRenderer.h>
#include<iostream>
#include"Arrow.h"

class ScanLine;
class StageBackGroundClass : public AActor
{
	
private:
	static StageBackGroundClass* MainStageBackGround;
	GENERATED_BODY(AActor)
public:
	StageBackGroundClass();
	~StageBackGroundClass();

	// delete Function
	StageBackGroundClass(const StageBackGroundClass& _Other) = delete;
	StageBackGroundClass(StageBackGroundClass&& _Other) noexcept = delete;
	StageBackGroundClass& operator=(const StageBackGroundClass& _Other) = delete;
	StageBackGroundClass& operator=(StageBackGroundClass&& _Other) noexcept = delete;

	StageBackGroundClass* GetMainStageBackGround();
	
	void ChangeBackGround();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();
private:
	int DelayTime = 0;
	std::vector<AActor> UIInfo;
	USpriteRenderer* Renderer = nullptr;
	USpriteRenderer* StageBackRender = nullptr;
	
	bool ColDir = false;
	
	
	

};

