#pragma once
#include "ContentLevel.h"

// Ό³Έν :
class TutorialLevel : public ContentLevel
{
public:
	// constrcuter destructer
	TutorialLevel();
	~TutorialLevel();

	// delete Function
	TutorialLevel(const TutorialLevel& _Other) = delete;
	TutorialLevel(TutorialLevel&& _Other) noexcept = delete;
	TutorialLevel& operator=(const TutorialLevel& _Other) = delete;
	TutorialLevel& operator=(TutorialLevel&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

private:
	std::shared_ptr<ContentBackground> BackLayer = nullptr;
	std::shared_ptr<ContentBackground> FrontLayer = nullptr;
	std::shared_ptr<class BaseCharacter> Player = nullptr;
	std::shared_ptr<class Target> TargetObject = nullptr;
	std::shared_ptr<class Sphere> Sphere1 = nullptr;
	std::shared_ptr<class Sphere> Sphere2 = nullptr;
	std::shared_ptr<class Sphere> Sphere3 = nullptr;
	std::shared_ptr<class TutorialDoor> ExitDoor = nullptr;
	std::shared_ptr<class FadeAnimation> Fade = nullptr;

	void SetLayerPos();

	bool IsLevelChange = false;
};

