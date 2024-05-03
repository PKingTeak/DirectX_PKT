#pragma once
#include<EngineBase/EngineRandom.h>
#include<string>

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

class CCTVBackGround;
class Animatronics
{
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

	std::string GetName();
	std::string GetCurLocationString();
protected :
	bool ACTOpportunity(int _CurLevel);
	int MoveChance(int _Num);
	//virtual std::string  MoveAnimtronics();
	virtual void SetLevel(int _Level);
	int Level = 0;
	
	std::string CurLocation = "";
	std::string CurLocalName = "";
	
	void StringChangeTest();
	
	
};

