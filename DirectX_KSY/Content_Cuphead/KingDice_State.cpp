#include "PreCompile.h"
#include "KingDice.h"

void KingDice::IntroHandStart()
{
	ChangeAnimationState("IntroHand");
}

void KingDice::IntroHandUpdate(float _Delta)
{

}

void KingDice::IntroBodyStart()
{
	ChangeAnimationState("IntroBody");
}

void KingDice::IntroBodyUpdate(float _Delta)
{

}

void KingDice::IdleStart()
{
	ChangeAnimationState("Idle");
	IdleTimer = 0.0f;
}

void KingDice::IdleUpdate(float _Delta)
{
	if (IdleTimer > 3.0f)
	{
		Transform.AddLocalPosition({ 0 , -247 });
		ChangeState(KingDiceState::Reveal);
	}

	IdleTimer += _Delta;

	if (true == GameEngineInput::IsDown('P', this))
	{
		ChangeState(KingDiceState::CameraEat);
	}
}

void KingDice::WinkStart()
{
	ChangeAnimationState("Wink");
}

void KingDice::WinkUpdate(float _Delta)
{

}

void KingDice::CuriousStart()
{
	ChangeAnimationState("Curious");
}

void KingDice::CuriousUpdate(float _Delta)
{

}

void KingDice::RevealStart()
{
	ChangeAnimationState("Reveal");
}

void KingDice::RevealUpdate(float _Delta)
{

}

void KingDice::CameraEatStart()
{
	ChangeAnimationState("CameraEat");
}

void KingDice::CameraEatUpdate(float _Delta)
{
	//GameEngineCore::ChangeLevel("ChipsBettiganLevel");
}

void KingDice::DeathStart()
{
	ChangeAnimationState("Death");
}

void KingDice::DeathUpdate(float _Delta)
{

}