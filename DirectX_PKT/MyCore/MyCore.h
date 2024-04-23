#pragma once
#include <EngineCore/EngineCore.h>
#include<string>
#include<string_view>
enum class OrderType
{
	BackGround,
	Object,
	UI,
	Mouse

};
// Ό³Έν :
class UMyCore : public UserCore
{
public:
	// constrcuter destructer
	UMyCore();
	~UMyCore();

	// delete Function
	UMyCore(const UMyCore& _Other) = delete;
	UMyCore(UMyCore&& _Other) noexcept = delete;
	UMyCore& operator=(const UMyCore& _Other) = delete;
	UMyCore& operator=(UMyCore&& _Other) noexcept = delete;

	void CuttingObject(std::string_view _ObjectName, int _SizeX, int _SizeY);
protected:
	void Initialize() override;


private:

};

