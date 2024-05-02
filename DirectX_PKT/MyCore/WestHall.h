#pragma once
class WestHall
{
public:
	// constructor destructor
	WestHall();
	~WestHall();

	// delete Function
	WestHall(const WestHall& _Other) = delete;
	WestHall(WestHall&& _Other) noexcept = delete;
	WestHall& operator=(const WestHall& _Other) = delete;
	WestHall& operator=(WestHall&& _Other) = delete;
};

