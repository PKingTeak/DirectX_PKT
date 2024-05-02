#pragma once
class SupplyCloset
{
public:
	// constructor destructor
	SupplyCloset();
	~SupplyCloset();

	// delete Function
	SupplyCloset(const SupplyCloset& _Other) = delete;
	SupplyCloset(SupplyCloset&& _Other) noexcept = delete;
	SupplyCloset& operator=(const SupplyCloset& _Other) = delete;
	SupplyCloset& operator=(SupplyCloset&& _Other) = delete;
};

