#pragma once
class KittenRoom
{
public:
	// constructor destructor
	KittenRoom();
	~KittenRoom();

	// delete Function
	KittenRoom(const KittenRoom& _Other) = delete;
	KittenRoom(KittenRoom&& _Other) noexcept = delete;
	KittenRoom& operator=(const KittenRoom& _Other) = delete;
	KittenRoom& operator=(KittenRoom&& _Other) = delete;
};

