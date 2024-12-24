#include "PreCompile.h"
#include "TestImage.h"
#include <EngineCore/SpriteRenderer.h>

ATestImage::ATestImage()
{
	// 랜더러를 만든다.
	TestRenderer = CreateDefaultSubObject<USpriteRenderer>();
	TestRenderer->SetSprite("Test.png");


	SetActorRelativeScale3D({ 600.0f, 600.0f, 1.0f });
	// SetActorLocation({ 200.0f, 100.0f, 1.0f });
}

ATestImage::~ATestImage()
{
}

void ATestImage::BeginPlay()
{
	AActor::BeginPlay();
}

void ATestImage::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	// AddActorLocation(FVector{ 0.001f, 0.0f, 0.0f});
}