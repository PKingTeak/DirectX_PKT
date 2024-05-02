#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include<EngineCore/DefaultSceneComponent.h>
#include<iostream>
#include"RoomManager.h"
class Animatronics;
// Ό³Έν :
class ShowRoom : public RoomManager
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ShowRoom();
	~ShowRoom();

	// delete Function
	ShowRoom(const ShowRoom& _Other) = delete;
	ShowRoom(ShowRoom&& _Other) noexcept = delete;
	ShowRoom& operator=(const ShowRoom& _Other) = delete;
	ShowRoom& operator=(ShowRoom&& _Other) noexcept = delete;

	bool CheckRoom();
	
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	
	void RendererOff();
	void RendererOn();

private:

	void SetMonster(Animatronics* _Monster);
	USpriteRenderer* RoomRender = nullptr;
	std::vector<std::string> Statename;
	Animatronics* Monster = nullptr;

	bool MonsterChecker = false;

};

