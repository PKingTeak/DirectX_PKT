#include "PreCompile.h"
#include "CCTVBackGround.h"
#include<EngineCore/Collision.h>
#include"MyCore.h"
#include<EngineCore/DefaultSceneComponent.h>
#include"Noise.h"
CCTVBackGround* CCTVBackGround::MainCCTV = nullptr;

CCTVBackGround::CCTVBackGround()
{
	
	UDefaultSceneComponent* Default = CreateDefaultSubObject<UDefaultSceneComponent>("Default");


	CCTVBackGroundRender = CreateDefaultSubObject<USpriteRenderer>("CCTVCam");
	CCTVBackGroundRender->SetupAttachment(Default);
	CCTVBackGroundRender->SetSprite("TestCamBackGround.png");
	CCTVBackGroundRender->SetAutoSize(1.0f, true);
	CCTVBackGroundRender->SetOrder(100);
	CCTVBackGroundRender->SetActive(false);


	CCTVEffect = CreateDefaultSubObject<USpriteRenderer>("CCTVEffect");
	
	
	CCTVEffect->SetupAttachment(Default);
	CCTVEffect->SetMaterial("Noise");
	CCTVEffect->SetOrder(101);
	CCTVEffect->SetScale({1600,720});
	CCTVEffect->CreateAnimation("NoizeAnimation", "Noise.png", 0.1f, true);
	CCTVEffect->ChangeAnimation("NoizeAnimation");
	CCTVEffect->SetActive(false);

	

	SetRoot(Default);

}



CCTVBackGround::~CCTVBackGround()
{
}
void CCTVBackGround::BeginPlay()
{
	Super::BeginPlay();
	CCTVBackGround::MainCCTV = this;
	NoiseEffect->Noise::GetNoise();

}
CCTVBackGround* CCTVBackGround::GetCCTVBackGround()
{
	return MainCCTV;
}
void CCTVBackGround::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}




void CCTVBackGround::CCTVON()
{
	CCTVBackGroundRender->SetActive(true);
	//NoiseEffect->SetActive(true);
	CCTVEffect->SetActive(true);

	CamMode = true;
}
void CCTVBackGround::CCTVOFF()
{
	CCTVBackGroundRender->SetActive(false);
	NoiseEffect->SetActive(false);
	CCTVEffect->SetActive(false);
	CamMode = false;
}


void CCTVBackGround::ChangeCam(std::string _UICamName)
{	
	std::string SpriteName = _UICamName.append(".png");
	
	CCTVBackGroundRender->SetSprite(SpriteName);
}


