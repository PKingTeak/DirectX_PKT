#pragma once
class WestHallCorner
{
public:
	// constructor destructor
	WestHallCorner();
	~WestHallCorner();

	// delete Function
	WestHallCorner(const WestHallCorner& _Other) = delete;
	WestHallCorner(WestHallCorner&& _Other) noexcept = delete;
	WestHallCorner& operator=(const WestHallCorner& _Other) = delete;
	WestHallCorner& operator=(WestHallCorner&& _Other) = delete;
};

