#include "PreCompile.h"
#include "ScanLine.h"
#include<EngineCore/Collision.h>
#include"MyCore.h"
#include<EngineCore/DefaultSceneComponent.h>


ScanLine::ScanLine()
{
	UDefaultSceneComponent* Default = CreateDefaultSubObject<UDefaultSceneComponent>("Default");
	Default->SetPosition(FVector{ 0,0 });
	
	

	//ScanLineRender = CreateDefaultSubObject<USpriteRenderer>("SccanLineRender");
	//ScanLineRender->SetupAttachment(Default);
//	//ScanLineRender->SetMaterial("Noise");
	//ScanLineRender->SetAutoSize(1.0f, true);
	//ScanLineRender->SetPosition({ 0,0 });
	//ScanLineRender->CreateAnimation("ScanLineAni", "CCTVEffect", 0.1f, false, 0, 8);
	//ScanLineRender->SetOrder(OrderType::Overlay);

	SetRoot(Default);

}

ScanLine::~ScanLine()
{
}


void ScanLine::BeginPlay()
{
	Super::BeginPlay();
	ScanLineUIImage = CreateWidget<UImage>(GetWorld(), "ScanLine");
	//ScanLineUIImage->SetMaterial("Noise");
	ScanLineUIImage->AddToViewPort(2);
	ScanLineUIImage->SetAutoSize(1.0f, true);
	ScanLineUIImage->SetPosition({ 0,0,100 });
	//ScanLineUIImage->SetMaterial("Noise");
	ScanLineUIImage->CreateAnimation("ScanLineAni", "CCTVEffect", 0.1f, false, 0, 8);





}
void ScanLine::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
void ScanLine::ScanLineLoad()
{
	if (false == ScanLineUIImage->IsActive())
	{
		ScanLineUIImage->SetActive(true);
	}

	ScanLineUIImage->ChangeAnimation("ScanLineAni");
	ScanLineUIImage->SetFrameCallback("ScanLineAni", 8, [=]
		{
			ScanLineUIImage->SetActive(false);
		}
	);
}