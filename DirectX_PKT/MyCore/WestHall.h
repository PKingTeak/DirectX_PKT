#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include<EngineCore/DefaultSceneComponent.h>
#include<iostream>
#include "RoomManager.h"
class WestHall :public RoomManager
{
public:
	// constructor destructor
	WestHall();
	~WestHall();

	// delete Function
	WestHall(const WestHall& _Other) = delete;
	WestHall(WestHall&& _Other) noexcept = delete;
	WestHall& operator=(const WestHall& _Other) = delete;
	WestHall& operator=(WestHall&& _Other) = delete;
};

