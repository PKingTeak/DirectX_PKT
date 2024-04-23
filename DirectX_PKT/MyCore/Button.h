#pragma once

#include<EngineCore/Actor.h>
#include<EngineCore/Renderer.h>
#include<EngineCore/SpriteRenderer.h>
class BackStageGround;
class Button : public AActor
{
	
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
	void ButtonClick();
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

	void ButtonLight();
	void ButtonDoor();
};

