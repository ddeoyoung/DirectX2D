#include "PreCompile.h"
#include "KingDice.h"
#include "Dice.h"
#include "Marker.h"

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
		IdleTimer = 0.0f;
		ChangeState(KingDiceState::Reveal);
		return;
	}

	IdleTimer += _Delta;

	// 마커 이동 완료
	if (true == Marker::IsSpinEnd && true == Marker::IsTurnEnd)
	{
		Marker::IsTurnEnd = false;
		ChangeState(KingDiceState::Curious);
		return;
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
	CuriousTimer = 2.0f;
}

void KingDice::CuriousUpdate(float _Delta)
{
	CuriousTimer -= _Delta;
	if (CuriousTimer < 0.0f)
	{
		HeadRenderer->Off();

		if (true == IsSafeSpace)
		{
			ChangeState(KingDiceState::Reveal);
			return;
		}

		else if (false == IsSafeSpace)
		{
			ChangeState(KingDiceState::CameraEat);
			return;
		}
	}
}

void KingDice::RevealStart()
{
	ChangeAnimationState("Reveal");

	Transform.AddLocalPosition({ 0 , -247 });

	// Dice 생성
	PinkDice = GetLevel()->CreateActor<Dice>();
	PinkDice->Transform.SetLocalPosition({ 660.0f, -500.0f });
	PinkDice->Off();

	ShowDiceTimer = 1.5f;

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
		return;
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////// Attack //////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void KingDice::AttackStart()
{
	RandomAttackDir();
	SetAttackPos();
	HeadRenderer->Off();
	AttackCount = 7;
	CardInter = 0.0f;
	std::string AnimationName = "Attack_" + AttackDir;
	ChangeAnimationState(AnimationName);

	// Arm
	SetAttackArm();
}

void KingDice::AttackUpdate(float _Delta)
{
	CheckAttackCount();

	if (AttackCount == 0)
	{
		std::string AnimationName = "KingDice_Attack_" + AttackDir + "_End";
		MainRenderer->ChangeAnimation(AnimationName);
		ArmRenderer->Off();
	}

	bool CheckLoop = IsAttackLoop();

	CardInter += _Delta;
	if (CardInter > 0.5f && true == CheckLoop)
	{
		CreateCards();
		CardInter = 0.0f;
	}
}

void KingDice::AttackIdleStart()
{
	ChangeAnimationState("AttackIdle");
	ResetAttackPos();
	AttackIdleTime = 0.0f;
}

void KingDice::AttackIdleUpdate(float _Delta)
{
	AttackIdleTime += _Delta;
	if (AttackIdleTime > 3.0f)
	{
		ChangeState(KingDiceState::Attack);
		return;
	}
}