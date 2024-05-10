#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include<EngineCore/DefaultSceneComponent.h>
#include<EngineCore/Image.h>
#include<iostream>
#include "RoomManager.h"


class Animatronics;

class BackStage : public RoomManager
{
	GENERATED_BODY(RoomManager)

public:

	BackStage();
	~BackStage();

	// delete Function
	BackStage(const BackStage& _Other) = delete;
	BackStage(BackStage&& _Other) noexcept = delete;
	BackStage& operator=(const BackStage& _Other) = delete;
	BackStage& operator=(BackStage&& _Other) noexcept = delete;



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
	std::vector<std::string> RoomStatename;

	void SettingSpriteName(int _Index) override;

};

