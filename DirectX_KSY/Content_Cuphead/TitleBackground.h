#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class TitleBackground : public ContentActor
{
public:
	// constrcuter destructer
	TitleBackground();
	~TitleBackground();

	// delete Function
	TitleBackground(const TitleBackground& _Other) = delete;
	TitleBackground(TitleBackground&& _Other) noexcept = delete;
	TitleBackground& operator=(const TitleBackground& _Other) = delete;
	TitleBackground& operator=(TitleBackground&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> Renderer;
	std::shared_ptr<class GameEngineSpriteRenderer> PressKeyRenderer;

	float PressKeyTime = 0.0f;
};

