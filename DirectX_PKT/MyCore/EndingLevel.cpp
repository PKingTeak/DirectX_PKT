#include "PreCompile.h"
#include "EndingLevel.h"
#include "TitleBackGround.h"
#include <EngineCore/Camera.h>
#include <EnginePlatform/EngineInput.h>
#include "Stage.h"
#include"Mouse.h"
#include"Noise.h"

EndingLevel::EndingLevel()
{


}


EndingLevel::~EndingLevel()
{
}

void EndingLevel::BeginPlay()
{
	Super::BeginPlay();
	UEngineSprite::CreateCutting("TITLE.png", 1, 4);
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	
	
	
	Renderer->ChangeAnimation("NoizeAnimation");
	

	

}

void EndingLevel::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (true == UEngineInput::IsDown('P'))
	{
		GEngine->ChangeLevel("MainLevel");
	}
	//if (true == UEngineInput::IsDown('P'))
	//{
	//	GEngine->ChangeLevel("PlayLevel");
	//}
}



