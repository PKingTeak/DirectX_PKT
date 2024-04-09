#include"PreCompile.h"
#include "MyCore.h"
#include"PlayGameMode.h"
#include "TitleGameMode.h"
#include <EngineCore/EngineSprite.h>
#include "MainTitleLevel.h"

UMyCore::UMyCore()
{
}

UMyCore::~UMyCore()
{
}

void UMyCore::Initialize()
{

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

		// Ư�� ��������Ʈ�� 
		// Ư�� �ؽ�ó�� ã�Ƽ�
		// ���� ��������Ʈ�� �������� �ʴ´ٸ�
		// �̰� ����ϴ� ���� ������ �ڸ���.
		// �̹� �� �̸��� ���� ��������Ʈ�� �����Ѵ�.
		// �׷��� ������ ��������Ʈ �����ʹ� ����������
		// �ڸ� ��������Ʈ ������ �����Ѵ�.
		UEngineSprite::CreateCutting("Chica.png", 1, 16);
		UEngineSprite::CreateCutting("TITLE.png", 1, 4);

		
	}


	{
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

	GEngine->CreateLevel<APlayGameMode>("PlayLevel");
	GEngine->CreateLevel<ATitleGameMode>("TitleLevel");
	GEngine->CreateLevel<MainTitleLevel>("Maintitle");
	GEngine->ChangeLevel("Maintitle");


}