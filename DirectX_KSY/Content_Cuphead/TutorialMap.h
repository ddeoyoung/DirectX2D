#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class TutorialMap : public GameEngineActor
{
public:
	// constrcuter destructer
	TutorialMap();
	~TutorialMap();

	// delete Function
	TutorialMap(const TutorialMap& _Other) = delete;
	TutorialMap(TutorialMap&& _Other) noexcept = delete;
	TutorialMap& operator=(const TutorialMap& _Other) = delete;
	TutorialMap& operator=(TutorialMap&& _Other) noexcept = delete;

protected:
	void Start() override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> Renderer;
};

