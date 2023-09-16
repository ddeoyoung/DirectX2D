#include "PreCompile.h"
#include "BaseCharacter.h"
#include "Peashot.h"

void BaseCharacter::IdleStart()
{
	ChangeAnimationState("Idle");

	IsJump = false;
}

void BaseCharacter::IdleUpdate(float _Delta)
{
	if (true == GameEngineInput::IsPress(VK_LEFT) || true == GameEngineInput::IsPress(VK_RIGHT))
	{
		ChangeState(CharacterState::Run);
	}

	if (true == GameEngineInput::IsDown(VK_DOWN) || true == GameEngineInput::IsPress(VK_DOWN))
	{
		ChangeState(CharacterState::Duck);
	}

	if (true == GameEngineInput::IsDown(VK_LSHIFT))
	{
		ChangeState(CharacterState::Dash);
	}

	if (true == GameEngineInput::IsDown('Z'))
	{
		ChangeState(CharacterState::Jump);
	}

	if (true == GameEngineInput::IsDown('X'))
	{
		ChangeState(CharacterState::Shoot);
	}

	if (true == GameEngineInput::IsDown('C'))
	{
		ChangeState(CharacterState::Aim);
	}
}


void BaseCharacter::RunStart()
{
	ChangeAnimationState("Run");
}

void BaseCharacter::RunUpdate(float _Delta)
{
	float RunSpeed = RUNSPEED;
	float4 MovePos = 0.0f;

	if (Dir == ActorDir::Left && true == GameEngineInput::IsDown(VK_LEFT) 
		|| Dir == ActorDir::Left && true == GameEngineInput::IsPress(VK_LEFT))
	{
		MovePos = float4::LEFT * _Delta * RunSpeed;
	}

	if (Dir == ActorDir::Right && true == GameEngineInput::IsDown(VK_RIGHT) 
		|| Dir == ActorDir::Right && true == GameEngineInput::IsPress(VK_RIGHT))
	{
		MovePos = float4::RIGHT * _Delta * RunSpeed;
	}

	if (true == GameEngineInput::IsDown(VK_LSHIFT))
	{
		ChangeState(CharacterState::Dash);
	}

	if (true == GameEngineInput::IsDown('Z'))
	{
		ChangeState(CharacterState::Jump);
	}

	if (true == GameEngineInput::IsDown('X'))
	{
		ChangeState(CharacterState::Shoot);
	}

	if (true == GameEngineInput::IsDown('C'))
	{
		ChangeState(CharacterState::Aim);
	}

	if (float4::ZERO == MovePos)
	{
		ChangeState(CharacterState::Idle);
		return;
	}

	Transform.AddLocalPosition(MovePos);
}

void BaseCharacter::AimStart()
{
	ChangeAnimationState("Aim");
}

void BaseCharacter::AimUpdate(float _Delta)
{
	if (true == GameEngineInput::IsUp('C') || true == GameEngineInput::IsFree('C'))
	{
		ChangeState(CharacterState::Idle);
	}
}

void BaseCharacter::ShootStart()
{
	ChangeAnimationState("Shoot");

	std::shared_ptr<Peashot> Bullet = GetLevel()->CreateActor<Peashot>();
	float4 BulletPos = Transform.GetWorldPosition(); 
	BulletPos += BULLETSTARTPOS;
	Bullet->Transform.SetLocalPosition(BulletPos);
	Bullet->SetAttackDir(AttDir);
}

void BaseCharacter::ShootUpdate(float _Delta)
{
	if (true == GameEngineInput::IsUp('X') || true == GameEngineInput::IsFree('X'))
	{
		ChangeState(CharacterState::Idle);
	}
}

void BaseCharacter::DuckStart()
{
	ChangeAnimationState("Duck");
}

void BaseCharacter::DuckUpdate(float _Delta)
{
	if (true == MainRenderer->IsCurAnimationEnd())
	{
		ChangeState(CharacterState::DuckIdle);
	}

	// Idle
	if (true == GameEngineInput::IsUp(VK_DOWN) || true == GameEngineInput::IsFree(VK_DOWN))
	{
		ChangeState(CharacterState::Idle);
	}
	
	// Aim
	if (true == GameEngineInput::IsDown('C') || true == GameEngineInput::IsPress('C'))
	{
		ChangeState(CharacterState::Aim);
	}

	// Duck Shoot
	if ((true == GameEngineInput::IsDown(VK_DOWN) || true == GameEngineInput::IsPress(VK_DOWN))
		&& (true == GameEngineInput::IsDown('X') || true == GameEngineInput::IsPress('X')))
	{
		ChangeState(CharacterState::DuckShoot);
	}
}

void BaseCharacter::DuckIdleStart()
{
	ChangeAnimationState("Duck_Idle");
}

void BaseCharacter::DuckIdleUpdate(float _Delta)
{
	if (true == GameEngineInput::IsUp(VK_DOWN) || true == GameEngineInput::IsFree(VK_DOWN))
	{
		ChangeState(CharacterState::Idle);
	}
}

void BaseCharacter::DuckShootStart()
{
	ChangeAnimationState("Duck_Shoot");
}

void BaseCharacter::DuckShootUpdate(float _Delta)
{
	if (true == GameEngineInput::IsUp(VK_DOWN) || true == GameEngineInput::IsFree(VK_DOWN))
	{
		ChangeState(CharacterState::Idle);
	}
}

void BaseCharacter::HitStart()
{
	ChangeAnimationState("Hit");
}

void BaseCharacter::HitUpdate(float _Delta)
{

}

void BaseCharacter::DashStart()
{
	ChangeAnimationState("Dash");
}

void BaseCharacter::DashUpdate(float _Delta)
{
	if (true == MainRenderer->IsCurAnimationEnd())
	{
		ChangeState(CharacterState::Idle);
	}

	float DashSpeed = 1000.0f;
	float4 MovePos = 0.0f;

	switch (Dir)
	{
	case ActorDir::Left:
		MovePos = float4::LEFT * _Delta * DashSpeed;
		break;
	case ActorDir::Right:
		MovePos = float4::RIGHT * _Delta * DashSpeed;
		break;
	default:
		break;
	}

	if (true == IsJump)
	{
		MovePos.Y -= _Delta * GravityForce.Y;
	}

	Transform.AddLocalPosition(MovePos);
}

void BaseCharacter::JumpStart()
{
	ChangeAnimationState("Jump");
	JumpTimer = 0.15f;
	IsJump = true;
}

void BaseCharacter::JumpUpdate(float _Delta)
{
	float4 JumpPos = float4::ZERO;
	float4 JumpGravityForce = float4::ZERO;
	float4 MovePos = float4::ZERO;

	JumpTimer -= _Delta;

	if (true == GameEngineInput::IsPress('Z') && 0.0f <= JumpTimer)
	{
		JumpPos.Y += 1800.0f * _Delta;
	}

	if (Dir == ActorDir::Left && true == GameEngineInput::IsDown(VK_LEFT)
		|| Dir == ActorDir::Left && true == GameEngineInput::IsPress(VK_LEFT))
	{
		MovePos = float4::LEFT * _Delta * RUNSPEED;
	}

	if (Dir == ActorDir::Right && true == GameEngineInput::IsDown(VK_RIGHT)
		|| Dir == ActorDir::Right && true == GameEngineInput::IsPress(VK_RIGHT))
	{
		MovePos = float4::RIGHT * _Delta * RUNSPEED;
	}

	MovePos += JumpPos;
	Transform.AddLocalPosition(MovePos);

	if (true == GameEngineInput::IsPress(VK_LSHIFT))
	{
		ChangeState(CharacterState::Dash);
	}
	

	// 땅에 닿으면 Idle이 되도록 수정
	if (true == MainRenderer->IsCurAnimationEnd())
	{
		IsJump = false;
		ChangeState(CharacterState::Idle);
	}
}

void BaseCharacter::ParryStart()
{
	ChangeAnimationState("Parry");
}

void BaseCharacter::ParryUpdate(float _Delta)
{

}

void BaseCharacter::IntroStart()
{
	ChangeAnimationState("Intro");
}

void BaseCharacter::IntroUpdate(float _Delta)
{
	if (true == MainRenderer->IsCurAnimationEnd())
	{
		ChangeState(CharacterState::Idle);
	}
}

void BaseCharacter::GhostStart()
{
	ChangeAnimationState("Ghost");
}

void BaseCharacter::GhostUpdate(float _Delta)
{

}

void BaseCharacter::DeathStart()
{
	ChangeAnimationState("Death");
}

void BaseCharacter::DeathUpdate(float _Delta)
{

}