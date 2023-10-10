#pragma once
#include <GameEngineCore\GameEngineActor.h>

enum class ChipsState
{
	None,
	Intro,
	Idle,
	Spin,
	Death,
};

// Ό³Έν :
class ChipsBettigan : public GameEngineActor
{
public:
	// constrcuter destructer
	ChipsBettigan();
	~ChipsBettigan();

	// delete Function
	ChipsBettigan(const ChipsBettigan& _Other) = delete;
	ChipsBettigan(ChipsBettigan&& _Other) noexcept = delete;
	ChipsBettigan& operator=(const ChipsBettigan& _Other) = delete;
	ChipsBettigan& operator=(ChipsBettigan&& _Other) noexcept = delete;

protected:
	void ChangeState(ChipsState _State);
	void StateUpdate(float _Delta);
	void ChangeAnimationState(const std::string& _StateName);

	void IntroStart();
	void IntroUpdate(float _Delta);

	void IdleStart();
	void IdleUpdate(float _Delta);

	void SpinStart();
	void SpinUpdate(float _Delta);

	void DeathStart();
	void DeathUpdate(float _Delta);

protected:
	void Start() override;
	void Update(float _Delta) override;

	void SpinAttack();
	void CreateChips();

	std::string CurState = "";
	ChipsState State = ChipsState::None;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> BossCollision = nullptr;

	std::shared_ptr<class GameEngineSpriteRenderer> MiddleRenderer = nullptr;
	std::shared_ptr<class GameEngineSpriteRenderer> BottomRenderer = nullptr;

private:
	float MainTimer = 0.0f;

	// Attack
	float StretchTimer = 0.0f;
};

