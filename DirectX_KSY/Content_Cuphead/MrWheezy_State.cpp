#include "PreCompile.h"
#include "MrWheezy.h"

void MrWheezy::IntroStart()
{
	ChangeAnimationState("Intro");
}

void MrWheezy::IntroUpdate(float _Delta)
{

}

void MrWheezy::IdleStart()
{
	ChangeAnimationState("Idle");
	IdleTime = 0.0f;
}

void MrWheezy::IdleUpdate(float _Delta)
{
	IdleTime += _Delta;
	if (IdleTime > 2.0f)
	{
		if (AttackCount >= 3)
		{
			AttackCount = 0;
			ChangeState(WheezyState::Teleport);
			return;
		}

		ChangeState(WheezyState::Attack);
		return;
	}
}

void MrWheezy::AttackStart()
{
	ChangeAnimationState("Attack");
}

void MrWheezy::AttackUpdate(float _Delta)
{
	if (true == MainRenderer->IsCurAnimationEnd())
	{
		AttackCount += 1;
		ChangeState(WheezyState::Idle);
	}
}

void MrWheezy::TeleportStart()
{
	ChangeAnimationState("Teleport");
}

void MrWheezy::TeleportUpdate(float _Delta)
{
	if (true == MainRenderer->IsCurAnimation("MrWheezy_Teleport3")
		&& true == MainRenderer->IsCurAnimationEnd())
	{
		ReverseDir();

		if (Dir == -1)
		{
			/*MainRenderer->*/Transform.AddLocalPosition({ -850, 0 });
		}

		else if (Dir == 1)
		{
			/*MainRenderer->*/Transform.AddLocalPosition({ 850, 0 });
		}

		ChangeState(WheezyState::Idle);
		return;
	}
}

void MrWheezy::DeathStart()
{
	ChangeAnimationState("Death");
}

void MrWheezy::DeathUpdate(float _Delta)
{

}