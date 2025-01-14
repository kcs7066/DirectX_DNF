#pragma once
#include <EngineBase/FSMStateManager.h>

#include <EnginePlatform/EngineWinImage.h>

#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

enum class InfighterState
{
	Idle,
	Move,
	Jump,
	Attack,

	Skill,
	Ducking,
	Sway,
	Roll,

	Hit,
	Die
};

class AInfighter : public AActor
{
public:

	AInfighter();
	~AInfighter();


	AInfighter(const AInfighter& _Other) = delete;
	AInfighter(AInfighter&& _Other) noexcept = delete;
	AInfighter& operator=(const AInfighter& _Other) = delete;
	AInfighter& operator=(AInfighter&& _Other) noexcept = delete;

	std::shared_ptr<class USpriteRenderer> GetRenderer()
	{
		return InfighterRenderer;
	}

	void Idle(float _DeltaTime);
	void Move(float _DeltaTime);
	void Jump(float _DeltaTime);
	void Attack(float _DeltaTime);

	void Skill(float _DeltaTime);
	void Ducking(float _DeltaTime);
	void Sway(float _DeltaTime);
	void Roll(float _DeltaTime);

	void HitStart();
	void Hit(float _DeltaTime);
	void DieStart();
	void Die(float _DeltaTime);


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> InfighterRenderer;
	std::shared_ptr<class USpriteRenderer> buffRenderer;
	std::shared_ptr<class USpriteRenderer> neoRenderer;

	int Speed = 300;
	float Delaytime = 0.0f;
	bool IsMonster = false;
	bool DashValue = false;

	FVector DuckingDir = {0,0};

	UFSMStateManager FSM = UFSMStateManager();
};

