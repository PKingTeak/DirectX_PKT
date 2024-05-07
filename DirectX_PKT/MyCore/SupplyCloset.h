#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include<EngineCore/DefaultSceneComponent.h>
#include<EngineCore/Image.h>
#include<iostream>
#include "RoomManager.h"


class Animatronics;

class SupplyCloset : public RoomManager
{
	GENERATED_BODY(AActor)

public:

	SupplyCloset();
	~SupplyCloset();

	// delete Function
	SupplyCloset(const SupplyCloset& _Other) = delete;
	SupplyCloset(SupplyCloset&& _Other) noexcept = delete;
	SupplyCloset& operator=(const SupplyCloset& _Other) = delete;
	SupplyCloset& operator=(SupplyCloset&& _Other) noexcept = delete;



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
	std::vector<std::string> RoomStatename = { "SupplyCloset","SupplyClosetBonni"};

	void SettingSpriteName(int _Index) override;

};

