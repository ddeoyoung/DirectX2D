#pragma once
#include <GameEngineCore\GameEngineActor.h>

#define PAGEDUR 0.03f

// Ό³Έν :
class StoryBook : public GameEngineActor
{
public:
	// constrcuter destructer
	StoryBook();
	~StoryBook();

	// delete Function
	StoryBook(const StoryBook& _Other) = delete;
	StoryBook(StoryBook&& _Other) noexcept = delete;
	StoryBook& operator=(const StoryBook& _Other) = delete;
	StoryBook& operator=(StoryBook&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	int PageNumber = 1;
	float PageDur = 0.0f;

	std::shared_ptr<class GameEngineSpriteRenderer> Renderer;
};

