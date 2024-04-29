#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include<iostream>
#include<string>
#include<string_view>

// Ό³Έν :
class Noise : public AActor
{
	GENERATED_BODY(AActor)

private:
	static Noise* MainNoise;
public:
	// constrcuter destructer
	Noise();
	~Noise();

	// delete Function
	Noise(const Noise& _Other) = delete;
	Noise(Noise&& _Other) noexcept = delete;
	Noise& operator=(const Noise& _Other) = delete;
	Noise& operator=(Noise&& _Other) noexcept = delete;

	

	static Noise* GetNoise();
	

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();

private:
	USpriteRenderer* Renderer = nullptr;
	

};

