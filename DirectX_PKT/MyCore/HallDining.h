#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include<EngineCore/DefaultSceneComponent.h>
#include<EngineCore/Image.h>
#include<iostream>
#include "RoomManager.h"


class Animatronics;

class HallDining : public RoomManager
{
	GENERATED_BODY(AActor)

public:

	HallDining();
	~HallDining();

	// delete Function
	HallDining(const HallDining& _Other) = delete;
	HallDining(HallDining&& _Other) noexcept = delete;
	HallDining& operator=(const HallDining& _Other) = delete;
	HallDining& operator=(HallDining&& _Other) noexcept = delete;



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
	std::vector<std::string> RoomStatename = { "HallDining","HallDining2","HallDiningBonni","HallDiningBonnie2","HallDiningChica","HallDiningChica2" };

	void SettingSpriteName(int _Index) override;

};

