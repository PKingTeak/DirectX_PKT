#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include<EngineCore/DefaultSceneComponent.h>
#include<iostream>
#include "RoomManager.h"
class PirateRoom :public RoomManager
{
public:
	// constructor destructor
	PirateRoom();
	~PirateRoom();

	// delete Function
	PirateRoom(const PirateRoom& _Other) = delete;
	PirateRoom(PirateRoom&& _Other) noexcept = delete;
	PirateRoom& operator=(const PirateRoom& _Other) = delete;
	PirateRoom& operator=(PirateRoom&& _Other) = delete;
};

