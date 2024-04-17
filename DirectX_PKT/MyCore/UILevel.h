#pragma once
#include<EngineCore/GameMode.h>
#include<EngineCore/SpriteRenderer.h>
#include<EngineCore/Widget.h>
// Ό³Έν :
class UILevel : public AActor
{
	GENERATED_BODY(AActor)

public:
	
	UILevel();
	~UILevel();

	// delete Function
	UILevel(const UILevel& _Other) = delete;
	UILevel(UILevel&& _Other) noexcept = delete;
	UILevel& operator=(const UILevel& _Other) = delete;
	UILevel& operator=(UILevel&& _Other) noexcept = delete;

protected:
	
private:
	//std::shared_ptr<UWidget>
	

};

