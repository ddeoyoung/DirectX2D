#pragma once
#include <GameEngineCore\GameEngineActor.h>

enum class ScotchState
{
	None,
	Idle,
	Attack,
	Death,
};

// Ό³Έν :
class Scotch : public ContentActor
{
public:
	// constrcuter destructer
	Scotch();
	~Scotch();

	// delete Function
	Scotch(const Scotch& _Other) = delete;
	Scotch(Scotch&& _Other) noexcept = delete;
	Scotch& operator=(const Scotch& _Other) = delete;
	Scotch& operator=(Scotch&& _Other) noexcept = delete;

	void HPMinus();
	void CreateDeathEffect();

	bool GetIsDeath()
	{
		return IsDeath;
	}

protected:
	void ChangeState(ScotchState _State);
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

	void CreateLiquid();
	void DeathCheck();

	std::string CurState = "";
	ScotchState State = ScotchState::None;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> BossCollision = nullptr;

	std::shared_ptr<class Attack_Liquid> Liquid = nullptr;

private:
	int BossHP = 0;
	bool IsHit = false;
	bool IsDeath = false;
	float IdleTimer = 0.0f;
	float AttackTimer = 0.0f;
};

