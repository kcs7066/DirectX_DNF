#include "PreCompile.h"
#include "Grandis.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/TimeEventComponent.h>
#include "MyRenderer.h"

AGrandis::AGrandis()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	GrandisRenderer = CreateDefaultSubObject<USpriteRenderer>();

	GrandisRenderer->CreateAnimation("grandis_Prey", "grandis", 0, 4, 0.6f);
	GrandisRenderer->CreateAnimation("grandis_UpMove", "grandis", 5, 6, 0.5f);
	GrandisRenderer->CreateAnimation("grandis_DownMove", "grandis", 7, 8, 0.5f);

	{
		GrandisRenderer->ChangeAnimation("grandis_Prey");
		GrandisRenderer->SetAutoScaleRatio(1.5f);
		GrandisRenderer->SetWorldLocation({ 100, 400,-10 });
		GrandisRenderer->SetupAttachment(RootComponent);
	}
}
AGrandis::~AGrandis()
{
}

void AGrandis::BeginPlay()
{
	AActor::BeginPlay();

	FSM.CreateState(GrandisState::Prey, std::bind(&AGrandis::Prey, this, std::placeholders::_1),
		[this]()
		{
			GrandisRenderer->ChangeAnimation("grandis_Prey");
		}
	);

	FSM.CreateState(GrandisState::UpMove, std::bind(&AGrandis::UpMove, this, std::placeholders::_1),
		[this]()
		{
			GrandisRenderer->ChangeAnimation("grandis_UpMove");
		}
	);

	FSM.CreateState(GrandisState::DownMove, std::bind(&AGrandis::DownMove, this, std::placeholders::_1),
		[this]()
		{
			GrandisRenderer->ChangeAnimation("grandis_DownMove");
		}
	);

	FSM.ChangeState(GrandisState::Prey);
}

void AGrandis::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	FSM.Update(_DeltaTime);
}

void AGrandis::Prey(float _DeltaTime)
{
	DelayTime -= _DeltaTime;

	if (0.0f > DelayTime)
	{
		FSM.ChangeState(GrandisState::UpMove);
		DelayTime = 1.0f;
	}
}

void AGrandis::UpMove(float _DeltaTime)
{
	DelayTime -= _DeltaTime;
	AddActorLocation({ 0,50 * _DeltaTime,0 });
	if (0.0f > DelayTime)
	{
		FSM.ChangeState(GrandisState::DownMove);
		DelayTime = 1.0f;
	}
}

void AGrandis::DownMove(float _DeltaTime)
{
	DelayTime -= _DeltaTime;
	AddActorLocation({ 0,-50 * _DeltaTime,0 });

	if (0.0f > DelayTime)
	{
		FSM.ChangeState(GrandisState::UpMove);
		DelayTime = 1.0f;
	}
}