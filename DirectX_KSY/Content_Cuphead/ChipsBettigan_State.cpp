#include "PreCompile.h"
#include "ChipsBettigan.h"


void ChipsBettigan::IntroStart()
{
	ChangeAnimationState("Intro");
}

void ChipsBettigan::IntroUpdate(float _Delta)
{

}

void ChipsBettigan::IdleStart()
{
	ChangeAnimationState("Idle");

	MainTimer = 0.0f;
}

void ChipsBettigan::IdleUpdate(float _Delta)
{
	if (MainTimer > 4.0f)
	{
		ChangeState(ChipsState::Spin);
		MainTimer = 0.0f;
	}

	MainTimer += _Delta;
}

void ChipsBettigan::SpinStart()
{
	ChangeAnimationState("Spin");
}

void ChipsBettigan::SpinUpdate(float _Delta)
{

}

void ChipsBettigan::DeathStart()
{
	ChangeAnimationState("Death");
}

void ChipsBettigan::DeathUpdate(float _Delta)
{

}
