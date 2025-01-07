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

	InfighterRenderer->CreateAnimation("infighter_Idle", "infighter", 0, 196, 0.2f);
	{
		USpriteRenderer::FrameAnimation* Animation = InfighterRenderer->FindAnimation("infighter_Idle");
	}

	InfighterRenderer->ChangeAnimation("infighter_Idle");
	InfighterRenderer->SetRelativeScale3D({ 50, 50, -1.0f });
	InfighterRenderer->SetWorldLocation({ 0,0,-10 });
	InfighterRenderer->SetupAttachment(RootComponent);

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
		AddRelativeLocation(FVector{ -100.0f * _DeltaTime, 0.0f, 0.0f });
	}
	if (UEngineInput::IsPress('D'))
	{
		AddRelativeLocation(FVector{ 100.0f * _DeltaTime, 0.0f, 0.0f });
	}

	if (UEngineInput::IsPress('W'))
	{
		AddRelativeLocation(FVector{ 0.0f, 100.0f * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress('S'))
	{
		AddRelativeLocation(FVector{ 0.0f, -100.0f * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress('Q'))
	{
		AddActorRotation(FVector{ 0.0f, 0.0f , 360.0f * _DeltaTime });
	}

	if (UEngineInput::IsPress('E'))
	{
		//InfighterRenderer->ChangeAnimation("Move");
	}

	if (UEngineInput::IsPress('R'))
	{
		InfighterRenderer->ChangeAnimation("Idle");
	}

}