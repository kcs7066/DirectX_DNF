#include "PreCompile.h"
#include "Infighter.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/TimeEventComponent.h>
#include "MyRenderer.h"

AInfighter::AInfighter()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	InfighterRenderer = CreateDefaultSubObject<USpriteRenderer>();

	InfighterRenderer->CreateAnimation("infighter_Idle", "infighter", 0, 196, 0.1f);
	{
		USpriteRenderer::FrameAnimation* Animation = InfighterRenderer->FindAnimation("infighter_Idle");
	}

	InfighterRenderer->ChangeAnimation("infighter_Idle");
	InfighterRenderer->SetAutoScaleRatio(1.5f);
	InfighterRenderer->SetRelativeLocation({ 0,0,-10 });
	InfighterRenderer->SetupAttachment(RootComponent);

	buffRenderer = CreateDefaultSubObject<USpriteRenderer>();
	buffRenderer->CreateAnimation("infighter_buff", "buff", 0, 18, 0.1f);
	{
		USpriteRenderer::FrameAnimation* Animation = InfighterRenderer->FindAnimation("infighter_buff");
	}
	
	buffRenderer->SetRelativeLocation({ 0,150,-20 });
	buffRenderer->SetupAttachment(RootComponent);


    neoRenderer = CreateDefaultSubObject<USpriteRenderer>();
	neoRenderer->CreateAnimation("infighter_neo", "neo", 0, 22, 0.1f);
	{
		USpriteRenderer::FrameAnimation* Animation = InfighterRenderer->FindAnimation("infighter_neo");
	}
	neoRenderer->SetAutoScaleRatio(1.5f);
	neoRenderer->SetWorldLocation({ 0,0,-30 });
	neoRenderer->SetupAttachment(RootComponent);

}

AInfighter::~AInfighter()
{
}

void AInfighter::BeginPlay()
{
	AActor::BeginPlay();
}

void AInfighter::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (UEngineInput::IsPress('A'))
	{
		AddRelativeLocation(FVector{ -Speed * _DeltaTime, 0.0f, 0.0f });
	}
	if (UEngineInput::IsPress('D'))
	{
		AddRelativeLocation(FVector{ Speed * _DeltaTime, 0.0f, 0.0f });
	}

	if (UEngineInput::IsPress('W'))
	{
		AddRelativeLocation(FVector{ 0.0f, Speed * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress('S'))
	{
		AddRelativeLocation(FVector{ 0.0f, -Speed * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress('Q'))
	{
		AddActorRotation(FVector{ 0.0f, 0.0f , 360.0f * _DeltaTime });
	}

	if (UEngineInput::IsPress('E'))
	{
		buffRenderer->ChangeAnimation("infighter_buff");
	}

	if (UEngineInput::IsPress('R'))
	{
		neoRenderer->ChangeAnimation("infighter_neo");
	}

}