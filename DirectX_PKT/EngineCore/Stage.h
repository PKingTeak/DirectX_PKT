#pragma once
#include<EngineCore/GameMode.h>
#include<EngineCore/SpriteRenderer.h>
// Ό³Έν :
class Stage : public AGameMode
{
	GENERATED_BODY(AGameMode)

public:
	// constrcuter destructer
	Stage();
	~Stage();

	// delete Function
	Stage(const Stage& _Other) = delete;
	Stage(Stage&& _Other) noexcept = delete;
	Stage& operator=(const Stage& _Other) = delete;
	Stage& operator=(Stage&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* StageRender = nullptr;
};

