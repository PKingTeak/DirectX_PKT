#include "PreCompile.h"
#include "Arrow.h"
#include<EngineCore/Collision.h>
#include"MyCore.h"
#include<EngineCore/DefaultSceneComponent.h>

Arrow::Arrow() 
{
	

	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");

	

	SetRoot(Root);
}

Arrow::~Arrow() 
{
}
void Arrow::BeginPlay()
{
	Super::BeginPlay();

} 
void Arrow::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
void Arrow::ChangeCam()
{

	StageCam->CamCCTVOn();
	
	if (true == isCamOpen)
	{
		StageCam->SetActive(false);
		isCamOpen = false;

	}
	else
	{
		StageCam->SetActive(true);
		isCamOpen = true;
		//�Լ� �ֱ� 
	}
	
	
	

	
	//Actor->
	//ChangeLevel == ���⼭ ī�޶� ���� �ϴ� �κ����� �������ִ°��� ������ ����. 


}