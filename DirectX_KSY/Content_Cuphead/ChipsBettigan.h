#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Speed
#define STRETCHSPEED 160.0f
#define ATTACKSPEED -600.0f
#define ATTACKTIME 1.5f

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

	void CreateChips();
	void StretchChips(float _Delta, bool _IsStretch);
	void SpinAttack(float _Delta);
	void DeathChips();
	void CheckIdleDir();
	bool CheckAttackDir();

	std::string CurState = "";
	ChipsState State = ChipsState::None;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> BossCollision = nullptr;

	std::vector<std::shared_ptr<class Attack_Chips>> ChipSet;

private:
	int SpinDir = 1;

	float MainTimer = 0.0f;
	float StretchTimer = 0.0f;
	float AttackTimer = 0.0f;

	bool IsStretch = false;
	bool IsSpinEnd = false;
	bool IsMove = false;

	bool FirstAttack = false;
	bool SecondAttack = false;
	bool ThirdAttack = false;
};

