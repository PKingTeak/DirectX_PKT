#pragma once
#include<EngineCore/GameMode.h>
#include<EngineCore/SpriteRenderer.h>
#include"CCTVBackGround.h"
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
	FVector GetCurCameraPos();
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:
	void CameraMove(float _DeltaTime);
	USpriteRenderer* StageRender = nullptr;
	void DebugGUI();
	CCTVBackGround* CCTVPtr = nullptr;
	std::shared_ptr<UCamera> Camera;
	bool MoveEnd = false;

};

