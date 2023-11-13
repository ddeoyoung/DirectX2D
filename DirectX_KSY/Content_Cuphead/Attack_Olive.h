#pragma once
#include <GameEngineCore\GameEngineActor.h>

#define OLIVE_MOVE_SPEED 20.0f;

enum class OliveState
{
	None,
	Appear,
	Idle,
	Move,
	Attack,
	Death,
};

// Ό³Έν :
class Attack_Olive : public ContentActor
{
public:
	// constrcuter destructer
	Attack_Olive();
	~Attack_Olive();

	// delete Function
	Attack_Olive(const Attack_Olive& _Other) = delete;
	Attack_Olive(Attack_Olive&& _Other) noexcept = delete;
	Attack_Olive& operator=(const Attack_Olive& _Other) = delete;
	Attack_Olive& operator=(Attack_Olive&& _Other) noexcept = delete;

	void SetState(OliveState _State)
	{
		State = _State;
	}

	void HPMinus();

protected:
	void ChangeState(OliveState _State);
	void StateUpdate(float _Delta);
	void ChangeAnimationState(const std::string& _StateName);

	void AppearStart();
	void AppearUpdate(float _Delta);

	void IdleStart();
	void IdleUpdate(float _Delta);

	void MoveStart();
	void MoveUpdate(float _Delta);

	void AttackStart();
	void AttackUpdate(float _Delta);

	void DeathStart();
	void DeathUpdate(float _Delta);

protected:
	void Start() override;
	void Update(float _Delta) override;

	void DeathCheck();

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> AttackCollision = nullptr;

	std::string CurState = "";
	OliveState State = OliveState::None;

private:
	int HP = 0;
	int ChangeDir = 1;
	bool IsHit = false;
	bool IsDeath = false;
	float IdleTimer = 0.0f;
	float AttackTimer = 0.0f;
	float MoveDur = 0.0f;

	float4 PlayerPos = float4::ZERO;
};

