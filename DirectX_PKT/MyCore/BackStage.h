#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include<EngineCore/DefaultSceneComponent.h>
#include<iostream>
#include "RoomManager.h"

class BackStage :public RoomManager
{
public:
	// constructor destructor
	BackStage();
	~BackStage();

	// delete Function
	BackStage(const BackStage& _Other) = delete;
	BackStage(BackStage&& _Other) noexcept = delete;
	BackStage& operator=(const BackStage& _Other) = delete;
	BackStage& operator=(BackStage&& _Other) = delete;
};

