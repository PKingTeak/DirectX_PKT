#pragma once

#include<EngineCore/Actor.h>
#include<EngineCore/Renderer.h>
#include<EngineCore/SpriteRenderer.h>
#include<iostream>
#include"Arrow.h"

class Animatronics;
class ScanLine;
class Door;
class Stage;
class Lobby;
class StageBackGroundClass : public AActor
{
	
private:
	static StageBackGroundClass* MainStageBackGround;
	GENERATED_BODY(AActor)
public:
	StageBackGroundClass();
	~StageBackGroundClass();

	// delete Function
	StageBackGroundClass(const StageBackGroundClass& _Other) = delete;
	StageBackGroundClass(StageBackGroundClass&& _Other) noexcept = delete;
	StageBackGroundClass& operator=(const StageBackGroundClass& _Other) = delete;
	StageBackGroundClass& operator=(StageBackGroundClass&& _Other) noexcept = delete;
	
	StageBackGroundClass* GetMainStageBackGround();

	
	void LightOn(std::string _Dir);
	void ChangeBackGround(std::string _RoomState);
	void PlayJumpScare(std::string _Name);
	void SetLobbyMonster(Animatronics* _Monster);
	void CountMonsterTime(float _DeltaTime);
	bool BlockChecker();
	bool RightBlockChecker();
	bool LeftLightChecker();
	bool RightLightChecker();


	void SetLobbySound();
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();
	
private:
	std::vector<AActor> UIInfo;
	USpriteRenderer* JumpScare = nullptr;
	USpriteRenderer* StageBackRender = nullptr;
	USpriteRenderer* TurnoffLobby = nullptr;

	Animatronics* Monster = nullptr;
	
	std::shared_ptr<Door> LobbyDoor = nullptr;
	std::shared_ptr<Lobby> BatteryUI = nullptr;
	
	float TickTimeChecker = 0.0f;
	Stage* MainStage = nullptr;
	bool ColDir = false;
	float Time = 0.0f;
	bool LeftLight = false;
	bool RightLight = false;
	
	bool BlockCheck = false;
	bool RBlockCheck = false;
	UEngineSoundPlayer LobbySound;
	UEngineSoundPlayer JumpScareSound;
	UEngineSoundPlayer LightSound;
	UEngineSoundPlayer MonsterLightSound;
	UEngineSoundPlayer TurnOffSound;
	UEngineSoundPlayer ToyMusicSound;
	void BatteryOff();
	bool StageLightCheck = false;
	int AniCount = 0;
};

