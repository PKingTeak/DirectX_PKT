#include "PreCompile.h"
#include "Lobby.h"
#include<EngineCore/Camera.h>
#include<EngineCore/EngineDebugMsgWindow.h>
#include"MyCore.h"
#include<EnginePlatform/EngineInput.h>

Lobby::Lobby()
{
	UDefaultSceneComponent* UIDefault = CreateDefaultSubObject<UDefaultSceneComponent>("UIDefault");
	
	

	SetRoot(UIDefault);

}

Lobby::~Lobby()
{
}
void Lobby::BeginPlay()
{
	Super::BeginPlay();
	

	BatteryUI = CreateWidget<UImage>(GetWorld(), "BatteryUI");
	BatteryUI->AddToViewPort(2);
	BatteryUI->SetAutoSize(1.0f, true);
	BatteryUI->SetPosition({ -474,-300,100 });
	BatteryUI->SetSprite("BatteryUI.png");

	UsageText = CreateWidget<UImage>(GetWorld(), "UsageTextUI");
	UsageText->AddToViewPort(2);
	UsageText->SetAutoSize(1.0f, true);
	UsageText->SetPosition({ -575,-300,100 });
	UsageText->SetSprite("UIUsage.png");

	PowerLeftText = CreateWidget<UImage>(GetWorld(), "PowerLeftTextUI");
	PowerLeftText->AddToViewPort(2);
	PowerLeftText->SetAutoSize(1.0f, true);
	PowerLeftText->SetPosition({ -540,-260,100 });
	PowerLeftText->SetSprite("UIPowerLeft.png");

	PerCent = CreateWidget<UImage>(GetWorld(), "PerCentUI");
	PerCent->AddToViewPort(2);
	PerCent->SetAutoSize(1.0f, true);
	PerCent->SetPosition({ -418,-260,100 });
	PerCent->SetSprite("UIPercentage.png");
	
	GageText[0] = CreateWidget<UImage>(GetWorld(), "GageTextUI");
	GageText[0]->AddToViewPort(2);
	GageText[0]->SetAutoSize(1.0f, true);
	GageText[0]->SetPosition({ -450,-260,100 });
	

	GageText[1] = CreateWidget<UImage>(GetWorld(), "GageTextUI2");
	GageText[1]->AddToViewPort(2);
	GageText[1]->SetAutoSize(1.0f, true);
	GageText[1]->SetPosition({ -434,-260,100 });


	
	
	//BatteryGageUI(_DeltaTime);
	//BatteryGageUI();
}

void Lobby::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	if (UEngineInput::IsDown('M'))
	{
		BatteryPower -= 1;
	}

	if (UEngineInput::IsDown('N'))
	{
		if (BatteryUser > 5)
		{
			BatteryUser = 1;
		}
		++BatteryUser;
		
	}
	//BatteryPowerCheck(_DeltaTime);
	Batterypercent();
	BatteryGageUI(_DeltaTime);

}

void Lobby::BatteryPowerCheck(float _DeltaTime, int _limitTime)//���͸� äũ�ϱ� ������ ���� ������ �پ����Լ�
{
	Time += 0.5f* _DeltaTime;
	if (Time > _limitTime)
	{
		Time = 0;
		if (BatteryPower < 0)
		{
			BatteryPower = 0;
		}
		BatteryPower -= 1;
	}

	//BatteryPower -= (1 - _DeltaTime);
	
}
void Lobby::Batterypercent() //���͸� ��ġ ǥ�� 
{

	
	BatteryText = std::to_string(BatteryPower);
	std::string str; // ���� �ϳ��� �̾��ֱ� ���� ��������
	for (int i = 0; i < BatteryText.length(); ++i)
	{

		str = BatteryText.substr(i, 1); //1500 ���� �ϳ��� �������� ���� ��������
		str.append(".png"); //���� �ſ� �߰��� .png�ٿ��� setimage�ҰŴ�

		GageText[i]->SetSprite(str); //�ϳ��� ���
		
	}



}

void Lobby::BatteryGageUI(float _DeltaTime)
{
	std::string BatteryUIName = BatteryUI->GetName();
	switch (BatteryUser)
	{
	case 1:
		
		BatteryUI->SetSprite(BatteryUIName.append(".png"));
		BatteryPowerCheck(_DeltaTime,6);
		//���͸� �Ҹ� ���
		break;
	case 2:
		BatteryUI->SetSprite(BatteryUIName.append("2.png"));
		BatteryPowerCheck(_DeltaTime, 5);
		break;
	case 3:
		BatteryUI->SetSprite(BatteryUIName.append("3.png"));
		BatteryPowerCheck(_DeltaTime, 4);
			break;
	case 4:
		BatteryUI->SetSprite(BatteryUIName.append("4.png"));
		BatteryPowerCheck(_DeltaTime, 3);
		break;
	case 5:
		BatteryUI->SetSprite(BatteryUIName.append("5.png"));
		BatteryPowerCheck(_DeltaTime, 1);
		break;
	default:
		
		break;
	}
	
}

