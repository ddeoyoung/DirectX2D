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

	// CigarFire
	std::shared_ptr<CigarFire> CigarFireBack = CreateActor<CigarFire>();
	CigarFireBack->SetFireTypeAndPos("Back", {640, -700});
	std::shared_ptr<CigarFire> CigarFireMiddle = CreateActor<CigarFire>();
	CigarFireMiddle->SetFireTypeAndPos("Middle", {640, -800});
	std::shared_ptr<CigarFire> CigarFireFront = CreateActor<CigarFire>();
	CigarFireFront->SetFireTypeAndPos("Front", {640, -900});

	// Smoke
	std::shared_ptr<TopSmoke> BackgroundSmoke = CreateActor<TopSmoke>();
}

void MrWheezyLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}