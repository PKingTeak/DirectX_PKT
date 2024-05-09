#pragma once
#include<EngineCore/Actor.h>
#include<EngineCore/SpriteRenderer.h>
#include"Animatronics.h"
#include"map"
#include<EngineCore/imgui.h>
#include"Stage.h"
class BackGroundClass;
class Stage;
class Button;
class CCTVBackGround;
class Chica : public Animatronics
{

	GENERATED_BODY(AActor)

public:
	// constructor destructor
	Chica();
	~Chica();

	// delete Function
	Chica(const Chica& _Other) = delete;
	Chica(Chica&& _Other) noexcept = delete;
	Chica& operator=(const Chica& _Other) = delete;
	Chica& operator=(Chica&& _Other) = delete;
	void SetCurLocation();


	ChicaLocation GetCurLocation();
	std::string GetCurLocationString();
	void AutoMove(float _DeltaTime);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	//bool ACTOpportunity(int _CurLevel) override;
	int MoveChance(int _Num);
	void FindMonsterIndex() override;

	void RendererOff();
	void RendererOn();
private:
	Stage* MainStage = nullptr;
	std::shared_ptr<BackGroundClass> LobbyRoom = nullptr;
	std::shared_ptr<CCTVBackGround> CCTVMap = nullptr;
	std::shared_ptr<Door> LobbyDoor = nullptr;
	std::shared_ptr<StageBackGroundClass> LobbyBackGround = nullptr;



	bool Ismove = false;
	float TestTime = 0.0f;
	float PrevTime = 0.0f;
	int TimeCount = 0;
	ChicaLocation CurState = ChicaLocation::ShowRoom;


};


