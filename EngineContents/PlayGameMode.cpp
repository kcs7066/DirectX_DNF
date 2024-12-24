#include "PreCompile.h"
#include "PlayGameMode.h"
#include "TestImage.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>

APlayGameMode::APlayGameMode()
{
	{
		std::shared_ptr<ATestImage> Logo = GetWorld()->SpawnActor<ATestImage>();
		Logo->SetActorLocation({ 300.0f, 0.0f, 0.0f });
		Logo->GetRenderer()->SetSpriteData({ 0.0f, 0.0f }, { 0.5f, 0.5f });
	}

	{
		std::shared_ptr<ATestImage> Logo = GetWorld()->SpawnActor<ATestImage>();
		Logo->SetActorLocation({ -300.0f, 0.0f, 0.0f });
	}

	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });
}

APlayGameMode::~APlayGameMode()
{

}

void APlayGameMode::Tick(float _DeltaTime)
{

	AActor::Tick(_DeltaTime);


}