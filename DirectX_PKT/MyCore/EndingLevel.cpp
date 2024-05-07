#include "PreCompile.h"
#include "EndingLevel.h"
#include "TitleBackGround.h"
#include <EngineCore/Camera.h>
#include <EnginePlatform/EngineInput.h>
#include "Stage.h"
#include"EndingBackGround.h"

EndingLevel::EndingLevel()
{


}


EndingLevel::~EndingLevel()
{
}

void EndingLevel::BeginPlay()
{
	Super::BeginPlay();
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	


	EndingBack = GetWorld()->SpawnActor<EndingBackGround>("EndingBackGround");

	
	
	

}

void EndingLevel::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}



