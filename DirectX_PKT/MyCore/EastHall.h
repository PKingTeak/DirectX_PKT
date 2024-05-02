#pragma once
class EastHall
{
public:
	// constructor destructor
	EastHall();
	~EastHall();

	// delete Function
	EastHall(const EastHall& _Other) = delete;
	EastHall(EastHall&& _Other) noexcept = delete;
	EastHall& operator=(const EastHall& _Other) = delete;
	EastHall& operator=(EastHall&& _Other) = delete;
};

