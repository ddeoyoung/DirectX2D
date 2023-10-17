#include "PreCompile.h"
#include "BaseWeapon.h"
#include "BaseCharacter.h"
#include "Cuphead.h"

void BaseWeapon::SparkStart()
{
	ChangeAnimationState("Spark");
}

void BaseWeapon::SparkUpdate(float _Delta)
{
	if (true == MainRenderer->IsCurAnimationEnd())
	{
		ChangeState(AttackState::Attack);
	}
}

void BaseWeapon::AttackStart()
{
	ChangeAnimationState("Attack");
}

void BaseWeapon::AttackUpdate(float _Delta)
{
	AttackDirCheck();

	float AttackSpeed = ATTACKSPEED;
	float4 MovePos = 0.0f;

	switch (AttDir)
	{
	case AttackDir::None:
		break;
	case AttackDir::Left_Up:
		MovePos = float4::UP * _Delta * AttackSpeed;
		break;
	case AttackDir::Left_Diagonal_Up:
		MovePos = (float4::LEFT + float4::UP) * _Delta * AttackSpeed;
		break;
	case AttackDir::Left_Straight:
		MovePos = float4::LEFT * _Delta * AttackSpeed;
		break; 
	case AttackDir::Left_Diagonal_Down:
		MovePos = (float4::LEFT + float4::DOWN) * _Delta * AttackSpeed;
		break;
	case AttackDir::Left_Down:
		MovePos = float4::DOWN * _Delta * AttackSpeed;
		break;
	case AttackDir::Right_Up:
		MovePos = float4::UP * _Delta * AttackSpeed;
		break;
	case AttackDir::Right_Diagonal_Up:
		MovePos = (float4::RIGHT + float4::UP) * _Delta * AttackSpeed;
		break;
	case AttackDir::Right_Straight:
		MovePos = float4::RIGHT * _Delta * AttackSpeed;
		break;
	case AttackDir::Right_Diagonal_Down:
		MovePos = (float4::RIGHT + float4::DOWN) * _Delta * AttackSpeed;
		break;
	case AttackDir::Right_Down:
		MovePos = float4::DOWN * _Delta * AttackSpeed;
		break;
	default:
		break;
	}

	Transform.AddLocalPosition(MovePos);



	// Test Code
	{
		bool IsAttacked = AttackCollision->Collision(CollisionOrder::Boss);

		if (true == IsAttacked)
		{
			ChangeState(AttackState::Death);
		}
	}
}

void BaseWeapon::DeathStart()
{
	ChangeAnimationState("Death");
}

void BaseWeapon::DeathUpdate(float _Delta)
{
	if (true == MainRenderer->IsCurAnimationEnd())
	{
		Death();
	}
}