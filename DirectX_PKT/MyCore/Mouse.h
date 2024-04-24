#pragma once
#include <EngineCore/Actor.h>
#include<EngineCore/SpriteRenderer.h>
#include<EngineCore/Collision.h>
#include"MyCore.h"
#include"Arrow.h"
// ���� :
class StageBackGroundClass;
class Button;
class Mouse : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	Mouse();
	~Mouse();

	// delete Function
	Mouse(const Mouse& _Other) = delete;
	Mouse(Mouse&& _Other) noexcept = delete;
	Mouse& operator=(const Mouse& _Other) = delete;
	Mouse& operator=(Mouse&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void RendererOff();
	void RendererOn();
private:

	std::shared_ptr<StageBackGroundClass> StageBackGround;
	std::shared_ptr<Button> ButtonClass;
	void MouseClick(OrderType _OrderType);
	void MouseActive();
	void SetMousePos();
	FVector MousePos = {};
	UCollision* MouseCollision = nullptr;
	USpriteRenderer* MSprite = nullptr;
	

};

