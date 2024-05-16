#pragma once
#include<EngineCore/GameMode.h>
#include<EngineCore/SpriteRenderer.h>
#include<EngineCore/Widget.h>
#include<EngineCore/GameMode.h>
#include<EngineCore/Image.h>
#include"StageCamera.h"
#include<EngineCore/Actor.h>
#include<Enginecore/DefaultSceneComponent.h>
// Ό³Έν :
class Lobby : public AActor
{
	GENERATED_BODY(AActor)

public:
	
	Lobby();
	~Lobby();

	// delete Function
	Lobby(const Lobby& _Other) = delete;
	Lobby(Lobby&& _Other) noexcept = delete;
	Lobby& operator=(const Lobby& _Other) = delete;
	Lobby& operator=(Lobby&& _Other) noexcept = delete;
	
	void BatteryPowerCheck(float _DeltaTime, int _limitTime);
	inline void BatteryUserUP()
	{
		++BatteryUser;
	}
	inline void BatteryUserDown()
	{
		--BatteryUser;
	
	}

	inline int GetBatteryPower()
	{
		return BatteryPower;
	}
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	
private:

	float Time = 0;
	
	int BatteryPower = 99;

	int BatteryUser = 1;
	std::string BatteryText;
	UImage* BatteryUI = nullptr;
	UImage* PowerLeftText = nullptr;
	UImage* UsageText = nullptr;
	UImage* GageText[2] = {nullptr,nullptr};
	UImage* PerCent = nullptr;
	
	
	void Batterypercent();
	void BatteryGageUI(float _DeltaTime);
	

};

