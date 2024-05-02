#pragma once
class BackStage
{
public:
	// constructor destructor
	BackStage();
	~BackStage();

	// delete Function
	BackStage(const BackStage& _Other) = delete;
	BackStage(BackStage&& _Other) noexcept = delete;
	BackStage& operator=(const BackStage& _Other) = delete;
	BackStage& operator=(BackStage&& _Other) = delete;
};

