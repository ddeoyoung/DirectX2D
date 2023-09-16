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

void BaseWeapon::AttackDirCheck()
{
	switch (AttDir)
	{
	case AttackDir::None:
		break;
	case AttackDir::Left_Up:
		Transform.SetLocalScale({ -1.0f, 1.0f });
		Transform.SetLocalRotation({ 0.0f, 0.0f, -90.0f });
		break;
	case AttackDir::Left_Diagonal_Up:
		Transform.SetLocalScale({ -1.0f, 1.0f });
		Transform.SetLocalRotation({ 0.0f, 0.0f, -45.0f });
		break;
	case AttackDir::Left_Straight:
		Transform.SetLocalScale({ -1.0f, 1.0f });
		//Transform.SetLocalRotation({ 0.0f, 0.0f, 0.0f });
		break;
	case AttackDir::Left_Diagonal_Down:
		Transform.SetLocalScale({ -1.0f, 1.0f });
		Transform.SetLocalRotation({ 0.0f, 0.0f, 225.0f });
		break;
	case AttackDir::Left_Down:
		Transform.SetLocalScale({ -1.0f, 1.0f });
		Transform.SetLocalRotation({ 0.0f, 0.0f, 270.0f });
		break;
	case AttackDir::Right_Up:
		Transform.SetLocalScale({ 1.0f, 1.0f });
		Transform.SetLocalRotation({ 0.0f, 0.0f, 90.0f });
		break;
	case AttackDir::Right_Diagonal_Up:
		Transform.SetLocalScale({ 1.0f, 1.0f });
		Transform.SetLocalRotation({ 0.0f, 0.0f, 45.0f });
		break;
	case AttackDir::Right_Straight:
		Transform.SetLocalScale({ 1.0f, 1.0f });
		//Transform.SetLocalRotation({ 0.0f, 0.0f, 0.0f });
		break;
	case AttackDir::Right_Diagonal_Down:
		Transform.SetLocalScale({ 1.0f, 1.0f });
		Transform.SetLocalRotation({ 0.0f, 0.0f, -45.0f });
		break;
	case AttackDir::Right_Down:
		Transform.SetLocalScale({ 1.0f, 1.0f });
		Transform.SetLocalRotation({ 0.0f, 0.0f, -90.0f });
		break;
	default:
		break;
	}
}


void BaseWeapon::SetAttackPos(float4 _Pos)
{
	float4 PlayerPos = _Pos;
	float4 AttackPos = PlayerPos;

	switch (AttDir)
	{
	case AttackDir::None:
		break;
	case AttackDir::Left_Up:
		AttackPos += ATTACK_LEFT_UP;
		break;
	case AttackDir::Left_Diagonal_Up:
		AttackPos += ATTACK_LEFT_DIAGONAL_UP;
		break;
	case AttackDir::Left_Straight:
		AttackPos += ATTACK_LEFT;
		break;
	case AttackDir::Left_Diagonal_Down:
		AttackPos += ATTACK_LEFT_DIAGONAL_DOWN;
		break;
	case AttackDir::Left_Down:
		AttackPos += ATTACK_LEFT_DOWN;
		break;
	case AttackDir::Right_Up:
		AttackPos += ATTACK_RIGHT_UP;
		break;
	case AttackDir::Right_Diagonal_Up:
		AttackPos += ATTACK_RIGHT_DIAGONAL_UP;
		break;
	case AttackDir::Right_Straight:
		AttackPos += ATTACK_RIGHT;
		break;
	case AttackDir::Right_Diagonal_Down:
		AttackPos += ATTACK_RIGHT_DIAGONAL_DOWN;
		break;
	case AttackDir::Right_Down:
		AttackPos += ATTACK_RIGHT_DOWN;
		break;
	default:
		break;
	}

	Transform.SetLocalPosition(AttackPos);
}