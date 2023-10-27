#include "PreCompile.h"
#include "MrWheezyLevel.h"

#include "BaseCharacter.h"
#include "Cuphead.h"
#include "MrWheezy.h"

#include "Background_Smokers.h"
#include "TopSmoke.h"
#include "CigarFire.h"
#include "FightText.h"

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
}

void MrWheezyLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentLevel::LevelStart(_PrevLevel);

	LevelStartTextureLoad();
	LevelStartTextureSet();

	// FightText
	std::shared_ptr<FightText> Ready = CreateActor<FightText>();
	Ready->SetFightText("Ready");

	// Background
	std::shared_ptr<Background_Smokers> Background = CreateActor<Background_Smokers>();

	// Pixel Background
	CurLevelPixelBackground = CreateActor<ContentBackground>();
	CurLevelPixelBackground->PixelBackgroundInit("kd_cigar_bg_pixel.png");

	// Player
	CurLevelPlayer = CreateActor<Cuphead>();
	CurLevelPlayer->Transform.SetLocalPosition({ 250, -400 });

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
}

void MrWheezyLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}