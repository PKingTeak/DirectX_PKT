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
	//������ �ൿ ��ȸ
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
		return 0; //��Ҽ�
	}
	else if(RandomNum % 2 == 1)
	{
		// _Num���� ū�� Ȧ���ϰ�� 1
	return 1; //Ȯ�� ������
	}
	return 2;//�ƹ��͵� �ش�ȵǸ� 2
}// w

