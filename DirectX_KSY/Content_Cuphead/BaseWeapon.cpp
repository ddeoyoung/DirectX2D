#include "PreCompile.h"
#include "BaseWeapon.h"
#include "BaseCharacter.h"

BaseWeapon::BaseWeapon()
{
}

BaseWeapon::~BaseWeapon()
{
}

void BaseWeapon::Start()
{

}

void BaseWeapon::Update(float _Delta)
{
	StateUpdate(_Delta);
}

void BaseWeapon::ChangeState(AttackState _State)
{
	if (_State != State)
	{
		switch (_State)
		{
		case AttackState::None:
			break;
		case AttackState::Spark:
			SparkStart();
			break;
		case AttackState::Attack:
			AttackStart();
			break;
		case AttackState::Death:
			DeathStart();
			break;
		default:
			break;
		}
	}

	State = _State;
}

void BaseWeapon::StateUpdate(float _Delta)
{
	switch (State)
	{
	case AttackState::None:
		break;
	case AttackState::Spark:
		return SparkUpdate(_Delta);
	case AttackState::Attack:
		return AttackUpdate(_Delta);
	case AttackState::Death:
		return DeathUpdate(_Delta);
	default:
		break;
	}
}

void BaseWeapon::ChangeAnimationState(const std::string& _StateName) {}
