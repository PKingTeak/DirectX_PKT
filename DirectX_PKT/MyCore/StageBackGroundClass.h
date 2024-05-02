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

	
	void LightOn(std::string _Dir);
	void ChangeBackGround(std::string _RoomState);
	void PlayJumpScare(std::string _Name);
	
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();
private:
	std::vector<AActor> UIInfo;
	USpriteRenderer* JumpScare = nullptr;
	USpriteRenderer* StageBackRender = nullptr;
	
	bool ColDir = false;
	float Time = 0.0;
	bool LeftLight = false;
	bool RightLight = false;
	

};

