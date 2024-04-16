#pragma once
#include<EngineCore/GameMode.h>
#include<EngineCore/SpriteRenderer.h>
// Ό³Έν :
class CamLevel : public AGameMode
{
	GENERATED_BODY(AGameMode)

public:
	// constrcuter destructer
	CamLevel();
	~CamLevel();

	// delete Function
	CamLevel(const CamLevel& _Other) = delete;
	CamLevel(CamLevel&& _Other) noexcept = delete;
	CamLevel& operator=(const CamLevel& _Other) = delete;
	CamLevel& operator=(CamLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:
	
};

