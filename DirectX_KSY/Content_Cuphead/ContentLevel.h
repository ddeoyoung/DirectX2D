#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class ContentBackground;
class ContentLevel : public GameEngineLevel
{
	static ContentLevel* CurLevel;
public:
	// constrcuter destructer
	ContentLevel();
	~ContentLevel();

	// delete Function
	ContentLevel(const ContentLevel& _Other) = delete;
	ContentLevel(ContentLevel&& _Other) noexcept = delete;
	ContentLevel& operator=(const ContentLevel& _Other) = delete;
	ContentLevel& operator=(ContentLevel&& _Other) noexcept = delete;

	std::shared_ptr<ContentBackground> GetCurLevelBackground()
	{
		return CurLevelBackground;
	}

protected:
	void Start() override;
	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

	std::shared_ptr<ContentBackground> CurLevelBackground = nullptr;
private:
};

