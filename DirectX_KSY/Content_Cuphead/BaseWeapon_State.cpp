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
	float AttackSpeed = ATTACKSPEED;
	float4 MovePos = 0.0f;

	if (AttDir == AttackDir::Left_Straight)
	{
		MovePos = float4::LEFT * _Delta * ATTACKSPEED;
	}

	if (AttDir == AttackDir::Right_Straight)
	{
		MovePos = float4::RIGHT * _Delta * ATTACKSPEED;
	}

	Transform.AddLocalPosition(MovePos);
}

void BaseWeapon::DeathStart()
{
	ChangeAnimationState("Death");
}

void BaseWeapon::DeathUpdate(float _Delta)
{

}