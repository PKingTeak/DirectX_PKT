#include "PreCompile.h"
#include "CCTVBackGround.h"
#include<EngineCore/Collision.h>
#include"MyCore.h"
#include<EngineCore/DefaultSceneComponent.h>

CCTVBackGround* CCTVBackGround::MainCCTV = nullptr;
CCTVBackGround::CCTVBackGround()
{
	
	CCTVBackGroundRender = CreateDefaultSubObject<USpriteRenderer>("CCTVCam");
	CCTVBackGroundRender->SetSprite("TestCamBackGround.png");
	CCTVBackGroundRender->SetAutoSize(1.0f, true);
	CCTVBackGroundRender->SetOrder(100);
	CCTVBackGroundRender->SetActive(false);

	
	SetRoot(CCTVBackGroundRender);

}



CCTVBackGround::~CCTVBackGround()
{
}
void CCTVBackGround::BeginPlay()
{
	CCTVBackGround::MainCCTV = this;
	Super::BeginPlay();

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
	CamMode = true;
}
void CCTVBackGround::CCTVOFF()
{
	CCTVBackGroundRender->SetActive(false);
	CamMode = false;
}
