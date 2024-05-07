#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include<EngineCore/DefaultSceneComponent.h>
#include<EngineCore/Image.h>
#include<iostream>
#include "RoomManager.h"


class Animatronics;

class EastHallCorner : public RoomManager
{
	GENERATED_BODY(AActor)

public:

	EastHallCorner();
	~EastHallCorner();

	// delete Function
	EastHallCorner(const EastHallCorner& _Other) = delete;
	EastHallCorner(EastHallCorner&& _Other) noexcept = delete;
	EastHallCorner& operator=(const EastHallCorner& _Other) = delete;
	EastHallCorner& operator=(EastHallCorner&& _Other) noexcept = delete;



	void ChangeRoomCamera(Animatronics* _Monster) override;
	void MapChangeSprite(Animatronics* _Monster);


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
	std::vector<std::string> RoomStatename = { "EastHallCorner","EastHallCornerBonni" };

	void SettingSpriteName(int _Index) override;

};

