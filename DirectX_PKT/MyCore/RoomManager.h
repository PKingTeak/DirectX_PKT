#pragma once
#include<EngineCore/Actor.h>
#include"Animatronics.h"
#include<EngineCore/Image.h>
#include"MyCore.h"


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

	bool CheckRoom();
	void SetMonter(Animatronics* _Monster);


	void SetMonster(Animatronics* _Monster);
	Animatronics* GetMonster();
	virtual UImage* GetUI(); 
	virtual void SettingSpriteName(int _index);
	std::string GetCurRoomSpriteName();
	
protected:
	virtual void MapUpdate();

	virtual void ChangeRoomCamera(Animatronics* _Monster);
	void BeginPlay() override;
//	virtual Animatronics* GetMonster();
	void Tick(float _DeltaTime) override;
	void RendererOff();
	void RendererOn();
	UImage* Camera = nullptr;
	std::string CurRoomSpriteName = "";
	Animatronics* Monster = nullptr;
	
	
	std::vector<std::string> RoomStatename;
};

