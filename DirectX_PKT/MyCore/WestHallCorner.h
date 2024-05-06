#pragma once
class WestHallCornerCorner
{
public:
	// constructor destructor
	WestHallCornerCorner();
	~WestHallCornerCorner();

	// delete Function
	WestHallCornerCorner(const WestHallCornerCorner& _Other) = delete;
	WestHallCornerCorner(WestHallCornerCorner&& _Other) noexcept = delete;
	WestHallCornerCorner& operator=(const WestHallCornerCorner& _Other) = delete;
	WestHallCornerCorner& operator=(WestHallCornerCorner&& _Other) = delete;
};

#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include<EngineCore/DefaultSceneComponent.h>
#include<iostream>
#include "RoomManager.h"
class WestHallCorner :public RoomManager
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	WestHallCorner();
	~WestHallCorner();

	// delete Function
	WestHallCorner(const WestHallCorner& _Other) = delete;
	WestHallCorner(WestHallCorner&& _Other) noexcept = delete;
	WestHallCorner& operator=(const WestHallCorner& _Other) = delete;
	WestHallCorner& operator=(WestHallCorner&& _Other) = delete;
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
	std::vector<std::string> RoomStatename = { "WestHallCorner","WestHallCornerBonnie" };

	void SettingSpriteName(int _Index) override;

};

