#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include<EngineCore/DefaultSceneComponent.h>
#include<iostream>
#include "RoomManager.h"
class Animatronics;

// Ό³Έν :
class HallDining : public RoomManager
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	HallDining();
	~HallDining();

	// delete Function
	HallDining(const HallDining& _Other) = delete;
	HallDining(HallDining&& _Other) noexcept = delete;
	HallDining& operator=(const HallDining& _Other) = delete;
	HallDining& operator=(HallDining&& _Other) noexcept = delete;


	
	void SetMonster(Animatronics* _Monster);
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();

private:
	
	USpriteRenderer* RoomRender = nullptr;
	Animatronics* Monster = nullptr;

};

