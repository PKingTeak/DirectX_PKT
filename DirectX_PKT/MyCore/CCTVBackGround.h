#pragma once
#include <EngineCore/Actor.h>
#include<EngineCore/SpriteRenderer.h>
#include<EngineCore/Collision.h>

// ���� :
class CCTVBackGround : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	CCTVBackGround();
	~CCTVBackGround();

	// delete Function
	CCTVBackGround(const CCTVBackGround& _Other) = delete;
	CCTVBackGround(CCTVBackGround&& _Other) noexcept = delete;
	CCTVBackGround& operator=(const CCTVBackGround& _Other) = delete;
	CCTVBackGround& operator=(CCTVBackGround&& _Other) noexcept = delete;


	void ChangeAnimation();
	
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void RendererOff();
	void RendererOn();
private:
	USpriteRenderer* CCTVBackGroundRender = nullptr;
	




};

