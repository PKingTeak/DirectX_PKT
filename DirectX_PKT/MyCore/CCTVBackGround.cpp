#include "PreCompile.h"
#include "CCTVBackGround.h"
#include<EngineCore/Collision.h>
#include"MyCore.h"
#include<EngineCore/DefaultSceneComponent.h>
#include"Noise.h"
#include"Stage.h"

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

	ChangeEffect = CreateDefaultSubObject<USpriteRenderer>("ChangeEffect");
	ChangeEffect->SetupAttachment(Default);
	ChangeEffect->SetMaterial("Noise");
	ChangeEffect->SetOrder(101);
	ChangeEffect->SetScale({ 1600,720 });
	ChangeEffect->CreateAnimation("ScanLineAni", "CCTVEffect", 0.1f, false);
	ChangeEffect->ChangeAnimation("ScanLineAni");
	ChangeEffect->SetActive(false);

	SetRoot(Default);

}



CCTVBackGround::~CCTVBackGround()
{
}
void CCTVBackGround::BeginPlay()
{
	Super::BeginPlay();
	
	StageLevel = dynamic_cast<Stage*>(GetWorld()->GetGameMode().get());


	NoiseEffect = StageLevel->GetNoise();


	
	

}
CCTVBackGround* CCTVBackGround::GetCCTVBackGround()
{
	return this;
}
void CCTVBackGround::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}




void CCTVBackGround::CCTVON()
{
	CCTVBackGroundRender->SetActive(true);
	CCTVEffect->SetActive(true);
	//NoiseEffect->SetActive(true);
	ChangeEffect->ChangeAnimation("ScanLineAni");
	CamMode = true;
}
void CCTVBackGround::CCTVOFF()
{
	CCTVBackGroundRender->SetActive(false);
	CCTVEffect->SetActive(false);
	//CCTVEffect->SetActive(false);
	//ChangeEffect->SetActive(false);
	CamMode = false;
}


void CCTVBackGround::ChangeCam(std::string _UICamName)
{	
	std::string SpriteName = _UICamName.append(".png");
	
	CCTVBackGroundRender->SetSprite(SpriteName);
}

void CCTVBackGround::ScanLineON()
{
	if (CamMode == true  )
	{
	ChangeEffect->SetActive(true);
	ChangeEffect->ChangeAnimation("ScanLineAni");
	ScanLineEffect();

	ChangeEffect->GetCurInfo();
	}
	

}


void CCTVBackGround::ScanLineEffect()
{

ChangeEffect->SetLastFrameCallback("ScanLineAni",[=]
	{
		ChangeEffect->SetActive(false);
		
		ChangeEffect->GetCurInfo();
		ChangeEffect->AnimationReset();
		ChangeEffect->ChangeAnimation("ScanLineAni");
		
	}
);
}