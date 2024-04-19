#pragma once
#include <EngineCore/EngineRenderTarget.h>

// Ό³Έν :
class FishEyes : public UEffect
{
public:
	// constrcuter destructer
	FishEyes();
	~FishEyes();

	// delete Function
	FishEyes(const FishEyes& _Other) = delete;
	FishEyes(FishEyes&& _Other) noexcept = delete;
	FishEyes& operator=(const FishEyes& _Other) = delete;
	FishEyes& operator=(FishEyes&& _Other) noexcept = delete;

protected:
	void Init() override;
	void Effect(std::shared_ptr<UEngineRenderTarget> EffectTarget) override;


private:
	std::shared_ptr<UEngineRenderTarget> CopyTarget;
	
};

