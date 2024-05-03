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
class CCTVUI;
class Button;
class Door;
class Lobby;
class StageBackGroundClass;
class Fan;
class Bonni;
class ShowRoom;
class PirateRoom;
class BackStage;
class SupplyCloset;
class WestHall;
class WestHallCorner;
class EastHall;
class EastHallCorner;
class KittenRoom;
class HallDining;
class RestRoom;
class RoomManager;
class Animatronics;

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
	
	std::shared_ptr<StageBackGroundClass> GetLobbyBackGround();
	std::shared_ptr<CCTVBackGround> GetCCTVBack();
	std::shared_ptr<Noise> GetNoise();
	std::shared_ptr<Door> GetStageDoor();
	
	std::shared_ptr<Bonni> GetStageBonni();
	std::vector<std::string> GetCamName();
	
	std::string FindAnimatronicsLocation();
	std::shared_ptr<RoomManager> FindActorIndex(Animatronics* _Monster);
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:

	void ChageCam();
	//Lobby
	std::shared_ptr<StageBackGroundClass> LobbyBackGround = nullptr;
	std::shared_ptr<Fan> LobbyFan = nullptr;

	//Camera
	void ResetCamPos();
	void CameraMove(float _DeltaTime);
	bool CamMove = false;
	bool CamLeftMove = false;
	bool CameRightMove = false;
	void MainStageMove(float _DeltaTime);
	bool CCTVChecker = false;
	std::shared_ptr<CCTVUI> CCTVRectUI = nullptr;

	//
	USpriteRenderer* StageRender = nullptr;
	void DebugGUI();
	std::shared_ptr<CCTVBackGround> CCTVPtr = nullptr; //화면 전환해주는 포인터 CCTV화면
	std::shared_ptr<UCamera> Camera; // 레벨 메인 카메라
	bool MoveEnd = false;
	//
	// Object
	std::shared_ptr<StageCamera> StageCam = nullptr;
	std::shared_ptr<Door> StageDoor = nullptr;



	//UI
	UImage* ArrowUi = nullptr;
	UImage* LeftBox = nullptr;
	UImage* RightBox = nullptr;
	UImage* CCTVMap = nullptr;
	UImage* CCTVCams[11] = { nullptr, };

	
	UImage* PrevCam = nullptr;

	//Button
	std::shared_ptr<Button> DoorControlButton = nullptr;
	
	
	//Cam
	std::vector<std::string> Name = { "Cam1A","Cam1B" ,"Cam1C","Cam5","Cam7","Cam3","Cam6","Cam2A","Cam2B","Cam4A","Cam4B" };
	std::vector<AActor*> CamLocal;

	std::vector<std::shared_ptr<RoomManager>> RoomActor;
	std::vector<UImage*> RoomCameraUI;


	//캠설정
	int FindIndex(std::string _Name);
	

	UImage* PreCCTVCamUI = nullptr;
	UImage* CurCCTVCamUI = nullptr;

	RoomManager* CurCCTVCamActor = nullptr;
	RoomManager* PreCCTVCamUIActor = nullptr;




	std::string PreCamName = "ShowRoom";

	std::string CurCamInfo = " ";
	std::string PrevCamInfo = " ";
	std::string LocationName = "";


	

	std::string PrevMouseCamInfo = "ShowRoom";
	
	//void FindCCTVCam();

	void ClickCamUI(std::string _CamName);
	void CamInteract();
	void CCTVUpdate();
	void CCTVUIGreenCheck(std::string _CamName);
	

	// Noise
	std::shared_ptr<Noise> NoiseEffect = nullptr;
	void NoiseCheck();

	//Lobby UI
	std::shared_ptr<Lobby> LobbyUI = nullptr;
	

	//Monster
	std::shared_ptr<Bonni> BonniActor = nullptr;
	
	std::string MonsterName = "";
	//


	std::shared_ptr<ShowRoom> BShowRoom = nullptr;
	std::shared_ptr<HallDining> BHallDining = nullptr;
	std::shared_ptr<PirateRoom> BPirateRoom = nullptr;
	std::shared_ptr<BackStage> BBackStage = nullptr;
	std::shared_ptr<SupplyCloset> BSupplyCloset = nullptr;
	std::shared_ptr<WestHall> BWestHall = nullptr;
	std::shared_ptr<WestHallCorner> BWestHallCorner = nullptr;
	std::shared_ptr<EastHall> BEastHall = nullptr;
	std::shared_ptr<EastHallCorner> BEastHallCorner = nullptr;
	std::shared_ptr<KittenRoom> BKittenRoom = nullptr;
	std::shared_ptr<RestRoom> BRestRoom = nullptr;
	
	


	float TestTimer = 0;
	bool BonniChecker = false;
};

