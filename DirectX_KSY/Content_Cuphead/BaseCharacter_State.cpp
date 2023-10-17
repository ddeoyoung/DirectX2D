#include "PreCompile.h"
#include "BaseCharacter.h"
#include "Peashot.h"

void BaseCharacter::IdleStart()
{
	ChangeAnimationState("Idle");
}

void BaseCharacter::IdleUpdate(float _Delta)
{
	if (true == GameEngineInput::IsPress(VK_LEFT, this) || true == GameEngineInput::IsPress(VK_RIGHT, this))
	{
		ChangeState(CharacterState::Run);
	}

	if (true == GameEngineInput::IsDown(VK_DOWN, this) || true == GameEngineInput::IsPress(VK_DOWN, this))
	{
		ChangeState(CharacterState::Duck);
	}

	if (true == GameEngineInput::IsDown(VK_LSHIFT, this))
	{
		ChangeState(CharacterState::Dash);
	}

	if (true == GameEngineInput::IsDown('Z', this))
	{
		ChangeState(CharacterState::Jump);
	}

	if (true == GameEngineInput::IsDown('X', this))
	{
		ChangeState(CharacterState::Shoot);
	}

	if (true == GameEngineInput::IsDown('C', this))
	{
		ChangeState(CharacterState::Aim);
	}
}


void BaseCharacter::RunStart()
{
	ChangeAnimationState("Run");

	RunDustTimer = 0.3f;
}

void BaseCharacter::RunUpdate(float _Delta)
{
	PixelCheck(_Delta);

	RunDustTimer -= _Delta;

	if (RunDustTimer < 0.0f)
	{
		CreateRunDust();
		RunDustTimer = 0.3f;
	}

	if (true == GameEngineInput::IsDown(VK_LSHIFT, this))
	{
		ChangeState(CharacterState::Dash);
	}

	if (true == GameEngineInput::IsDown('Z', this))
	{
		ChangeState(CharacterState::Jump);
	}

	if (true == GameEngineInput::IsDown('X', this))
	{
		ChangeState(CharacterState::Shoot);
	}

	if (true == GameEngineInput::IsDown('C', this) || true == GameEngineInput::IsPress('C', this))
	{
		ChangeState(CharacterState::Aim);
	}

	if (true == GameEngineInput::IsFree(VK_LEFT, this)
		&& true == GameEngineInput::IsFree(VK_RIGHT, this))
	{
		ChangeState(CharacterState::Idle);
		return;
	}
}

void BaseCharacter::AimStart()
{
	ChangeAnimationState("Aim");

	IsAim = true;
}

void BaseCharacter::AimUpdate(float _Delta)
{
	if (true == GameEngineInput::IsUp('C', this) || true == GameEngineInput::IsFree('C', this))
	{
		IsAim = false;
		ChangeState(CharacterState::Idle);
	}

	if (true == GameEngineInput::IsDown('X', this))
	{
		IsAim = true;
		ChangeState(CharacterState::Shoot);
	}
}

void BaseCharacter::ShootStart()
{
	ChangeAnimationState("Shoot");

	std::shared_ptr<Peashot> Bullet = GetLevel()->CreateActor<Peashot>();
	float4 PlayerPos = Transform.GetWorldPosition();
	Bullet->SetAttackDirAndPos(AttDir, PlayerPos);

	ShootInterval = 0.0f;
}

void BaseCharacter::ShootUpdate(float _Delta)
{
	IsRunShoot = MoveCheck();

	if (true == GameEngineInput::IsUp('X', this) || true == GameEngineInput::IsFree('X', this))
	{
		ChangeState(CharacterState::Idle);
	}

	if (true == GameEngineInput::IsPress('X', this) && ShootInterval >= SHOOT_INTERVAL)
	{
		std::shared_ptr<Peashot> Bullet = GetLevel()->CreateActor<Peashot>();
		float4 PlayerPos = Transform.GetWorldPosition();
		Bullet->SetAttackDirAndPos(AttDir, PlayerPos);

		ShootInterval = 0.0f;
	}

	ShootInterval += _Delta;


	if (true == IsRunShoot)
	{
		ChangeState(CharacterState::RunShoot);
	}

}

void BaseCharacter::RunShootStart()
{
	ChangeAnimationState("Run_Shoot");

	ShootInterval = 0.0f;
}

void BaseCharacter::RunShootUpdate(float _Delta)
{
	PixelCheck(_Delta);

	IsRunShoot = MoveCheck();

	// Run
	float RunSpeed = RUNSPEED;
	float4 MovePos = 0.0f;

	if (Dir == ActorDir::Left && true == GameEngineInput::IsDown(VK_LEFT, this)
		|| Dir == ActorDir::Left && true == GameEngineInput::IsPress(VK_LEFT, this))
	{
		MovePos = float4::LEFT * _Delta * RunSpeed;
	}

	if (Dir == ActorDir::Right && true == GameEngineInput::IsDown(VK_RIGHT, this)
		|| Dir == ActorDir::Right && true == GameEngineInput::IsPress(VK_RIGHT, this))
	{
		MovePos = float4::RIGHT * _Delta * RunSpeed;
	}


	// Shoot
	if (true == GameEngineInput::IsPress('X', this) && true == IsRunShoot && ShootInterval >= SHOOT_INTERVAL)
	{
		std::shared_ptr<Peashot> Bullet = GetLevel()->CreateActor<Peashot>();
		float4 PlayerPos = Transform.GetWorldPosition();
		Bullet->SetAttackDirAndPos(AttDir, PlayerPos, IsRunShoot);

		ShootInterval = 0.0f;
	}

	ShootInterval += _Delta;

	// Shoot End
	if ((true == GameEngineInput::IsUp('X', this) || true == GameEngineInput::IsFree('X', this))
		&& ((true == GameEngineInput::IsDown(VK_LEFT, this) || true == GameEngineInput::IsPress(VK_LEFT, this))
			|| (true == GameEngineInput::IsDown(VK_RIGHT, this) || true == GameEngineInput::IsPress(VK_RIGHT, this))) )
	{
		IsRunShoot = false;
		ChangeState(CharacterState::Run);
	}

	// Run End
	if (false == IsRunShoot
		&& ((true == GameEngineInput::IsDown('X', this) || true == GameEngineInput::IsPress('X', this)))
		)
	{
		ChangeState(CharacterState::Shoot);
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
	if (true == GameEngineInput::IsUp(VK_DOWN, this) || true == GameEngineInput::IsFree(VK_DOWN, this))
	{
		ChangeState(CharacterState::Idle);
	}
	
	// Aim
	if (true == GameEngineInput::IsDown('C', this) || true == GameEngineInput::IsPress('C', this))
	{
		ChangeState(CharacterState::Aim);
	}

	// Duck Shoot
	if ((true == GameEngineInput::IsDown(VK_DOWN, this) || true == GameEngineInput::IsPress(VK_DOWN, this))
		&& (true == GameEngineInput::IsDown('X', this) || true == GameEngineInput::IsPress('X', this)))
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
	if (true == GameEngineInput::IsUp(VK_DOWN, this) || true == GameEngineInput::IsFree(VK_DOWN, this))
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
	if (true == GameEngineInput::IsUp(VK_DOWN, this) || true == GameEngineInput::IsFree(VK_DOWN, this))
	{
		ChangeState(CharacterState::Idle);
	}
}

void BaseCharacter::FallStart()
{
	ChangeAnimationState("Fall");
}

void BaseCharacter::FallUpdate(float _Delta)
{
	
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

	DashCount = 1;
}

void BaseCharacter::DashUpdate(float _Delta)
{
	// Dash
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

	// Dash Effect
	if (DashCount == 1)
	{
		CreateDashDust();
		DashCount = 0;
	}

	// ChangeState
	if (true == MainRenderer->IsCurAnimationEnd())
	{
		ChangeState(CharacterState::Idle);
	}
}

void BaseCharacter::JumpStart()
{
	ChangeAnimationState("Jump");
	JumpTimer = 0.15f;
	IsJump = true;
	
	JumpHeight.Y = 1600.0f;
}

void BaseCharacter::JumpUpdate(float _Delta)
{
	PixelCheck(_Delta);

	float4 JumpPos = float4::ZERO;
	float4 JumpGravityForce = float4::ZERO;

	JumpTimer -= _Delta;

	if (true == GameEngineInput::IsPress('X', this) && 0.2f >= JumpTimer)
	{
		JumpHeight.Y += 2600.0f * _Delta;
	}

	if (true == IsJump)
	{
		if (JumpHeight.Y >= -1600.0f)
		{
			JumpHeight.Y += -3300.0f * _Delta;
		}

		Transform.AddLocalPosition(JumpHeight * _Delta);
	}

	if (true == GameEngineInput::IsPress(VK_LSHIFT, this))
	{
		ChangeState(CharacterState::Dash);
	}

	if (JumpHeight.Y <= 0.0f && true == IsGround)
	{
		IsJump = false;
		CreateJumpDust();
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