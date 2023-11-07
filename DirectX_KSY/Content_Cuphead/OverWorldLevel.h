#pragma once
#include "ContentLevel.h"

// Ό³Έν :
class OverWorldLevel : public ContentLevel
{
public:
	// constrcuter destructer
	OverWorldLevel();
	~OverWorldLevel();

	// delete Function
	OverWorldLevel(const OverWorldLevel& _Other) = delete;
	OverWorldLevel(OverWorldLevel&& _Other) noexcept = delete;
	OverWorldLevel& operator=(const OverWorldLevel& _Other) = delete;
	OverWorldLevel& operator=(OverWorldLevel&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

private:
	std::shared_ptr<class OverWorldCharacter> OverWorldPlayer = nullptr;
	std::shared_ptr<class OverWorldFlag> FlagToThree = nullptr;
	std::shared_ptr<class OverWorldFlag> FlagToOne = nullptr;
	std::shared_ptr<class Portal> PortalToHell = nullptr;
	std::shared_ptr<class FadeAnimation> FadeOut = nullptr;

	bool IsHell = false;

	float4 LastPlayerPos = float4::ZERO;
};

