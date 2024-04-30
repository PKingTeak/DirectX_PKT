#pragma once

#include<EngineCore/Actor.h>
#include<EngineCore/Renderer.h>
#include<EngineCore/SpriteRenderer.h>
class BackStageGround;
class StageBackGroundClass;
class Stage;
class Door;
class Button : public AActor
{
private:
	static Button* MainButton;
	

	GENERATED_BODY(AActor)
public:
	Button();
	~Button();

	// delete Function
	Button(const Button& _Other) = delete;
	Button(Button&& _Other) noexcept = delete;
	Button& operator=(const Button& _Other) = delete;
	Button& operator=(Button&& _Other) noexcept = delete;

	void MoveButton(FVector _SetPos);
	void ButtonLight(std::string _ButtonName);
	void ButtonDoor(std::string _ButtonName);

	inline bool LDoorButtonCheck()
	{
		return LeftDoor;
	}
	inline bool RDoorBUttonCheck()
	{
		return RightDoor;
	}

	inline Button* GetMainButton()
	{
		return MainButton;
	}


	

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


	void RendererOff();
	void RendererOn();
private:
	

	USpriteRenderer* LeftButtonRender = nullptr;
	UCollision* LeftDoorButton = nullptr;
	UCollision* LeftLightButton = nullptr;

	USpriteRenderer* RightButtonRender = nullptr;
	UCollision* RightDoorButton = nullptr;
	UCollision* RightLightButton = nullptr;

	bool LeftLight = false;
	bool LeftDoor = false;
	bool RightLight = false;
	bool RightDoor = false;

};

