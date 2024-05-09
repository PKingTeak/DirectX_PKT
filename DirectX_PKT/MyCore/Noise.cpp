#include "PreCompile.h"
#include "Noise.h"
#include <EngineBase/EngineRandom.h>
#include"MyCore.h"
Noise* Noise::MainNoise = nullptr;

Noise::Noise()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	SetRoot(Renderer);


}

Noise::~Noise()
{
}


void Noise::BeginPlay() 
{
	Super::BeginPlay();
	Noise::MainNoise = this;
	Renderer->SetMaterial("Noise");
	SetActorScale3D(FVector(1280.0f, 720.0f, 50.0f));
	Renderer->CreateAnimation("NoizeAnimation", "Noise.png", 0.1f, true);
	Renderer->ChangeAnimation("NoizeAnimation");
	


	Renderer->SetOrder(100);
	
	
}

Noise* Noise::GetNoise()

{
	return MainNoise;
}

void Noise::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
}

