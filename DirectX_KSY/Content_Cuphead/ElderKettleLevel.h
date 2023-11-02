#pragma once
#include "ContentLevel.h"

// Ό³Έν :
class ElderKettleLevel : public ContentLevel
{
public:
	// constrcuter destructer
	ElderKettleLevel();
	~ElderKettleLevel();

	// delete Function
	ElderKettleLevel(const ElderKettleLevel& _Other) = delete;
	ElderKettleLevel(ElderKettleLevel&& _Other) noexcept = delete;
	ElderKettleLevel& operator=(const ElderKettleLevel& _Other) = delete;
	ElderKettleLevel& operator=(ElderKettleLevel&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

	void TutorialEnterInteraction();

private:
	std::shared_ptr<class ElderKettle> Kettle = nullptr;
	std::shared_ptr<class EnterMessage> EnterBubble = nullptr;
	std::shared_ptr<class FadeAnimation> Fade = nullptr;

	bool IsLevelChange = false;
};

