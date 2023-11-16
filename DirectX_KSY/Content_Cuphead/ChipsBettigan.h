#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Speed
#define CHIPSTRETCHSPEED 160.0f
#define CHIPATTACKSPEED -600.0f
#define CHIPFALLSPEED -1600.0f
#define CHIPATTACKTIME 1.5f

enum class ChipsState
{
	None,
	Intro,
	Idle,
	Spin,
	Death,
};

// Ό³Έν :
class ChipsBettigan : public ContentActor
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

	void HPMinus();

	bool GetIsDeath()
	{
		return IsDeath;
	}

	void CreateDeathEffect();

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
	void CheckDeathDir();

	void DeathCheck();

	std::string CurState = "";
	ChipsState State = ChipsState::None;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> BossCollision = nullptr;

	std::shared_ptr<class Attack_Chips> Chips1 = nullptr;
	std::shared_ptr<class Attack_Chips> Chips2 = nullptr;
	std::shared_ptr<class Attack_Chips> Chips3 = nullptr;
	std::shared_ptr<class Attack_Chips> Chips4 = nullptr;
	std::shared_ptr<class Attack_Chips> Chips5 = nullptr;
	std::shared_ptr<class Attack_Chips> Chips6 = nullptr;
	std::shared_ptr<class Attack_Chips> Chips7 = nullptr;

	std::vector<std::shared_ptr<class Attack_Chips>> ChipSet;

private:
	int SpinDir = 1;
	int BossHP = 0;
	bool IsHit = false;
	bool IsDeath = false;

	float IdleTimer = 0.0f;
	float StretchTimer = 0.0f;
	float AttackTimer = 0.0f;
	float DeathFallTimer = 0.0f;

	bool IsStretch = false;
	bool IsSpinEnd = false;
	bool IsMove = false;

	bool FirstAttack = false;
	bool SecondAttack = false;
	bool ThirdAttack = false;
};

