#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> GrandisRenderer;
};

