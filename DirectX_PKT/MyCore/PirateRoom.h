#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include<EngineCore/DefaultSceneComponent.h>
#include<EngineCore/Image.h>
#include<iostream>
#include "RoomManager.h"


class Animatronics;

class PirateRoom : public RoomManager
{
	GENERATED_BODY(AActor)

public:

	PirateRoom();
	~PirateRoom();

	// delete Function
	PirateRoom(const PirateRoom& _Other) = delete;
	PirateRoom(PirateRoom&& _Other) noexcept = delete;
	PirateRoom& operator=(const PirateRoom& _Other) = delete;
	PirateRoom& operator=(PirateRoom&& _Other) noexcept = delete;



	void ChangeRoomCamera(Animatronics* _Monster) override;
	void MapChangeSprite(Animatronics* _Monster);


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void RendererOff();
	void RendererOn();
	void MapUpdate()override;
private:
	//std::string FindImageName(std::vector<std::string> _Statename, std::string _MonsterLocal);
	USpriteRenderer* RoomRender = nullptr;
	Animatronics* Monster = nullptr;
	Animatronics* PrevMonster = nullptr;
	std::vector<std::string> RoomStatename = { "PirateRoom","PirateRoom2","PirateRoomBonni","PirateRoomBonnie2","PirateRoomBonni","PirateRoomBonni2" };

	void SettingSpriteName(int _Index) override;

};

