#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include<EngineCore/DefaultSceneComponent.h>
#include<iostream>

class Animatronics;

// Ό³Έν :
class HallDining : public AActor
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


	bool CheckRoom();

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

