#include "PreCompile.h"
#include "TipsyTroopLevel.h"

void TipsyTroopLevel::LevelStartTextureLoad()
{
	// Background
	if (nullptr == GameEngineSprite::Find("kingdice_alcohol_bg_backdrop.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\TipsyTroop\\StageObject");

		// Far Background (Drop)
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_backdrop.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_backdrop.png");

		// Ground Background (Table)
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_Ground_Table.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_Ground_Table.png");

		// Pixel Background
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_Ground_Table_pixel.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_Ground_Table_pixel.png");
	}

	// Background Object - Spotlight 1 ~ 4
	if (nullptr == GameEngineSprite::Find("kingdice_alcohol_bg_spotlight_table1.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\TipsyTroop\\StageObject");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_spotlight_table1.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_spotlight_table1.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_spotlight_table2.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_spotlight_table2.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_spotlight_table3.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_spotlight_table3.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_spotlight_table4.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_spotlight_table4.png");
	}

	// Background Object - Table 1 ~ 4
	if (nullptr == GameEngineSprite::Find("kingdice_alcohol_bg_table1.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\TipsyTroop\\StageObject");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_table1.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_table1.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_table2.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_table2.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_table3.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_table3.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_table4.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_table4.png");
	}

	// Background Object - Demons
	if (nullptr == GameEngineSprite::Find("kingdice_alcohol_bg_beastlady.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\TipsyTroop\\StageObject");

		// Beast Lady
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_beastlady.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_beastlady.png");

		// Demon Lord
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_demon_lord.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_demon_lord.png");

		// Demon Pair
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_demon_pair.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_demon_pair.png");

		// Fancy Couple
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_fancy_couple.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_fancy_couple.png");

		// Floating Demon
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_floating_demon.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_floating_demon.png");

		// Fur Stole Woman
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_fur_stole_woman.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_fur_stole_woman.png");

		// Ghost
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_Ghost.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_Ghost.png");

		// Horse Skeleton
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_horse_skeleton.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_horse_skeleton.png");

		// Mob Couple
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_mob_couple.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_mob_couple.png");

		// Tired Demon
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_tired_demon.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_tired_demon.png");
	}

}