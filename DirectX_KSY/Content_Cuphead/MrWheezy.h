#pragma once
#include "BaseMonster.h"

enum class WheezyState
{
	None,
	Intro,
	Idle,
	Attack,
	Teleport,
	Appear,
	Death,
};

// Ό³Έν :
class MrWheezy : public BaseMonster
{
public:
	// constrcuter destructer
	MrWheezy();
	~MrWheezy();

	// delete Function
	MrWheezy(const MrWheezy& _Other) = delete;
	MrWheezy(MrWheezy&& _Other) noexcept = delete;
	MrWheezy& operator=(const MrWheezy& _Other) = delete;
	MrWheezy& operator=(MrWheezy&& _Other) noexcept = delete;

	void SetState(WheezyState _State)
	{
		State = _State;
	}

	int GetDir()
	{
		return Dir;
	}

	void CreateDeathEffect();

protected:
	void ChangeState(WheezyState _State);
	void StateUpdate(float _Delta);
	void ChangeAnimationState(const std::string& _StateName);

	void IntroStart();
	void IntroUpdate(float _Delta);

	void IdleStart();
	void IdleUpdate(float _Delta);

	void AttackStart();
	void AttackUpdate(float _Delta);

	void TeleportStart();
	void TeleportUpdate(float _Delta);

	void AppearStart();
	void AppearUpdate(float _Delta);

	void DeathStart();
	void DeathUpdate(float _Delta);

protected:
	void Start() override;
	void Update(float _Delta) override;

	void ReverseDir();
	void CreateCiggyDemon(float _Delta);
	void CreateFireBullet();
	void DeathCheck();

	std::string CurState = "";
	WheezyState State = WheezyState::None;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineSpriteRenderer> KingDiceRenderer = nullptr;
	std::shared_ptr<class GameEngineSpriteRenderer> FireRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> BossCollision = nullptr;

private:
	int Dir = 1;
	int AttackCount = 0;
	float IdleTime = 0.0f;
	float AttackTime = 0.0f;
	float CiggyDemonInter = 3.0f;
	bool IsAttack = false;
};

