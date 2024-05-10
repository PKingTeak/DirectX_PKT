#pragma once
#include <EngineCore/Actor.h>
#include<EngineCore/SpriteRenderer.h>
#include<EngineCore/Collision.h>
#include"Noise.h"

class Stage;
class Bonni;
class RoomManager;
class StageNoise;
class CCTVBackGround : public AActor
{
	GENERATED_BODY(AActor)
private:
	



	

public:
	// constrcuter destructer
	CCTVBackGround();
	~CCTVBackGround();

	// delete Function
	CCTVBackGround(const CCTVBackGround& _Other) = delete;
	CCTVBackGround(CCTVBackGround&& _Other) noexcept = delete;
	CCTVBackGround& operator=(const CCTVBackGround& _Other) = delete;
	CCTVBackGround& operator=(CCTVBackGround&& _Other) noexcept = delete;

	CCTVBackGround* GetCCTVBackGround();
	
	void CCTVON();
	void CCTVOFF();
	void StartScanLine();
	inline bool GetCamMode()
	{
		return CamMode;
	}
	//void ChangeCam(std::string _UICamName);
	void ChangeSprite(std::string _ChangeCam);
	void ScanLineON();
	void SetCamBackInfo(RoomManager* _CamInfo, bool _CurCheck = true);
	//void ChangeCam(RoomManager* _UICamName);
	std::string ChangeCam(RoomManager* _UICamName);	
	void GetCamera(RoomManager* _ChangeRoom);

	void AllCamActorOff();
	void MonsterSpriteChange(std::string _ChangeName);

	USpriteRenderer* GetRenderer()
	{
		return CCTVBackGroundRender;
	}
	void ChangeSprite();
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();
private:
	
	USpriteRenderer* CCTVBackGroundRender = nullptr;
	USpriteRenderer* CCTVEffect = nullptr;
	USpriteRenderer* ChangeEffect = nullptr;
	bool CamMode;
	bool ScanAniEnd = false;

	Stage* StageLevel = nullptr;
	std::shared_ptr<StageNoise> NoiseEffect = nullptr;

	void ScanLineEffect();


	//Animatronics
	std::shared_ptr<Bonni> BonniCam = nullptr;
	//다른 것들도 추가 
	
	
	
	//std::map<int,AActor*> CCTVBackGroundMaps;
	
	USpriteRenderer* ChangeSpriteRender = nullptr;
	
	std::vector<std::shared_ptr<RoomManager>> CCTVActors;
	RoomManager* CCTVInfo = nullptr;
	RoomManager* PreCCTVInfo = nullptr;
	


	std::string ChangeCamName;
};

