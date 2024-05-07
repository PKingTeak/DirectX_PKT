#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include<EngineCore/DefaultSceneComponent.h>
#include<EngineCore/Image.h>
#include<iostream>
#include "RoomManager.h"


class Animatronics;

class RestRoom : public RoomManager
{
	GENERATED_BODY(AActor)

public:

	RestRoom();
	~RestRoom();

	// delete Function
	RestRoom(const RestRoom& _Other) = delete;
	RestRoom(RestRoom&& _Other) noexcept = delete;
	RestRoom& operator=(const RestRoom& _Other) = delete;
	RestRoom& operator=(RestRoom&& _Other) noexcept = delete;



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
	std::vector<std::string> RoomStatename = { "RestRoom","RestRoomBonni" };

	void SettingSpriteName(int _Index) override;

};

