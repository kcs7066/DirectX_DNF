#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

class ATestImage : public AActor
{
public:

	ATestImage();
	~ATestImage();


	ATestImage(const ATestImage& _Other) = delete;
	ATestImage(ATestImage&& _Other) noexcept = delete;
	ATestImage& operator=(const ATestImage& _Other) = delete;
	ATestImage& operator=(ATestImage&& _Other) noexcept = delete;

	std::shared_ptr<class USpriteRenderer> GetRenderer()
	{
		return TestRenderer;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> TestRenderer;
	std::shared_ptr<class USpriteRenderer> Child;
};

