#include "PreCompile.h"
#include "ChipsBettigan.h"
#include "Attack_Chips.h"


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

	CheckIdleDir();
}

void ChipsBettigan::IdleUpdate(float _Delta)
{
	if (MainTimer > 3.0f)
	{
		ChangeState(ChipsState::Spin);
		MainTimer = 0.0f;
	}

	MainTimer += _Delta;
}

void ChipsBettigan::SpinStart()
{
	ChangeAnimationState("Spin");

	CheckAttackDir();

	StretchTimer = 1.0f;
	AttackTimer = ATTACKTIME;
	IsStretch = false;
	FirstAttack = false;
	SecondAttack = false;
	ThirdAttack = false;
	IsSpinEnd = false;

	// Head
	Transform.AddLocalPosition({ 0, 260.0f });
	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("Chips_Spin_Head");
	float4 Scale = Texture->GetSpriteData(0).GetScale();
	BossCollision->Transform.SetLocalScale(Scale);
	BossCollision->Transform.SetLocalPosition({ 0, Scale.hY() });

	// Middle, Bottom (공격용 칩 생성)
	CreateChips();
}

void ChipsBettigan::SpinUpdate(float _Delta)
{
	// Stretch Up
	if (StretchTimer > 0.0f)
	{
		StretchChips(_Delta, IsStretch);
	}

	StretchTimer -= _Delta;

	if (StretchTimer < 0.0f && false == IsSpinEnd)
	{
		IsStretch = true;
	}


	// Attack
	if (true == IsStretch && false == IsSpinEnd)
	{
		SpinAttack(_Delta);
	}

	// Stretch Down
	if (true == SecondAttack)
	{
		StretchTimer = 1.0f;
		IsSpinEnd = true;
		SecondAttack = false;
	}

	if (StretchTimer < 0.0f && true == IsSpinEnd)
	{
		DeathChips();
		Transform.AddLocalPosition({ 0, -260.0f });
		ChangeState(ChipsState::Idle);
	}
}

void ChipsBettigan::DeathStart()
{
	ChangeAnimationState("Death");
}

void ChipsBettigan::DeathUpdate(float _Delta)
{

}
