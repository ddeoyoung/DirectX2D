#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class ContentLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	ContentLevel();
	~ContentLevel();

	// delete Function
	ContentLevel(const ContentLevel& _Other) = delete;
	ContentLevel(ContentLevel&& _Other) noexcept = delete;
	ContentLevel& operator=(const ContentLevel& _Other) = delete;
	ContentLevel& operator=(ContentLevel&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;
private:

};

