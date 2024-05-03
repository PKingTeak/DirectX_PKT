#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include<EngineCore/DefaultSceneComponent.h>
#include<iostream>
#include<EngineCore/Image.h>
#include"RoomManager.h"
class Animatronics;


// 설명 :
class ShowRoom : public RoomManager
{

	GENERATED_BODY(AActor)

public:


	
	// constrcuter destructer
	ShowRoom();
	~ShowRoom();

	// delete Function
	ShowRoom(const ShowRoom& _Other) = delete;
	ShowRoom(ShowRoom&& _Other) noexcept = delete;
	ShowRoom& operator=(const ShowRoom& _Other) = delete;
	ShowRoom& operator=(ShowRoom&& _Other) noexcept = delete;

	//UImage* GetUI();
	

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void RendererOff();
	void RendererOn();
	void ChangeRoomCamera(Animatronics* _Monster)override;
	


private:
	USpriteRenderer* RoomRender = nullptr;
	Animatronics* Monster = nullptr;
	std::vector<std::string> Statename = { "ShowRoom","ShowRoomWatchCam","ShowStageBonni","ShowStageChica","ShowStageAlone","ShowStageAllGone"};
	//0 일반 1 카메라 바라보기 2 보니만 없어짐 3. 치카만 없어짐 4.곰 혼자 5. 아무도 없음
	
	
	


};

