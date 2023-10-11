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

	StretchTimer = 1.0f;

	// Head
	Transform.AddLocalPosition({ 0, 260 });
	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("Chips_Spin_Head");
	float4 Scale = Texture->GetSpriteData(0).GetScale();
	BossCollision->Transform.SetLocalScale(Scale);
	BossCollision->Transform.SetLocalPosition({ 0, Scale.hY() });

	// Middle, Bottom (공격용 칩 생성)
	CreateChips();
}

void ChipsBettigan::SpinUpdate(float _Delta)
{
	if (StretchTimer > 0.0f)
	{
		StretchChips(_Delta);
	}

	StretchTimer -= _Delta;
}

void ChipsBettigan::DeathStart()
{
	ChangeAnimationState("Death");
}

void ChipsBettigan::DeathUpdate(float _Delta)
{

}
