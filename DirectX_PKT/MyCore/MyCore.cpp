#include"PreCompile.h"
#include "MyCore.h"
#include"PlayGameMode.h"
#include "TitleGameMode.h"
#include <EngineCore/EngineSprite.h>
#include "MainTitleLevel.h"
#include "Stage.h"
#include <EngineCore/EngineEditorGUI.h>
#include <iostream>
#include<EngineCore/EngineDebugMsgWindow.h>
#include"CCTVBackGround.h"
#include<EngineCore/EnginePixelShader.h>


UMyCore::UMyCore()
{
	
}

UMyCore::~UMyCore()
{
}



void UMyCore::Initialize()
{
	UEngineDirectory Dir;
	Dir.MoveToSearchChild("ContentsShader");
	UEngineShader::AutoCompile(Dir);
	{

	std::shared_ptr<UEngineMaterial> Mat = UEngineMaterial::Create("Noise");
	Mat->SetVertexShader("ImageShader.fx");
	Mat->SetPixelShader("ImageShader.fx");
	Mat->SetRasterizer("EngineBase");
	Mat->SetBlend("Overlay");
	
	}
	
	{

	std::shared_ptr<UEngineMaterial> Mat = UEngineMaterial::Create("FishEyes");
	Mat->SetVertexShader("Fisheye.fx");
	Mat->SetPixelShader("Fisheye.fx");

	}



	
	{
		// ������ ���
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("Resources");
		//Dir.Move("JumpScare");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : Files)
		{
			// CuttingTest.png texture�ε� ������ �ε尡 �ư�
			// ��������Ʈ�ε� 1��¥���� �ε尡 �� ��Ȳ�̾�.
			UEngineSprite::Load(File.GetFullPath());
		}

		// �ε������� �̷��� �Ѵٰ� Ĩ�ô�.
		std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			std::string Name = Directorys[i].GetFolderName();
			UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
		}

		
		UEngineSprite::CreateCutting("Chica.png", 1, 16);
		UEngineSprite::CreateCutting("Noise.png", 1, 8);
		UEngineSprite::CreateCutting("Fan.png", 3, 1);
		UEngineSprite::CreateCutting("StageCam.png", 4, 3);
		UEngineSprite::CreateCutting("Button.png",4, 2);
	

		
	}


	{
		//����
		// 
	//	UEngineDirectory Dir;
	//	Dir.MoveToSearchChild("ContentsResources");
	//	Dir.Move("Sound");
	//	std::vector<UEngineFile> Files = Dir.GetAllFile({ ".wav" });
	//	for (UEngineFile& File : Files)
	//	{
	//		//File.Open(EIOOpenMode::Read, EIODataType::Binary);
	//
	//		//char Arr[100];
	//		//File.Read(Arr, 100);
	//
	//		UEngineSound::Load(File.GetFullPath());
	//	}
	//	// UEngineSound::SoundPlay("anipang_ingame_wav.wav");
	}

	
	GEngine->CreateLevel<MainTitleLevel>("Maintitle");
	GEngine->CreateLevel<Stage>("StageLevel");
	GEngine->ChangeLevel("Maintitle");


	

}

void UMyCore::CuttingObject(std::string_view _ObjectName, int _Start, int _End)
{
	UEngineSprite::CreateCutting(_ObjectName, _Start, _End);

}

