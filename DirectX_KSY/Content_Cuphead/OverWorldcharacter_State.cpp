#include "PreCompile.h"
#include "OverWorldCharacter.h"

void OverWorldCharacter::IdleStart()
{
	ChangeAnimationState("Idle");
}

void OverWorldCharacter::IdleUpdate(float _Delta)
{
	if (true == GameEngineInput::IsPress(VK_LEFT, this) || true == GameEngineInput::IsPress(VK_RIGHT, this)
		|| (true == GameEngineInput::IsPress(VK_UP, this) || true == GameEngineInput::IsPress(VK_DOWN, this)))
	{
		ChangeState(OverWorldCharacterState::Walk);
	}
}

void OverWorldCharacter::WalkStart()
{
	ChangeAnimationState("Walk");
}

void OverWorldCharacter::WalkUpdate(float _Delta)
{
	PixelCheck(_Delta);

	if (true == GameEngineInput::IsUp(VK_LEFT, this) || true == GameEngineInput::IsUp(VK_RIGHT, this)
		|| (true == GameEngineInput::IsUp(VK_UP, this) || true == GameEngineInput::IsUp(VK_DOWN, this)))
	{
		ChangeState(OverWorldCharacterState::Idle);
	}
}

void OverWorldCharacter::WinStart()
{
	//ChangeAnimationState("Win");
}

void OverWorldCharacter::WinUpdate(float _Delta)
{

}
