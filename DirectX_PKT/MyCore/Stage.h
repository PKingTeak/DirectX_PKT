#pragma once
#include<EngineCore/GameMode.h>
#include<EngineCore/SpriteRenderer.h>
#include"CCTVBackGround.h"
#include<EngineCore/Widget.h>
#include<EngineCore/Image.h>
#include"StageCamera.h"
// ���� :
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
	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:

	//Camera
	void ResetCamPos();
	void CameraMove(float _DeltaTime);
	bool CamMove = false;
	bool CamLeftMove = false;
	bool CameRightMove = false;
	void MainStageMove(float _DeltaTime);
	//
	USpriteRenderer* StageRender = nullptr;
	void DebugGUI();
	CCTVBackGround* CCTVPtr = nullptr;
	std::shared_ptr<UCamera> Camera;
	bool MoveEnd = false;
	//
	// Object
	std::shared_ptr<StageCamera> StageCam;

	//UI
	UImage* ArrowUi = nullptr;
	UImage* LeftBox = nullptr;
	UImage* RightBox = nullptr;
	

};

