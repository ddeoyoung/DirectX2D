#include "PreCompile.h"
#include "MrWheezyLevel.h"

#include "BaseCharacter.h"
#include "Cuphead.h"
#include "MrWheezy.h"

#include "Background_Smokers.h"
#include "TopSmoke.h"
#include "CigarFire.h"
#include "FightText.h"
#include "FadeAnimation.h"

MrWheezyLevel::MrWheezyLevel()
{
}

MrWheezyLevel::~MrWheezyLevel()
{
}

void MrWheezyLevel::Start()
{
	ContentLevel::Start();
}

void MrWheezyLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);

	CheckStageClear();
	CreateFadeOut(_Delta);

	if (true == FadeOut->IsCurAnimationEnd())
	{
		// Level Change - King Dice
		GameEngineCore::ChangeLevel("KingDiceLevel");
	}
}

void MrWheezyLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentLevel::LevelStart(_PrevLevel);

	LevelStartTextureLoad();
	LevelStartTextureSet();

	// FightText
	Ready = CreateActor<FightText>();
	Ready->SetFightText("Ready");

	// Background (Loop)
	Background = CreateActor<Background_Smokers>();

	// Pixel Background
	CurLevelPixelBackground = CreateActor<ContentBackground>();
	CurLevelPixelBackground->PixelBackgroundInit("kd_cigar_bg_pixel.png");

	// Player
	CurLevelPlayer = CreateActor<Cuphead>();
	CurLevelPlayer->Transform.SetLocalPosition({ 250, -400 });
	CurLevelPlayer->SetCharacterState(CharacterState::Intro);

	// Boss
	Boss = CreateActor<MrWheezy>();

	// CigarFire
	std::shared_ptr<CigarFire> CigarFireBack = CreateActor<CigarFire>();
	CigarFireBack->SetFireTypeAndPos("Back", {640, -700}, (int)RenderOrder::BackgroundObject);
	std::shared_ptr<CigarFire> CigarFireMiddle = CreateActor<CigarFire>();
	CigarFireMiddle->SetFireTypeAndPos("Middle", {640, -780}, (int)RenderOrder::FrontgroundObject3);
	std::shared_ptr<CigarFire> CigarFireFront = CreateActor<CigarFire>();
	CigarFireFront->SetFireTypeAndPos("Front", {640, -850}, (int)RenderOrder::FrontgroundObject3);

	// Smoke
	std::shared_ptr<TopSmoke> BackgroundSmoke = CreateActor<TopSmoke>();

	// Fade Out
	if (nullptr == FadeOut)
	{
		FadeOut = CreateActor<FadeAnimation>();
		FadeOut->SetFade("Out");
		FadeOut->Off();
	}
}

void MrWheezyLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}


void MrWheezyLevel::CreateKnockOut()
{
	KnockOut = CreateActor<FightText>();
	KnockOut->SetFightText("KnockOut");
}

void MrWheezyLevel::CreateBossExplosion()
{
	Boss->CreateDeathEffect();
}

void MrWheezyLevel::CheckStageClear()
{
	bool CheckWheezyDeath = Boss->GetIsDeath();

	if (false == IsStageClear
		&& true == CheckWheezyDeath)
	{
		IsStageClear = true;
		CreateKnockOut();
		CreateBossExplosion();
	}
}

void MrWheezyLevel::CreateFadeOut(float _Delta)
{
	if (true == IsStageClear)
	{
		StageClearTime += _Delta;
		if (StageClearTime > 5.0f)
		{
			FadeOut->On();
		}
	}
}