#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include<EngineCore/DefaultSceneComponent.h>
#include<iostream>
#include "RoomManager.h"
class WestHall :public RoomManager
{
	GENERATED_BODY(RoomManager)
public:
	// constructor destructor
	WestHall();
	~WestHall();

	// delete Function
	WestHall(const WestHall& _Other) = delete;
	WestHall(WestHall&& _Other) noexcept = delete;
	WestHall& operator=(const WestHall& _Other) = delete;
	WestHall& operator=(WestHall&& _Other) = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void RendererOff();
	void RendererOn();
	void MapUpdate()override;
private:
	std::string FindImageName(std::vector<std::string> _Statename, std::string _MonsterLocal);
	USpriteRenderer* RoomRender = nullptr;
	Animatronics* Monster = nullptr;
	Animatronics* PrevMonster = nullptr;
	std::vector<std::string> RoomStatename = { "WestHall","WestHallBonnie"};

	void SettingSpriteName(int _Index) override;

};

