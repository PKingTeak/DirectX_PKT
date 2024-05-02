#pragma once
class PirateRoom
{
public:
	// constructor destructor
	PirateRoom();
	~PirateRoom();

	// delete Function
	PirateRoom(const PirateRoom& _Other) = delete;
	PirateRoom(PirateRoom&& _Other) noexcept = delete;
	PirateRoom& operator=(const PirateRoom& _Other) = delete;
	PirateRoom& operator=(PirateRoom&& _Other) = delete;
};

