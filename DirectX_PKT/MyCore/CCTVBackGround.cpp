#include "PreCompile.h"
#include "CCTVBackGround.h"
#include<EngineCore/Collision.h>
#include"MyCore.h"
#include<EngineCore/DefaultSceneComponent.h>
#include"Noise.h"
#include"Stage.h"
#include"Bonni.h"
#include"RoomManager.h"


CCTVBackGround::CCTVBackGround()
{

	UDefaultSceneComponent* Default = CreateDefaultSubObject<UDefaultSceneComponent>("Default");


	CCTVBackGroundRender = CreateDefaultSubObject<USpriteRenderer>("CCTVCam");
	CCTVBackGroundRender->SetupAttachment(Default);
	CCTVBackGroundRender->SetSprite("TestCamBackGround.png");
	CCTVBackGroundRender->SetAutoSize(1.0f, true);
	CCTVBackGroundRender->SetOrder(50);
	CCTVBackGroundRender->SetActive(false);


	ChangeSpriteRender = CreateDefaultSubObject<USpriteRenderer>("ChangeCCTVCam");
	ChangeSpriteRender->SetupAttachment(Default);
	ChangeSpriteRender->SetSprite("Void.png");
	ChangeSpriteRender->SetAutoSize(1.0f, true);
	ChangeSpriteRender->SetOrder(55);
	ChangeSpriteRender->SetActive(false);


	CCTVEffect = CreateDefaultSubObject<USpriteRenderer>("CCTVEffect");


	CCTVEffect->SetupAttachment(Default);
	CCTVEffect->SetMaterial("Noise");
	CCTVEffect->SetOrder(101);
	CCTVEffect->SetScale({ 1600,720 });
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
	BonniCam = StageLevel->GetStageBonni();
	NoiseEffect = StageLevel->GetNoise();
	
	
//	for (int i = static_cast<int>(BonniLocation::Cam1A); i <= static_cast<in  t>(BonniLocation::Lobby); i++)
//	{
//
//		//CCTVBonniLocal[i] = BonniLocalName[i];
//
//
//	}


	
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
	ChangeEffect->ChangeAnimation("ScanLineAni");
	CamMode = true;
	
	
}
void CCTVBackGround::CCTVOFF()
{
	CCTVBackGroundRender->SetActive(false);
	CCTVEffect->SetActive(false);
	AllCamActorOff();


	CamMode = false;
	if (CCTVInfo == nullptr)
	{
		return;
	}
	CCTVInfo->SetActive(false); //다음화면 켜주기 
}

void CCTVBackGround::ChangeCam(RoomManager* _UICamName)
{
	if (_UICamName == nullptr)
	{
		return;
	}
	if (_UICamName->GetMonster() != nullptr)
	{
		_UICamName->GetCurRoomSpriteName();


	}
	std::string ChangeCamName = _UICamName->GetCurRoomSpriteName();
	ChangeCamName.append(".png");

	CCTVBackGroundRender->SetSprite(ChangeCamName);
}

/*
void CCTVBackGround::ChangeCam(std::string _UICamName)
{
	std::string SpriteName = _UICamName.append(".png");  // 이름이 들어오면 바꿔줌

	
	//화면 이름을 가져와야함 현재 카메라 이름 


	//CCTVInfo->SetActive(true); //다음화면 켜주기 
	//if (PreCCTVInfo == nullptr)
	//{
	//	return;
	//}
	//PreCCTVInfo->SetActive(false);	//이전 화면 꺼주기

	//여기서 해당하는 화면을 켜주는것이 좋을듯 하다. 

	CCTVBackGroundRender->SetSprite(SpriteName);
}

*/
void CCTVBackGround::ScanLineON()
{ 
	//화면 지지직 
	if (CamMode == true)
	{
		ChangeEffect->SetActive(true);
		ChangeEffect->ChangeAnimation("ScanLineAni");
		ScanLineEffect();

		ChangeEffect->GetCurInfo();
	}


}


void CCTVBackGround::ScanLineEffect()
{

	ChangeEffect->SetLastFrameCallback("ScanLineAni", [=]
		{
			ChangeEffect->SetActive(false);

			ChangeEffect->GetCurInfo();
			ChangeEffect->AnimationReset();
			ChangeEffect->ChangeAnimation("ScanLineAni");

		}
	);
}



void CCTVBackGround::ChangeSprite(std::string _ChangeCam)
{
	_ChangeCam.append(".png");
	std::string ChangeLocalName = _ChangeCam.substr(2);
	
	ChangeSpriteRender->SetSprite(ChangeLocalName);
	ChangeSpriteRender->SetActive(true);

}


void CCTVBackGround::GetCamera(RoomManager* _ChangeRoom)
{
	_ChangeRoom->SetActive(true);
}

void CCTVBackGround::SetCamBackInfo(RoomManager* _CamInfo , bool _CurCheck)
{//카메라 배경 
	if (_CurCheck == false)
	{
		PreCCTVInfo = _CamInfo;
	}
	CCTVInfo = _CamInfo;
}
void CCTVBackGround::AllCamActorOff()
{
	StageLevel = dynamic_cast<Stage*>(GetWorld()->GetGameMode().get());
	CCTVActors = StageLevel->GetCamActor();
	for (int i = 0; i < CCTVActors.size(); i++)
	{
		CCTVActors[i].get()->SetActive(false);
	}

}