#include "PreCompile.h"
#include "BaseCharacter.h"

void BaseCharacter::IdleStart()
{
	ChangeAnimationState("Idle");
}

void BaseCharacter::IdleUpdate(float _Delta)
{
	if (true == GameEngineInput::IsPress(VK_LEFT) || true == GameEngineInput::IsPress(VK_RIGHT))
	{
		DirCheck();
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
}


void BaseCharacter::RunStart()
{
	ChangeAnimationState("Run");
}

void BaseCharacter::RunUpdate(float _Delta)
{
	DirCheck();

	float RunSpeed = 400.0f;
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

}

void BaseCharacter::ShootStart()
{
	ChangeAnimationState("Shoot");
}

void BaseCharacter::ShootUpdate(float _Delta)
{

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

	if (true == GameEngineInput::IsUp(VK_DOWN) || true == GameEngineInput::IsFree(VK_DOWN))
	{
		ChangeState(CharacterState::Idle);
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

	float DashSpeed = 800.0f;
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

	Transform.AddLocalPosition(MovePos);
}

void BaseCharacter::JumpStart()
{
	ChangeAnimationState("Jump");
}

void BaseCharacter::JumpUpdate(float _Delta)
{
	float JumpTimer = 0.0f;
	float4 JumpPos = float4::ZERO;
	float4 JumpGravityForce = float4::ZERO;

	if (true == GameEngineInput::IsPress('Z') && 0.2f >= JumpTimer)
	{
		JumpPos.Y += 1500.0f * _Delta;
	}

	Transform.AddLocalPosition(JumpPos);


	if (true == MainRenderer->IsCurAnimationEnd())
	{
		JumpTimer = 0.0f;
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