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
	GEngine->CreateLevel<APlayGameMode>("PlayLevel");
	GEngine->ChangeLevel("PlayLevel");

	// GEngine->CreateLevel();
	int a = 0;
}