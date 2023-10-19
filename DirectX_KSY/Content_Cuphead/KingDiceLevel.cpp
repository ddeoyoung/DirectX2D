#include "PreCompile.h"
#include "KingDiceLevel.h"

#include "ContentBackground.h"
#include "BaseCharacter.h"
#include "Cuphead.h"
#include "KingDice.h"
#include "KD_Chips.h"
#include "Roulette_Heart.h"


KingDiceLevel::KingDiceLevel()
{
}

KingDiceLevel::~KingDiceLevel()
{
}

void KingDiceLevel::Start()
{
	ContentLevel::Start();
}

void KingDiceLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);
}

void KingDiceLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentLevel::LevelStart(_PrevLevel);

	LevelStartTextureLoad();

	// Background
	CurLevelBackground = CreateActor<ContentBackground>();
	CurLevelBackground->BackgroundInit("kd_bg_painting.png");

	CurLevelPixelBackground = CreateActor<ContentBackground>();
	CurLevelPixelBackground->PixelBackgroundInit("kd_bg_table_pixel.bmp");

	// Frontground
	std::shared_ptr<ContentBackground> Frontground = CreateActor<ContentBackground>();
	Frontground->BackgroundInit("kd_bg_table2.png", { -60, -220 });
	std::shared_ptr<KD_Chips> Chips = CreateActor<KD_Chips>();

	// Boss
	Boss = CreateActor<KingDice>();

	// Player
	std::shared_ptr<BaseCharacter> Player = CreateActor<Cuphead>();
	Player->Transform.SetLocalPosition({ 250, -550 });

}

void KingDiceLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}