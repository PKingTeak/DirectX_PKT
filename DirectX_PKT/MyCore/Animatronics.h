#pragma once
#include<EngineBase/EngineRandom.h>
#include<EngineCore/Actor.h>
#include<string>
#include"Stage.h"
enum  class BonniLocation
{
	ShowRoom,
	HallDining,
	BackStage,
	WestHall,
	SupplyCloset,
	WestHallCorner,
	Lobby


};
enum class ChicaLocation
{
	ShowRoom,
	HallDining,
	RestRoom,
	Kitten,
	EastHall,
	EastHallCorner,
	Lobby


};


class CCTVBackGround;
class RoomManger;

class Animatronics :public AActor
{
	GENERATED_BODY(AActor)
public:
	friend CCTVBackGround;

	// constructor destructor
	Animatronics();
	~Animatronics();

	// delete Function
	Animatronics(const Animatronics& _Other) = delete;
	Animatronics(Animatronics&& _Other) noexcept = delete;
	Animatronics& operator=(const Animatronics& _Other) = delete;
	Animatronics& operator=(Animatronics&& _Other) = delete;

	//std::string GetName();
	std::string GetCurLocationString();
protected :
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	bool ACTOpportunity(int _CurLevel);
	int MoveChance(int _Num);
	//virtual std::string  MoveAnimtronics();
	virtual void SetLevel(int _Level);

	virtual void FindMonsterIndex();
	int Level = 0;
	std::string MonsterName = "";
	std::string CurLocation = "";
	std::string CurLocalName = "";
	std::vector<std::shared_ptr<RoomManager>> CurRoomInfo;

	void LobbyCallBackCheck();

	
};

