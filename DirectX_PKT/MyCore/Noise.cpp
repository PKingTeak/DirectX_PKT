#include "PreCompile.h"
#include "Noise.h"
#include <EngineBase/EngineRandom.h>

Noise::Noise()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");

}

Noise::~Noise()
{
}


void Noise::BeginPlay()
{
//std::shared_ptr<UEngineMaterial> Mat = UEngineMaterial::Create("Noise");
//Mat->SetPixelShader("ImageShader.fx");
//Mat->SetVertexShader("ImageShader.fx");
//Mat->SetBlend("Overlay");

	Super::BeginPlay();
	SetActorScale3D(FVector(1280.0f, 720.0f, 50.0f));
	
	Renderer->CreateAnimation("NoizeAnimation", "Noise.png", 0.1, true);
	Renderer->ChangeAnimation("NoizeAnimation");
//	Renderer->SetMaterial("Noise");
//	Renderer->GetMaterial()->SetBlend("Overlay");
	Renderer->SetOrder(100);
	

}

void Noise::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
}


