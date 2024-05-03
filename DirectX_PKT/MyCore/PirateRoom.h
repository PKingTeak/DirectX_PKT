#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include<EngineCore/DefaultSceneComponent.h>
#include<iostream>
#include "RoomManager.h"
class Animatronics;

// Ό³Έν :
class PirateRoom : public RoomManager
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	PirateRoom();
	~PirateRoom();

	// delete Function
	PirateRoom(const PirateRoom& _Other) = delete;
	PirateRoom(PirateRoom&& _Other) noexcept = delete;
	PirateRoom& operator=(const PirateRoom& _Other) = delete;
	PirateRoom& operator=(PirateRoom&& _Other) noexcept = delete;



	void SetMonster(Animatronics* _Monster);
	

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();

private:

	USpriteRenderer* RoomRender = nullptr;
	Animatronics* Monster = nullptr;
	bool isMonster = false;


};

