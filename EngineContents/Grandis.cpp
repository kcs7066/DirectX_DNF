#include "PreCompile.h"
#include "Grandis.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/TimeEventComponent.h>
#include "MyRenderer.h"
#include "EllerinonGameMode.h"
#include "Astaroth.h"

AGrandis::AGrandis()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	GrandisRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BackRenderer = CreateDefaultSubObject<USpriteRenderer>();

	BackRenderer->CreateAnimation("Back", "grandis", 9,32, 0.2f);

	GrandisRenderer->CreateAnimation("grandis_Appearance", "grandis", 0, 0,10.0f);
	GrandisRenderer->CreateAnimation("grandis_Prey", "grandis", 0, 4, 1.2f);
	GrandisRenderer->CreateAnimation("grandis_UpMove", "grandis", 5, 6, 0.5f);
	GrandisRenderer->CreateAnimation("grandis_DownMove", "grandis", 7, 8, 0.5f);

	{
		GrandisRenderer->ChangeAnimation("grandis_Prey");
		GrandisRenderer->SetAutoScaleRatio(1.5f);
		GrandisRenderer->SetWorldLocation({ 100, 400,-10 });
		GrandisRenderer->SetupAttachment(RootComponent);
	}

	{
		BackRenderer->SetAutoScaleRatio(1.5f);
		BackRenderer->SetWorldLocation({ 100, 400,-9 });
		BackRenderer->SetupAttachment(RootComponent);
	}

}
AGrandis::~AGrandis()
{
}

void AGrandis::BeginPlay()
{
	AActor::BeginPlay();

	FSM.CreateState(GrandisState::Appearance, std::bind(&AGrandis::Appearance, this, std::placeholders::_1),
		[this]()
		{
			GrandisRenderer->ChangeAnimation("grandis_Appearance");
		}
	);

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

	FSM.ChangeState(GrandisState::Appearance);

}

void AGrandis::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	DelayTime -= _DeltaTime;
	FSM.Update(_DeltaTime);
}

void AGrandis::Appearance(float _DeltaTime)
{
	if (0.0f > DelayTime)
	{
		FSM.ChangeState(GrandisState::Prey);
		SoundPlayer = UEngineSound::Play("grandis_gracia_01.ogg");
		DelayTime = 6.0f;
	}
}

void AGrandis::Prey(float _DeltaTime)
{

	if (0.0f > DelayTime)
	{
		FSM.ChangeState(GrandisState::UpMove);
		BackRenderer->ChangeAnimation("Back");

		AEllerinonGameMode* GameMode = GetWorld()->GetGameMode<AEllerinonGameMode>();
		GameMode->NewAstaroth = GetWorld()->SpawnActor<AAstaroth>();

		DelayTime = 1.0f;
	}
}

void AGrandis::UpMove(float _DeltaTime)
{
	AddActorLocation({ 0,50 * _DeltaTime,0 });
	if (0.0f > DelayTime)
	{
		FSM.ChangeState(GrandisState::DownMove);
		DelayTime = 1.0f;
	}
}

void AGrandis::DownMove(float _DeltaTime)
{
	AddActorLocation({ 0,-50 * _DeltaTime,0 });

	if (0.0f > DelayTime)
	{
		FSM.ChangeState(GrandisState::UpMove);
		DelayTime = 1.0f;
	}
}