#include "PreCompile.h"
#include "Animatronics.h"

Animatronics::Animatronics()
{

}

Animatronics::~Animatronics()
{
}


void Animatronics::BeginPlay()
{
	Super::BeginPlay();
	
}

void Animatronics::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
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
		return 0; //희소성
	}
	else if(RandomNum % 2 == 1)
	{
		// _Num보다 큰데 홀수일경우 1
	return 1; //확률 높은거
	}
	return 2;//아무것도 해당안되면 2
}// w

