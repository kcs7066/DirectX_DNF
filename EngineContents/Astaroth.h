#pragma once
#include <EngineBase/FSMStateManager.h>
#include <EngineBase/EngineRandom.h>

#include <EnginePlatform/EngineWinImage.h>
#include <EnginePlatform/EngineSound.h>

#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

enum class AstarothState
{
	Appearance,
	Idle,
	Move,
	RushReady,
	Rush,
	Trace,
	Jump,
	Landing,
	AfterImageStart,
	AfterImageReady,
	AfterImage,
	BorderTime,
	Groggy,
	Die

};

class AAstaroth : public AActor
{
public:
	AAstaroth();
	~AAstaroth();

	AAstaroth(const AAstaroth& _Other) = delete;
	AAstaroth(AAstaroth&& _Other) noexcept = delete;

	AAstaroth& operator=(const AAstaroth& _Other) = delete;
	AAstaroth& operator=(AAstaroth&& _Other) noexcept = delete;

	std::shared_ptr<class USpriteRenderer> GetRenderer()
	{
		return AstarothRenderer;
	}

	void Appearance(float _DeltaTime);
	void Idle(float _DeltaTime);
	void Move(float _DeltaTime);
	void RushReady(float _DeltaTime);
	void Rush(float _DeltaTime);
	void Trace(float _DeltaTime);
	void Jump(float _DeltaTime);
	void Landing(float _DeltaTime);
	void AfterImage(float _DeltaTime);
	void AfterImageReady(float _DeltaTime);
	void AfterImageStart(float _DeltaTime);
	void BorderTime(float _DeltaTime);
	void Groggy(float _DeltaTime);
	void Die(float _DeltaTime);


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> AstarothRenderer;

	UFSMStateManager FSM = UFSMStateManager();
	UEngineRandom Random;
	USoundPlayer SoundPlayer;

	int AfterImageValue = 4;
	float DelayTime = 1.4f;
	bool SeeRight = false;
	FVector RushDir;
	FVector PlayerPos;

	void DirChange()
	{
		if (false == SeeRight)
		{
			RootComponent->SetScale3D({ -1,1 });
		}
		else
		{
			RootComponent->SetScale3D({ 1,1 });
		}
	}
};

