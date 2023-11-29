#include "PreCompile.h"
#include "BaseCharacter.h"
#include "Peashot.h"

void BaseCharacter::IdleStart()
{
	ChangeAnimationState("Idle");
}

void BaseCharacter::IdleUpdate(float _Delta)
{
	Gravity(_Delta);

	if (true == GameEngineInput::IsPress(VK_LEFT, this) || true == GameEngineInput::IsPress(VK_RIGHT, this))
	{
		ChangeState(CharacterState::Run);
		return;
	}

	if (true == GameEngineInput::IsDown(VK_DOWN, this) || true == GameEngineInput::IsPress(VK_DOWN, this))
	{
		ChangeState(CharacterState::Duck);
		return;
	}

	if (true == GameEngineInput::IsDown(VK_LSHIFT, this))
	{
		ChangeState(CharacterState::Dash);
		return;
	}

	if (true == GameEngineInput::IsDown('Z', this))
	{
		ChangeState(CharacterState::Jump);
		return;
	}

	if (true == GameEngineInput::IsDown('X', this))
	{
		ChangeState(CharacterState::Shoot);
		return;
	}

	if (true == GameEngineInput::IsDown('C', this))
	{
		ChangeState(CharacterState::Aim);
		return;
	}

	HitInterval -= _Delta;
	if (HitInterval < 0.0f)
	{
		if (true == CollisionCheck())
		{
			ChangeState(CharacterState::Hit);
			return;
		}
	}
}


void BaseCharacter::RunStart()
{
	ChangeAnimationState("Run");
	RunDustTimer = 0.3f;
}

void BaseCharacter::RunUpdate(float _Delta)
{
	Gravity(_Delta);
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
		return;
	}

	if (true == GameEngineInput::IsDown('Z', this))
	{
		ChangeState(CharacterState::Jump);
		return;
	}

	if (true == GameEngineInput::IsDown('X', this))
	{
		ChangeState(CharacterState::Shoot);
		return;
	}

	if (true == GameEngineInput::IsDown('C', this) || true == GameEngineInput::IsPress('C', this))
	{
		ChangeState(CharacterState::Aim);
		return;
	}

	if (true == GameEngineInput::IsFree(VK_LEFT, this)
		&& true == GameEngineInput::IsFree(VK_RIGHT, this))
	{
		ChangeState(CharacterState::Idle);
		return;
	}

	HitInterval -= _Delta;
	if (HitInterval < 0.0f)
	{
		if (true == CollisionCheck())
		{
			ChangeState(CharacterState::Hit);
			return;
		}
	}
}

void BaseCharacter::AimStart()
{
	ChangeAnimationState("Aim");
	IsAim = true;
}

void BaseCharacter::AimUpdate(float _Delta)
{
	Gravity(_Delta);

	if (true == GameEngineInput::IsUp('C', this) || true == GameEngineInput::IsFree('C', this))
	{
		IsAim = false;
		ChangeState(CharacterState::Idle);
		return;
	}

	if (true == GameEngineInput::IsDown('X', this))
	{
		IsAim = true;
		ChangeState(CharacterState::Shoot);
		return;
	}

	HitInterval -= _Delta;
	if (HitInterval < 0.0f)
	{
		if (true == CollisionCheck())
		{
			ChangeState(CharacterState::Hit);
			return;
		}
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
	Gravity(_Delta);

	IsRunShoot = AimCheck();

	if (true == GameEngineInput::IsUp('X', this) || true == GameEngineInput::IsFree('X', this))
	{
		ChangeState(CharacterState::Idle);
		return;
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
		return;
	}

	HitInterval -= _Delta;
	if (HitInterval < 0.0f)
	{
		if (true == CollisionCheck())
		{
			ChangeState(CharacterState::Hit);
			return;
		}
	}
}

void BaseCharacter::RunShootStart()
{
	ChangeAnimationState("Run_Shoot");
	ShootInterval = 0.0f;
}

void BaseCharacter::RunShootUpdate(float _Delta)
{
	Gravity(_Delta);
	PixelCheck(_Delta);

	IsRunShoot = AimCheck();

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
		return;
	}

	// Run End
	if (false == IsRunShoot
		&& ((true == GameEngineInput::IsDown('X', this) || true == GameEngineInput::IsPress('X', this)))
		)
	{
		ChangeState(CharacterState::Shoot);
		return;
	}

	// Hit
	HitInterval -= _Delta;
	if (HitInterval < 0.0f)
	{
		if (true == CollisionCheck())
		{
			ChangeState(CharacterState::Hit);
			return;
		}
	}
}

void BaseCharacter::DuckStart()
{
	ChangeAnimationState("Duck");
}

void BaseCharacter::DuckUpdate(float _Delta)
{
	Gravity(_Delta);

	if (true == MainRenderer->IsCurAnimationEnd())
	{
		ChangeState(CharacterState::DuckIdle);
		return;
	}

	if (true == GameEngineInput::IsUp(VK_DOWN, this) || true == GameEngineInput::IsFree(VK_DOWN, this))
	{
		ChangeState(CharacterState::Idle);
		return;
	}

	if (true == GameEngineInput::IsDown('C', this) || true == GameEngineInput::IsPress('C', this))
	{
		ChangeState(CharacterState::Aim);
		return;
	}

	if ((true == GameEngineInput::IsDown(VK_DOWN, this) || true == GameEngineInput::IsPress(VK_DOWN, this))
		&& (true == GameEngineInput::IsDown('X', this) || true == GameEngineInput::IsPress('X', this)))
	{
		ChangeState(CharacterState::DuckShoot);
		return;
	}

	// Hit
	HitInterval -= _Delta;
	if (HitInterval < 0.0f)
	{
		if (true == CollisionCheck())
		{
			ChangeState(CharacterState::Hit);
			return;
		}
	}
}

void BaseCharacter::DuckIdleStart()
{
	ChangeAnimationState("Duck_Idle");
}

void BaseCharacter::DuckIdleUpdate(float _Delta)
{
	Gravity(_Delta);

	if (true == GameEngineInput::IsUp(VK_DOWN, this) || true == GameEngineInput::IsFree(VK_DOWN, this))
	{
		ChangeState(CharacterState::Idle);
		return;
	}

	// Hit
	HitInterval -= _Delta;
	if (HitInterval < 0.0f)
	{
		if (true == CollisionCheck())
		{
			ChangeState(CharacterState::Hit);
			return;
		}
	}
}

void BaseCharacter::DuckShootStart()
{
	ChangeAnimationState("Duck_Shoot");
}

void BaseCharacter::DuckShootUpdate(float _Delta)
{
	Gravity(_Delta);

	if (true == GameEngineInput::IsUp(VK_DOWN, this) || true == GameEngineInput::IsFree(VK_DOWN, this))
	{
		ChangeState(CharacterState::Idle);
		return;
	}

	// Hit
	HitInterval -= _Delta;
	if (HitInterval < 0.0f)
	{
		if (true == CollisionCheck())
		{
			ChangeState(CharacterState::Hit);
			return;
		}
	}
}

void BaseCharacter::FallStart()
{
	ChangeAnimationState("Fall");
}

void BaseCharacter::FallUpdate(float _Delta)
{
	Gravity(_Delta);
}

void BaseCharacter::HitStart()
{
	ChangeAnimationState("Hit");
	CreateHitEffect();
}

void BaseCharacter::HitUpdate(float _Delta)
{
	Gravity(_Delta);

	if (true == MainRenderer->IsCurAnimationEnd())
	{
		// Reset Hit Interval
		HitInterval = 1.0f;
		ChangeState(CharacterState::Idle);
		return;
	}
}

void BaseCharacter::DashStart()
{
	ChangeAnimationState("Dash");
	DashCount = 1;
}

void BaseCharacter::DashUpdate(float _Delta)
{
	Gravity(_Delta);
	PixelCheck(_Delta);

	// Dash
	float DashSpeed = 1000.0f;
	float4 MovePos = float4::ZERO;
	float4 CheckPos = float4::ZERO;

	switch (Dir)
	{
	case ActorDir::Left:
		MovePos = float4::LEFT * _Delta * DashSpeed;
		CheckPos = LEFTCHECKPOS;
		break;
	case ActorDir::Right:
		MovePos = float4::RIGHT * _Delta * DashSpeed;
		CheckPos = RIGHTCHECKPOS;
		break;
	default:
		break;
	}

	if (true == IsJump)
	{
		MovePos.Y -= _Delta * GravityForce.Y;
	}

	GameEngineColor Color = GetPixelColor(CheckPos);

	if (GameEngineColor::RED != Color)
	{
		Transform.AddLocalPosition(MovePos);
	}

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
		return;
	}
}

void BaseCharacter::JumpStart()
{
	ChangeAnimationState("Jump");
	IsJump = true;
	IsParry = false;
	GravityForce = 0.0f;

	if (false == IsParry)
	{
		JumpPower.Y = 1200.0f;
	}

	else if (true == IsParry)
	{
		JumpPower.Y = 300.0f;
	}
}

void BaseCharacter::JumpUpdate(float _Delta)
{
	JumpPower.Y += GravityForce.Y * _Delta;
	Transform.AddLocalPosition(JumpPower * _Delta);

	Gravity(_Delta);
	PixelCheck(_Delta);
	GroundCheck();

	// Change State
	if (true == IsGround)
	{
		IsParry = false;
		IsJump = false;
		CreateJumpDust();
		ChangeState(CharacterState::Idle);
		return;
	}

	if (true == GameEngineInput::IsDown(VK_LSHIFT, this))
	{
		ChangeState(CharacterState::Dash);
		return;
	}

	if (true == GameEngineInput::IsDown('Z', this))
	{
		ChangeState(CharacterState::Parry);
		return;
	}

	// Hit
	HitInterval -= _Delta;
	if (HitInterval < 0.0f)
	{
		if (true == CollisionCheck())
		{
			ChangeState(CharacterState::Hit);
			return;
		}
	}
}

void BaseCharacter::ParryStart()
{
	ChangeAnimationState("Parry");
	GravityForce = 0.0f;

	IsParry = false;
	PauseTimer = 0.2f;
	UnScaleDeltaTime = GameEngineCore::MainTime.GetUnScaleDeltaTime();
}

void BaseCharacter::ParryUpdate(float _Delta)
{
	Gravity(_Delta);
	PixelCheck(_Delta);
	GroundCheck();

	ParryCollisionCheck();
	if (true == IsParry && ParryCount == 0 )
	{
		ParryCount = 1;
		CreateParrySpark();
	}

	if (ParryCount == 1)
	{
		PauseTimer -= UnScaleDeltaTime;
		if (PauseTimer > 0.0f)
		{
			GameEngineCore::MainTime.SetGlobalTimeScale(0);
		}

		else if (PauseTimer < 0.0f)
		{
			GameEngineCore::MainTime.SetGlobalTimeScale(1);
			ChangeState(CharacterState::Jump);
			ParryCount = 0;

			// Idle
			if (true == IsGround)
			{
				IsJump = false;
				IsParry = false;
				CreateJumpDust();
				ChangeState(CharacterState::Idle);
				return;
			}

			// Hit
			HitInterval -= _Delta;
			if (HitInterval < 0.0f)
			{
				if (true == CollisionCheck())
				{
					ChangeState(CharacterState::Hit);
					return;
				}
			}

			return;
		}
	}

	if (true == MainRenderer->IsCurAnimation("Cuphead_Parry")
		&& true == MainRenderer->IsCurAnimationEnd())
	{
		ChangeState(CharacterState::Idle);
		return;
	}
}

void BaseCharacter::IntroStart()
{
	ChangeAnimationState("Intro");
}

void BaseCharacter::IntroUpdate(float _Delta)
{
	Gravity(_Delta);

	if (true == MainRenderer->IsCurAnimationEnd())
	{
		ChangeState(CharacterState::Idle);
		return;
	}
}

void BaseCharacter::GhostStart()
{
	ChangeAnimationState("Ghost");
}

void BaseCharacter::GhostUpdate(float _Delta)
{
	Gravity(_Delta);
}

void BaseCharacter::DeathStart()
{
	ChangeAnimationState("Death");
}

void BaseCharacter::DeathUpdate(float _Delta)
{
	Gravity(_Delta);
}