#pragma once
#include<EngineCore/Actor.h>
#include<iostream>
#include<string>
#include<EngineCore/SpriteInstancingRender.h>
#include<EngineCore/DefaultSceneComponent.h>
class Door : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constructor destructor
	Door();
	~Door();

	// delete Function
	Door(const Door& _Other) = delete;
	Door(Door&& _Other) noexcept = delete;
	Door& operator=(const Door& _Other) = delete;
	Door& operator=(Door&& _Other) = delete;

	void DoorOpen(std::string_view _ButtonName);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


	void RendererOff();
	void RendererOn();

private:
	USpriteRenderer* LDoorRender = nullptr;
	USpriteRenderer* RDoorRender = nullptr;
	
};

