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
	void MapUpdate() override;
	void RendererOff();
	void RendererOn();

private:

	USpriteRenderer* RoomRender = nullptr;
	Animatronics* Monster = nullptr;
	Animatronics* PrevMonster = nullptr;
	bool isMonster = false;

	std::vector<std::string> RoomStatename = { "PirateRoom" , "PirateRoom2","PirateRoom3","PirateRoom4","PirateRoom5" };
};

