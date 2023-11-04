#include "PreCompile.h"
#include "OverWorldCharacter.h"

void OverWorldCharacter::IdleStart()
{
	ChangeAnimationState("Idle");
}

void OverWorldCharacter::IdleUpdate(float _Delta)
{

}

void OverWorldCharacter::WalkStart()
{
	ChangeAnimationState("Walk");
}

void OverWorldCharacter::WalkUpdate(float _Delta)
{

}

void OverWorldCharacter::WinStart()
{
	ChangeAnimationState("Win");
}

void OverWorldCharacter::WinUpdate(float _Delta)
{

}
