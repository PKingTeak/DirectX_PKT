#pragma once
#include<EngineCore/Actor.h>

class Animatronics;

class RoomManager : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constructor destructor
	RoomManager();
	~RoomManager();

	// delete Function
	RoomManager(const RoomManager& _Other) = delete;
	RoomManager(RoomManager&& _Other) noexcept = delete;
	RoomManager& operator=(const RoomManager& _Other) = delete;
	RoomManager& operator=(RoomManager&& _Other) = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	virtual void InitCCTVBackGround();
	void RendererOff();
	void RendererOn();

	Animatronics* Monster = nullptr;
	
};

