#pragma once
class EastHallCorner
{
public:
	// constructor destructor
	EastHallCorner();
	~EastHallCorner();

	// delete Function
	EastHallCorner(const EastHallCorner& _Other) = delete;
	EastHallCorner(EastHallCorner&& _Other) noexcept = delete;
	EastHallCorner& operator=(const EastHallCorner& _Other) = delete;
	EastHallCorner& operator=(EastHallCorner&& _Other) = delete;
};

