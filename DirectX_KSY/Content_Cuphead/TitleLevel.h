#pragma once
#include "ContentLevel.h"

// Ό³Έν :
class TitleLevel : public ContentLevel
{
public:
	// constrcuter destructer
	TitleLevel();
	~TitleLevel();

	// delete Function
	TitleLevel(const TitleLevel& _Other) = delete;
	TitleLevel(TitleLevel&& _Other) noexcept = delete;
	TitleLevel& operator=(const TitleLevel& _Other) = delete;
	TitleLevel& operator=(TitleLevel&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

private:
	std::shared_ptr<class TitleBackground> Back = nullptr;
	std::shared_ptr<class Cuphead_And_Mugman> CupheadAndMugman = nullptr;
	std::shared_ptr<class TitleMenuBackground> MenuBack = nullptr;
	std::shared_ptr<class TitleMenuButton> MenuButton = nullptr;
	std::shared_ptr<class FadeAnimation> FadeOut = nullptr;
};

