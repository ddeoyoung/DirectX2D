#pragma once
#include "BaseMonster.h"

enum class RumState
{
	None,
	Idle,
	Attack,
	Death,
};

// Ό³Έν :
class Rum : public BaseMonster
{
public:
	// constrcuter destructer
	Rum();
	~Rum();

	// delete Function
	Rum(const Rum& _Other) = delete;
	Rum(Rum&& _Other) noexcept = delete;
	Rum& operator=(const Rum& _Other) = delete;
	Rum& operator=(Rum&& _Other) noexcept = delete;

	void CreateDeathEffect();

protected:
	void ChangeState(RumState _State);
	void StateUpdate(float _Delta);
	void ChangeAnimationState(const std::string& _StateName);

	void IdleStart();
	void IdleUpdate(float _Delta);

	void AttackStart();
	void AttackUpdate(float _Delta);

	void DeathStart();
	void DeathUpdate(float _Delta);

protected:
	void Start() override;
	void Update(float _Delta) override;

	void CreateSpew();
	void DeathCheck();

	std::string CurState = "";
	RumState State = RumState::None;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> BossCollision = nullptr;

private:
	int HP = 0;
	bool IsDeath = false;
	float IdleTimer = 0.0f;
	float AttackTimer = 0.0f;
};

