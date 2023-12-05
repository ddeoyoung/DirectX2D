#pragma once
#include "ContentLevel.h"

// Ό³Έν :
class InkwellHellLevel : public ContentLevel
{
public:
	// constrcuter destructer
	InkwellHellLevel();
	~InkwellHellLevel();

	// delete Function
	InkwellHellLevel(const InkwellHellLevel& _Other) = delete;
	InkwellHellLevel(InkwellHellLevel&& _Other) noexcept = delete;
	InkwellHellLevel& operator=(const InkwellHellLevel& _Other) = delete;
	InkwellHellLevel& operator=(InkwellHellLevel&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

	void CheckPortal();
	void CheckLevelChange();
	void ShowTitleCard();
	void CheckBossStageEnter();

private:
	std::shared_ptr<class OverWorldCharacter> OverWorldPlayer = nullptr;
	std::shared_ptr<class Portal> PortalToInkwell = nullptr;
	std::shared_ptr<class Portal> PortalToBossStage = nullptr;
	std::shared_ptr<class Portal> NextLevel = nullptr;
	std::shared_ptr<class FadeAnimation> FadeOut = nullptr;
	std::shared_ptr<class TitleCard_Fader> Fader = nullptr;
	std::shared_ptr<class TitleCard_KingDice> TitleCard = nullptr;

	bool IsTitleCardOn = false;
};

