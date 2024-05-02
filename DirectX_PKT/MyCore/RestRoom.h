#pragma once
class RestRoom
{
public:
	// constructor destructor
	RestRoom();
	~RestRoom();

	// delete Function
	RestRoom(const RestRoom& _Other) = delete;
	RestRoom(RestRoom&& _Other) noexcept = delete;
	RestRoom& operator=(const RestRoom& _Other) = delete;
	RestRoom& operator=(RestRoom&& _Other) = delete;
};

