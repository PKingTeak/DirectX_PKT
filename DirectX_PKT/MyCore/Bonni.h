#pragma once
#include<EngineCore/Actor.h>
#include<EngineCore/SpriteRenderer.h>
#include"Animatronics.h"
#include"map"
#include<EngineCore/imgui.h>
class BackGroundClass;
class Stage;
class Button;
class CCTVBackGround;
class Bonni : public AActor, public Animatronics
{

	GENERATED_BODY(AActor)

public:
	// constructor destructor
	Bonni();
	~Bonni();

	// delete Function
	Bonni(const Bonni& _Other) = delete;
	Bonni(Bonni&& _Other) noexcept = delete;
	Bonni& operator=(const Bonni& _Other) = delete;
	Bonni& operator=(Bonni&& _Other) = delete;
	void SetCurLocation();


	BonniLocation GetCurLocation();
	std::string GetCurLocationString();
	void AutoMove(float _DeltaTime);
	static bool isLobby;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	//bool ACTOpportunity(int _CurLevel) override;
	int MoveChance(int _Num);


	void RendererOff();
	void RendererOn();
private:
	Stage* MainStage = nullptr;
	std::shared_ptr<BackGroundClass> LobbyRoom = nullptr;
	std::shared_ptr<CCTVBackGround> CCTVMap = nullptr;
	//std::map<std::string, UImage*>* Map;
	


	
	bool Ismove = false;
	float TestTime = 0.0f;
	BonniLocation CurState = BonniLocation::ShowRoom;
	

};


