#include "PreCompile.h"
#include "BaseCharacter.h"

void BaseCharacter::IdleStart()
{
	ChangeAnimationState("Idle");
}

void BaseCharacter::IdleUpdate(float _Delta)
{
	if (true == GameEngineInput::IsDown(VK_LEFT) || true == GameEngineInput::IsPress(VK_LEFT)
		|| true == GameEngineInput::IsDown(VK_RIGHT) || true == GameEngineInput::IsPress(VK_RIGHT)
		|| true == GameEngineInput::IsDown(VK_UP) || true == GameEngineInput::IsPress(VK_UP)
		|| true == GameEngineInput::IsDown(VK_DOWN) || true == GameEngineInput::IsPress(VK_DOWN))
	{
		DirCheck();
		ChangeState(CharacterState::Run);
		return;
	}
}


void BaseCharacter::RunStart()
{
	ChangeAnimationState("Run");
}

void BaseCharacter::RunUpdate(float _Delta)
{
	if	(true == GameEngineInput::IsUp(VK_LEFT)
		|| true == GameEngineInput::IsUp(VK_RIGHT)		
		|| true == GameEngineInput::IsUp(VK_UP)		
		|| true == GameEngineInput::IsUp(VK_DOWN))
	{
		ChangeState(CharacterState::Idle);
		return;
	}

	DirCheck();

	
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

}

void BaseCharacter::JumpStart()
{
	ChangeAnimationState("Jump");
}

void BaseCharacter::JumpUpdate(float _Delta)
{

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