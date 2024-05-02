#pragma once
#include <EngineCore/Actor.h>
#include<EngineCore/SpriteRenderer.h>
#include<EngineCore/Collision.h>
#include"Noise.h"

class Stage;
class Bonni;
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
	void ChangeCam(std::string _UICamName);
	void ScanLineON();
	



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
	std::shared_ptr<Noise> NoiseEffect = nullptr;

	void ScanLineEffect();


	//Animatronics
	std::shared_ptr<Bonni> BonniCam = nullptr;
	//�ٸ� �͵鵵 �߰� 
	
	std::string MonsterChecker();
	
	std::map<int, std::string> CCTVBonniLocal;
	std::vector<std::string> BonniLocalName = { "Cam1A","Cam1B","Cam5",	"Cam2A","Cam3",	"Cam2B","Lobby" };

};

