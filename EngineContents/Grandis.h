#pragma once

#include <EngineBase/FSMStateManager.h>

#include <EnginePlatform/EngineWinImage.h>

#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

enum class GrandisState
{
	Prey,
	UpMove,
	DownMove

};

class AGrandis : public AActor
{
public:
	AGrandis();
	~AGrandis();

	AGrandis(const AGrandis& _Other) = delete;
	AGrandis(AGrandis&& _Other) noexcept = delete;
	AGrandis& operator=(const AGrandis& _Other) = delete;
	AGrandis& operator=(AGrandis&& _Other) noexcept = delete;

	std::shared_ptr<class USpriteRenderer> GetRenderer()
	{
		return GrandisRenderer;
	}

	void Prey(float _DeltaTime);
	void UpMove(float _DeltaTime);
	void DownMove(float _DeltaTime);
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> GrandisRenderer;
	std::shared_ptr<class USpriteRenderer> BackRenderer;
	UFSMStateManager FSM = UFSMStateManager();

	float DelayTime = 3.0f;
};

