#pragma once

#include<EngineCore/Actor.h>
#include<EngineCore/Renderer.h>
#include<EngineCore/SpriteRenderer.h>
class Fan : public AActor
{
	GENERATED_BODY(AActor)
public:
	Fan();
	~Fan();

	// delete Function
	Fan(const Fan& _Other) = delete;
	Fan(Fan&& _Other) noexcept = delete;
	Fan& operator=(const Fan& _Other) = delete;
	Fan& operator=(Fan&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();
private:

	USpriteRenderer* ObjectRender = nullptr;
};

