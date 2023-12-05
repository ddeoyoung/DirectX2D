#pragma once
#include <GameEngineCore\GameEngineActor.h>

#define PAGEDUR 0.03f

enum class StoryType
{
	None,
	Intro,
	Outro,
};

// Ό³Έν :
class StoryBook : public ContentActor
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


	void SetStoryBook(StoryType _StoryType);

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	int PageNumber = 1;
	float PageDur = 0.0f;

	std::shared_ptr<class GameEngineSpriteRenderer> Renderer;
};

