#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include<EngineCore/DefaultSceneComponent.h>
#include<iostream>
#include<EngineCore/Image.h>
#include"RoomManager.h"
class Animatronics;


// ���� :
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
	void SettingSpriteName(int _index) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void RendererOff();
	void RendererOn();
	void MapUpdate()override;
	
	


private:
	USpriteRenderer* RoomRender = nullptr;
	Animatronics* Monster = nullptr;
	std::vector<std::string> RoomStatename = { "ShowRoom","ShowRoomWatchCam","ShowStageBonni","ShowStageChica","ShowStageAlone","ShowStageAllGone"};
	//0 �Ϲ� 1 ī�޶� �ٶ󺸱� 2 ���ϸ� ������ 3. ġī�� ������ 4.�� ȥ�� 5. �ƹ��� ����
	
	
	


};

