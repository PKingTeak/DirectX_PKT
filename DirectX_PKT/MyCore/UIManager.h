#pragma once
#include<EngineCore/GameMode.h>
#include<EngineCore/SpriteRenderer.h>
#include<EngineCore/Widget.h>
// Ό³Έν :
class UIManager : public UWidget
{
	GENERATED_BODY(UWidget)

public:
	
	UIManager();
	~UIManager();

	// delete Function
	UIManager(const UIManager& _Other) = delete;
	UIManager(UIManager&& _Other) noexcept = delete;
	UIManager& operator=(const UIManager& _Other) = delete;
	UIManager& operator=(UIManager&& _Other) noexcept = delete;

protected:
	void MaterialSettingEnd() override;
private:
	std::shared_ptr<UWidget> UI;
	void SetUI();
	

};

