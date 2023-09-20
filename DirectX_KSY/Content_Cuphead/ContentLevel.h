#pragma once
#include <GameEngineCore/GameEngineLevel.h>
#include "ContentBackground.h"

// Ό³Έν :
class ContentBackground;
class ContentLevel : public GameEngineLevel
{
public:
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


	std::shared_ptr<ContentBackground> GetCurLevelPixelBackground()
	{
		return CurLevelPixelBackground;
	}

	float4 GetCurLevelPixelScale()
	{
		return CurLevelPixelBackground->Transform.GetLocalScale();
	}

	std::string GetCurLevelName()
	{
		return CurLevel->GetName();
	}

protected:
	void Start() override;
	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

	std::shared_ptr<ContentBackground> CurLevelBackground = nullptr;
	std::shared_ptr<ContentBackground> CurLevelPixelBackground = nullptr;

private:
};

