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
	IdleTimer = 0.0f;
	CheckIdleDir();
}

void ChipsBettigan::IdleUpdate(float _Delta)
{
	DeathCheck();

	IdleTimer += _Delta;
	if (IdleTimer > 3.0f)
	{
		IdleTimer = 0.0f;
		ChangeState(ChipsState::Spin);
		return;
	}
}

void ChipsBettigan::SpinStart()
{
	ChangeAnimationState("Spin");

	CheckAttackDir();

	StretchTimer = 1.0f;
	AttackTimer = CHIPATTACKTIME;
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
	DeathCheck();

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
		std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("Chips_Idle");
		float4 Scale = Texture->GetSpriteData(0).GetScale();
		Scale -= { 80.0f, 60.0f };
		BossCollision->Transform.SetLocalScale(Scale);
		BossCollision->Transform.SetLocalPosition({ 0, Scale.hY() });
		ChangeState(ChipsState::Idle);
		return;
	}
}

void ChipsBettigan::DeathStart()
{
	ChangeAnimationState("Death");
	CheckDeathDir();

	float4 CurPos = Transform.GetLocalPosition();
	CurPos.Y = -200.0f;
	Transform.SetLocalPosition(CurPos);
}

void ChipsBettigan::DeathUpdate(float _Delta)
{
	float4 MovePos = { 0.0f, CHIPFALLSPEED * _Delta};
	float4 CurPos = Transform.GetLocalPosition();

	if (CurPos.Y > -640.0f)
	{
		Transform.AddLocalPosition(MovePos);
	}

}
