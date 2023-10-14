#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Speed
#define ATTACKSPEED 1200.0f

// Attack Start Pos
#define ATTACK_RIGHT	{ 70.0f, 80.0f }
#define ATTACK_RIGHT_DIAGONAL_UP	{ 70.0f, 120.0f }
#define ATTACK_RIGHT_DIAGONAL_DOWN	{ 70.0f, 40.0f }
#define ATTACK_RIGHT_UP { 20.0f, 160.0f }
#define ATTACK_RIGHT_DOWN	{ 20.0f, 20.0f }

#define ATTACK_LEFT	{ -70.0f, 80.0f }
#define ATTACK_LEFT_DIAGONAL_UP { -70.0f, 120.0f }
#define ATTACK_LEFT_DIAGONAL_DOWN	{ -70.0f, 40.0f }
#define ATTACK_LEFT_UP { -20.0f, 160.0f }
#define ATTACK_LEFT_DOWN	{ -20.0f, 20.0f }

#define RUN_ATTACK_RIGHT	{ 90.0f, 80.0f }
#define RUN_ATTACK_RIGHT_DIAGONAL_UP	{ 110.0f, 130.0f }
#define RUN_ATTACK_LEFT	{ -90.0f, 80.0f }
#define RUN_ATTACK_LEFT_DIAGONAL_UP { -110.0f, 130.0f }

// Ό³Έν :
class BaseWeapon : public ContentActor
{
public:
	// constrcuter destructer
	BaseWeapon();
	~BaseWeapon();

	// delete Function
	BaseWeapon(const BaseWeapon& _Other) = delete;
	BaseWeapon(BaseWeapon&& _Other) noexcept = delete;
	BaseWeapon& operator=(const BaseWeapon& _Other) = delete;
	BaseWeapon& operator=(BaseWeapon&& _Other) noexcept = delete;

	void SetAttackDir(AttackDir _AttDir)
	{
		AttDir = _AttDir;
	}

	void SetAttackDirAndPos(AttackDir _AttDir, float4 _Pos, bool _IsMove = false);
	
protected:
	void ChangeState(AttackState _State);
	void StateUpdate(float _Delta);
	virtual void ChangeAnimationState(const std::string& _StateName);

	void SparkStart();
	void SparkUpdate(float _Delta);

	void AttackStart();
	void AttackUpdate(float _Delta);

	void DeathStart();
	void DeathUpdate(float _Delta);

protected:
	void Start() override;
	void Update(float _Delta) override;

	void AttackDirCheck();

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> AttackCollision = nullptr;

	AttackState State = AttackState::None;
	AttackDir AttDir = AttackDir::None;

	float4 PlayerPos = float4::ZERO;

	std::string CurState = "";

private:
};

