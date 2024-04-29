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
		//함수 넣기 
	}
	
	
	

	
	//Actor->
	//ChangeLevel == 여기서 카메라 감시 하는 부분으로 변경해주는것이 좋을거 같다. 


}