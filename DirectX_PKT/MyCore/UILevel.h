#pragma once
#include<EngineCore/GameMode.h>
#include<EngineCore/SpriteRenderer.h>
// Ό³Έν :
class UILevel : public AGameMode
{
	GENERATED_BODY(AGameMode)

public:
	// constrcuter destructer
	UILevel();
	~UILevel();

	// delete Function
	UILevel(const UILevel& _Other) = delete;
	UILevel(UILevel&& _Other) noexcept = delete;
	UILevel& operator=(const UILevel& _Other) = delete;
	UILevel& operator=(UILevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:
	std::shared_ptr<AActor> UIActor;
	

};

