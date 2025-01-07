#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

class ALucille : public AActor
{
public:
	ALucille();
	~ALucille();

	ALucille(const ALucille& _Other) = delete;
	ALucille(ALucille&& _Other) noexcept = delete;
	ALucille& operator=(const ALucille& _Other) = delete;
	ALucille& operator=(ALucille&& _Other) noexcept = delete;

	std::shared_ptr<class USpriteRenderer> GetRenderer()
	{
		return LucilleRenderer;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> LucilleRenderer;
};

