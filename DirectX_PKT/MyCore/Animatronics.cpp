#include "PreCompile.h"
#include "Animatronics.h"

Animatronics::Animatronics()
{
}

Animatronics::~Animatronics()
{
}


bool Animatronics::ACTOpportunity(int _CurLevel)
{
	//난수로 행동 기회
	int RandomNum = UEngineRandom::MainRandom.RandomInt(0, 20);
	if (_CurLevel >= RandomNum)
	{
		return true;
	}
	
	return false;

		
}

void Animatronics::SetLevel(int _Level)
{
	Level = _Level;
}







int Animatronics::MoveChance(int _Num)
{
	int RandomNum = UEngineRandom::MainRandom.RandomInt(0, 100);
	if (_Num < RandomNum)
	{
		return 0;
	}
	return 1;
}