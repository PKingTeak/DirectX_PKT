#include"PreCompile.h"
#include "MyCore.h"
#include"PlayGameMode.h"

UMyCore::UMyCore()
{
}

UMyCore::~UMyCore()
{
}

void UMyCore::Initialize()
{
	UEngineDirectory Dir;
	Dir.MoveToSearchChild("Resources");
	Dir.Move("Stage");
	std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
	for (UEngineFile& File : Files)
	{
		//File.Open(EIOOpenMode::Read, EIODataType::Binary);

		//char Arr[100];
		//File.Read(Arr, 100);

		UEngineTexture::Load(File.GetFullPath());
	}
	GEngine->CreateLevel<APlayGameMode>("PlayLevel");
	GEngine->ChangeLevel("PlayLevel");

	// GEngine->CreateLevel();
	int a = 0;
}