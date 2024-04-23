#pragma once
#include <EngineCore/Actor.h>
#include<EngineCore/SpriteRenderer.h>
#include<EngineCore/Collision.h>
#include"StageCamera.h"
#include<EngineCore/Image.h>
// Ό³Έν :

class Arrow : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	Arrow();
	~Arrow();

	// delete Function
	Arrow(const Arrow& _Other) = delete;
	Arrow(Arrow&& _Other) noexcept = delete;
	Arrow& operator=(const Arrow& _Other) = delete;
	Arrow& operator=(Arrow&& _Other) noexcept = delete;

	void ChangeCam();
	
	std::shared_ptr<StageCamera> StageCam;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();
private:
	UImage* ArrowUIImage = nullptr;
	USpriteRenderer* ArrowRender = nullptr;
	UCollision* ArrowCollision = nullptr;
	USpriteRenderer* TestRender = nullptr;
	bool isCamOpen = false;
};

