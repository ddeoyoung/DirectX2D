#pragma once
#include "ContentLevel.h"

// Ό³Έν :
class OutroLevel : public ContentLevel
{
public:
	// constrcuter destructer
	OutroLevel();
	~OutroLevel();

	// delete Function
	OutroLevel(const OutroLevel& _Other) = delete;
	OutroLevel(OutroLevel&& _Other) noexcept = delete;
	OutroLevel& operator=(const OutroLevel& _Other) = delete;
	OutroLevel& operator=(OutroLevel&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

private:
	std::shared_ptr<class StoryBook> Storybook = nullptr;
	std::shared_ptr<class FadeAnimation> FadeOut = nullptr;

	float FadeOutTime = 0.0f;
};

