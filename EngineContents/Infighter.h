#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> InfighterRenderer;
	std::shared_ptr<class USpriteRenderer> buffRenderer;
	std::shared_ptr<class USpriteRenderer> neoRenderer;

	int Speed = 300;
};

