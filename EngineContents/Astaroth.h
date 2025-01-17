#pragma once
#include <EngineBase/FSMStateManager.h>

#include <EnginePlatform/EngineWinImage.h>

#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>


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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> AstarothRenderer;

	UFSMStateManager FSM = UFSMStateManager();
};

