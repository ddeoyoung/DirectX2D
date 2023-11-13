#pragma once
#include <GameEngineCore\GameEngineActor.h>

enum class MartiniState
{
	None,
	Idle,
	Attack,
	Death,
};

// Ό³Έν :
class Martini : public ContentActor
{
public:
	// constrcuter destructer
	Martini();
	~Martini();

	// delete Function
	Martini(const Martini& _Other) = delete;
	Martini(Martini&& _Other) noexcept = delete;
	Martini& operator=(const Martini& _Other) = delete;
	Martini& operator=(Martini&& _Other) noexcept = delete;

	void HPMinus();

	bool GetIsDeath()
	{
		return IsDeath;
	}

protected:
	void ChangeState(MartiniState _State);
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

	void CreateOliveDevil();
	void DeathCheck();

	std::string CurState = "";
	MartiniState State = MartiniState::None;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> BossCollision = nullptr;

private:
	int BossHP = 0;
	bool IsOliveOn = false;
	bool IsHit = false;
	bool IsDeath = false;
	float IdleTimer = 0.0f;
	float AttackTimer = 0.0f;
};

