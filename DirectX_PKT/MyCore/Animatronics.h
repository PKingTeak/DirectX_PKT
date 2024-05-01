#pragma once
#include<EngineBase/EngineRandom.h>
#include<string>

enum class BonniLocation
{
	Cam1A,
	Cam1B,
	Cam5,
	Cam2A,
	Cam3,
	Cam2B,
	Lobby


};
class Animatronics
{
public:
	

	// constructor destructor
	Animatronics();
	~Animatronics();

	// delete Function
	Animatronics(const Animatronics& _Other) = delete;
	Animatronics(Animatronics&& _Other) noexcept = delete;
	Animatronics& operator=(const Animatronics& _Other) = delete;
	Animatronics& operator=(Animatronics&& _Other) = delete;


protected :
	bool ACTOpportunity(int _CurLevel);
	int MoveChance(int _Num);
	//virtual std::string  MoveAnimtronics();
	virtual void SetLevel(int _Level);
	int Level = 0;

	void StringChangeTest();
	
	
};

