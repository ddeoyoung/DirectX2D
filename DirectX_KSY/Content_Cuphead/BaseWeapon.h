#pragma once
#include <GameEngineCore\GameEngineActor.h>

#define ATTACKSPEED 800.0f

// ���� :
class BaseWeapon : public GameEngineActor
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

	AttackState State = AttackState::None;
	AttackDir AttDir = AttackDir::None;

	std::string CurState = "";

private:
};

