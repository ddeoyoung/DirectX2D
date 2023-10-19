#include "PreCompile.h"
#include "KingDice.h"
#include "Dice.h"

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
	if (false == IsDiceOn && IdleTimer > 3.0f)
	{
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

	Transform.AddLocalPosition({ 0 , -247 });

	// Dice »ý¼º
	PinkDice = GetLevel()->CreateActor<Dice>();
	PinkDice->Transform.SetLocalPosition({ 660.0f, -500.0f });
	PinkDice->Off();

	ShowDiceTimer = 1.0f;

	IsDiceOn = true;
}

void KingDice::RevealUpdate(float _Delta)
{
	ShowDiceTimer -= _Delta;

	if (ShowDiceTimer <= 0.0f)
	{
		PinkDice->On();
	}


	if (true == MainRenderer->IsCurAnimationEnd())
	{
		Transform.AddLocalPosition({ 0 , 247 });
		ChangeState(KingDiceState::Idle);
	}
}

void KingDice::CameraEatStart()
{
	ChangeAnimationState("CameraEat");
}

void KingDice::CameraEatUpdate(float _Delta)
{

}

void KingDice::DeathStart()
{
	ChangeAnimationState("Death");
}

void KingDice::DeathUpdate(float _Delta)
{

}