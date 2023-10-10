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

	// Head
	Transform.AddLocalPosition({ 0, 260 });

	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("Chips_Spin_Head");
	float4 Scale = Texture->GetSpriteData(0).GetScale();

	BossCollision->Transform.SetLocalScale(Scale);
	BossCollision->Transform.SetLocalPosition({ 0, Scale.hY() });

	StretchTimer = 1.0f;

	// 공격용 칩 생성 (Middle, Bottom)
	CreateChips();
}

void ChipsBettigan::SpinUpdate(float _Delta)
{
	float StretchSpeed = 160.0f;
	float4 MovePos = { 0.0f, StretchSpeed * _Delta };

	if (StretchTimer > 0.0f)
	{
		Transform.AddLocalPosition(MovePos);

		for (int i = 0; i < ChipSet.size(); i++)
		{
			float ChipSpeed = 15.0f * (i + 1);
			float4 MoveChipPos = { 0.0f, ChipSpeed * _Delta};
			ChipSet[i]->Transform.AddLocalPosition(MoveChipPos);
		}
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
