#include "PreCompile.h"
#include "TipsyTroopLevel.h"

#include "BaseCharacter.h"
#include "Cuphead.h"

#include "Martini.h"
#include "Rum.h"
#include "Scotch.h"

TipsyTroopLevel::TipsyTroopLevel()
{
}

TipsyTroopLevel::~TipsyTroopLevel()
{
}

void TipsyTroopLevel::Start()
{
	ContentLevel::Start();
}

void TipsyTroopLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);
}

void TipsyTroopLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentLevel::LevelStart(_PrevLevel);

	// Texture Load
	LevelStartTextureLoad();

	// Background
	CurLevelBackground = CreateActor<ContentBackground>();
	CurLevelBackground->BackgroundInit("kingdice_alcohol_bg_backdrop.png", { -85, 40 });

	// Table 1~4
	std::shared_ptr<ContentActor> Table4 = CreateActor<ContentActor>();
	Table4->SpriteInit("kingdice_alcohol_bg_table4.png", { 550, -230 });

	std::shared_ptr<ContentActor> Table3 = CreateActor<ContentActor>();
	Table3->SpriteInit("kingdice_alcohol_bg_table3.png", { 280, -350 });

	std::shared_ptr<ContentActor> Table2 = CreateActor<ContentActor>();
	Table2->SpriteInit("kingdice_alcohol_bg_table2.png", { 900, -450 });

	std::shared_ptr<ContentActor> Table1 = CreateActor<ContentActor>();
	Table1->SpriteInit("kingdice_alcohol_bg_table1.png", { 300, -500 });


	// SpotLight 1~4
	std::shared_ptr<ContentActor> SpotLight4 = CreateActor<ContentActor>();
	SpotLight4->SpriteInit("kingdice_alcohol_bg_spotlight_table4.png", { 550, -100 });

	std::shared_ptr<ContentActor> SpotLight3 = CreateActor<ContentActor>();
	SpotLight3->SpriteInit("kingdice_alcohol_bg_spotlight_table3.png", { 350, -100 });

	std::shared_ptr<ContentActor> SpotLight2 = CreateActor<ContentActor>();
	SpotLight2->SpriteInit("kingdice_alcohol_bg_spotlight_table2.png", { 900, -200 });

	std::shared_ptr<ContentActor> SpotLight1 = CreateActor<ContentActor>();
	SpotLight1->SpriteInit("kingdice_alcohol_bg_spotlight_table1.png", { 300, -220 });


	// Ground Background
	CurLevelBackground = CreateActor<ContentBackground>();
	CurLevelBackground->BackgroundInit("kingdice_alcohol_bg_Ground_Table.png", { -80, -480 });

	// Pixel Background
	CurLevelPixelBackground = CreateActor<ContentBackground>();
	CurLevelPixelBackground->PixelBackgroundInit("kingdice_alcohol_bg_Ground_Table_pixel.png");

	// Player
	CurLevelPlayer = CreateActor<Cuphead>();
	CurLevelPlayer->Transform.SetLocalPosition({ 250, -550 });

	// Frontground
	std::shared_ptr<ContentActor> LeftPlant = CreateActor<ContentActor>();
	LeftPlant->SpriteInit("kingdice_alcohol_bg_left_plant.png", { 70, -210 });

	std::shared_ptr<ContentActor> Foreground = CreateActor<ContentActor>();
	Foreground->SpriteInit("kingdice_alcohol_bg_Foreground.png", { 620, -520 }, TipsyActorOrder::Foreground);

	// Blend
	std::shared_ptr<ContentActor> Vignette = CreateActor<ContentActor>();
	Vignette->SpriteInit("kingdice_alcohol_bg_vignette.png", { 620, -320 }, TipsyActorOrder::Blend);


	// Boss
	BossMartini = CreateActor<Martini>();
	BossScotch = CreateActor<Scotch>();
	BossRum = CreateActor<Rum>();

}

void TipsyTroopLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}