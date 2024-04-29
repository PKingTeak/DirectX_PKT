#include "PreCompile.h"
#include "CCTVUI.h"
#include<EngineCore/Collision.h>
#include"MyCore.h"
#include<EngineCore/DefaultSceneComponent.h>


CCTVUI::CCTVUI()
{
	UDefaultSceneComponent* Default = CreateDefaultSubObject<UDefaultSceneComponent>("Default");
	Default->SetPosition(FVector{ 0,0 });

	SetRoot(Default);

}

CCTVUI::~CCTVUI()
{
}


void CCTVUI::BeginPlay()
{
	Super::BeginPlay();
	CCTVUIImage = CreateWidget<UImage>(GetWorld(), "CCTVUI");
	CCTVUIImage->AddToViewPort(2);
	CCTVUIImage->SetAutoSize(1.0f, true);
	CCTVUIImage->SetPosition({ 0,0,100 });
	CCTVUIImage->SetSprite("CCTVBackBackUI.png");
	//CCTVUIUIImage->CreateAnimation("CCTVUIAni", "CCTVEffect", 0.1f, false, 0, 8);





}
void CCTVUI::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
