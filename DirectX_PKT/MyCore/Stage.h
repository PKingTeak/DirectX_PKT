#pragma once
#include<EngineCore/GameMode.h>
#include<EngineCore/SpriteRenderer.h>
#include"CCTVBackGround.h"
#include<EngineCore/Widget.h>
#include<EngineCore/Image.h>
#include"StageCamera.h"
#include<map>

// 설명 :
class ScanLine;
class Noise;
class Stage : public AGameMode
{
	GENERATED_BODY(AGameMode)
	static bool IsCamOn;
	
public:
	// constrcuter destructer
	Stage();
	~Stage();

	// delete Function
	Stage(const Stage& _Other) = delete;
	Stage(Stage&& _Other) noexcept = delete;
	Stage& operator=(const Stage& _Other) = delete;
	Stage& operator=(Stage&& _Other) noexcept = delete;
	
	std::shared_ptr<CCTVBackGround> GetCCTVBack();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:

	void ChageCam();

	//Camera
	void ResetCamPos();
	void CameraMove(float _DeltaTime);
	bool CamMove = false;
	bool CamLeftMove = false;
	bool CameRightMove = false;
	void MainStageMove(float _DeltaTime);
	bool CCTVChecker = false;
	//
	USpriteRenderer* StageRender = nullptr;
	void DebugGUI();
	std::shared_ptr<CCTVBackGround> CCTVPtr = nullptr; //화면 전환해주는 포인터 CCTV화면
	std::shared_ptr<UCamera> Camera; // 레벨 메인 카메라
	bool MoveEnd = false;
	//
	// Object
	std::shared_ptr<StageCamera> StageCam;

	//UI
	UImage* ArrowUi = nullptr;
	UImage* LeftBox = nullptr;
	UImage* RightBox = nullptr;
	UImage* CCTVMap = nullptr;
	UImage* CCTVCams[11] = { nullptr, };
	UImage* PrevCam = nullptr;

	
	std::vector<std::string> Name = { "Cam1A","Cam1B" ,"Cam1C","Cam5","Cam7","Cam3","Cam6","Cam2A","Cam2B","Cam4A","Cam4B" };
	std::map<std::string,UImage*> CCTVCamUI;
	std::string MouseCamInfo = " ";
	std::string PrevMouseCamInfo = "Cam1A";
	//void FindCCTVCam();

	void ClickCamUI(std::string _CamName);
	void CamInteract();
	void CCTVUpdate();
	void CCTVUIGreenCheck(std::string _CamName);

	//ScanLine
	
	std::shared_ptr<Noise> NoiseEffect = nullptr;
	std::shared_ptr<ScanLine> ScanLineUI = nullptr;
	void StartScanLine();
	void NoiseCheck();
	

};

