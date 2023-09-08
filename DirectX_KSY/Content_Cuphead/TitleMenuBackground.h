#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class TitleMenuBackground : public GameEngineActor
{
public:
	// constrcuter destructer
	TitleMenuBackground();
	~TitleMenuBackground();

	// delete Function
	TitleMenuBackground(const TitleMenuBackground& _Other) = delete;
	TitleMenuBackground(TitleMenuBackground&& _Other) noexcept = delete;
	TitleMenuBackground& operator=(const TitleMenuBackground& _Other) = delete;
	TitleMenuBackground& operator=(TitleMenuBackground&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> Renderer;
};

