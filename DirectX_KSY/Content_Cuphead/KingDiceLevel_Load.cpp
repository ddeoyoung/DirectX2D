#include "PreCompile.h"
#include "KingDiceLevel.h"
#include "KD_Chips.h"

void KingDiceLevel::LevelStartTextureLoad()
{
	// Background
	if (nullptr == GameEngineSprite::Find("kd_bg_painting.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\KingDice\\StageObject\\Background\\kd_bg_painting.png");

		// 페인팅 배경(위)
		GameEngineTexture::Load(Dir.GetStringPath());
		GameEngineSprite::CreateSingle("kd_bg_painting.png");

		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\KingDice\\StageObject\\Table");

		// 테이블 배경(아래)
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_bg_table.png");
		GameEngineSprite::CreateSingle("kd_bg_table.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_bg_table2.png");
		GameEngineSprite::CreateSingle("kd_bg_table2.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_bg_table_pixel.bmp");
		GameEngineSprite::CreateSingle("kd_bg_table_pixel.bmp");
	}

	// KingDice Roulette Heart
	if (nullptr == GameEngineSprite::Find("kd_gb_heart_01.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\KingDice\\StageObject\\Heart\\");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_heart_01.png");
		GameEngineSprite::CreateSingle("kd_gb_heart_01.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_heart_02.png");
		GameEngineSprite::CreateSingle("kd_gb_heart_02.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_heart_03.png");
		GameEngineSprite::CreateSingle("kd_gb_heart_03.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_heart_04.png");
		GameEngineSprite::CreateSingle("kd_gb_heart_04.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_heart_05.png");
		GameEngineSprite::CreateSingle("kd_gb_heart_05.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_heart_06.png");
		GameEngineSprite::CreateSingle("kd_gb_heart_06.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_heart_07.png");
		GameEngineSprite::CreateSingle("kd_gb_heart_07.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_heart_08.png");
		GameEngineSprite::CreateSingle("kd_gb_heart_08.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_heart_09.png");
		GameEngineSprite::CreateSingle("kd_gb_heart_09.png");
	}

	// KingDice Roulette Odds
	if (nullptr == GameEngineSprite::Find("kd_gb_main_odds_01.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\KingDice\\StageObject\\Odds\\");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_main_odds_01.png");
		GameEngineSprite::CreateSingle("kd_gb_main_odds_01.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_main_odds_02.png");
		GameEngineSprite::CreateSingle("kd_gb_main_odds_02.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_main_odds_03.png");
		GameEngineSprite::CreateSingle("kd_gb_main_odds_03.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_main_odds_04.png");
		GameEngineSprite::CreateSingle("kd_gb_main_odds_04.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_main_odds_05.png");
		GameEngineSprite::CreateSingle("kd_gb_main_odds_05.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_main_odds_06.png");
		GameEngineSprite::CreateSingle("kd_gb_main_odds_06.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_main_odds_07.png");
		GameEngineSprite::CreateSingle("kd_gb_main_odds_07.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_main_odds_08.png");
		GameEngineSprite::CreateSingle("kd_gb_main_odds_08.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_main_odds_09.png");
		GameEngineSprite::CreateSingle("kd_gb_main_odds_09.png");
	}

	// KingDice Roulette Spaces
	if (nullptr == GameEngineSprite::Find("kd_gb_space_01.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\KingDice\\StageObject\\Spaces\\");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_space_01.png");
		GameEngineSprite::CreateSingle("kd_gb_space_01.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_space_02.png");
		GameEngineSprite::CreateSingle("kd_gb_space_02.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_space_03.png");
		GameEngineSprite::CreateSingle("kd_gb_space_03.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_space_04.png");
		GameEngineSprite::CreateSingle("kd_gb_space_04.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_space_05.png");
		GameEngineSprite::CreateSingle("kd_gb_space_05.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_space_06.png");
		GameEngineSprite::CreateSingle("kd_gb_space_06.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_space_07.png");
		GameEngineSprite::CreateSingle("kd_gb_space_07.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_space_08.png");
		GameEngineSprite::CreateSingle("kd_gb_space_08.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_space_09.png");
		GameEngineSprite::CreateSingle("kd_gb_space_09.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_space_fin.png");
		GameEngineSprite::CreateSingle("kd_gb_space_fin.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_space_fin_complete.png");
		GameEngineSprite::CreateSingle("kd_gb_space_fin_complete.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "kd_gb_space_start_over.png");
		GameEngineSprite::CreateSingle("kd_gb_space_start_over.png");
	}
}

void KingDiceLevel::LevelStartTextureSet()
{
	// Background
	CurLevelBackground = CreateActor<ContentBackground>();
	CurLevelBackground->BackgroundInit("kd_bg_painting.png");

	CurLevelPixelBackground = CreateActor<ContentBackground>();
	CurLevelPixelBackground->PixelBackgroundInit("kd_bg_table_pixel.bmp");

	// Frontground
	std::shared_ptr<ContentBackground> Frontground = CreateActor<ContentBackground>();
	Frontground->BackgroundInit("kd_bg_table2.png", { -60, -220 });
	std::shared_ptr<KD_Chips> Chips = CreateActor<KD_Chips>();

	// Roulette - Heart
	std::shared_ptr<ContentActor> Heart1 = CreateActor<ContentActor>();
	Heart1->SpriteInit("kd_gb_heart_01.png", { 349, -329 });

	std::shared_ptr<ContentActor> Heart6 = CreateActor<ContentActor>();
	Heart6->SpriteInit("kd_gb_heart_06.png", { 677, -481 });

	std::shared_ptr<ContentActor> Heart9 = CreateActor<ContentActor>();
	Heart9->SpriteInit("kd_gb_heart_09.png", { 905, -415 });


	// Roulette - Odd
	std::shared_ptr<ContentActor> Odd2 = CreateActor<ContentActor>();
	Odd2->SpriteInit("kd_gb_main_odds_02.png", { 387, -374 });

	std::shared_ptr<ContentActor> Odd3 = CreateActor<ContentActor>();
	Odd3->SpriteInit("kd_gb_main_odds_03.png", { 434, -414 });

	std::shared_ptr<ContentActor> Odd4 = CreateActor<ContentActor>();
	Odd4->SpriteInit("kd_gb_main_odds_04.png", { 552, -466 });

	std::shared_ptr<ContentActor> Odd5 = CreateActor<ContentActor>();
	Odd5->SpriteInit("kd_gb_main_odds_05.png", { 614, -479 });

	std::shared_ptr<ContentActor> Odd7 = CreateActor<ContentActor>();
	Odd7->SpriteInit("kd_gb_main_odds_07.png", { 802, -463 });

	std::shared_ptr<ContentActor> Odd8 = CreateActor<ContentActor>();
	Odd8->SpriteInit("kd_gb_main_odds_08.png", { 855, -443 });


	// KingDice Roulette Spaces
	std::shared_ptr<ContentActor> Space1 = CreateActor<ContentActor>();
	Space1->SpriteInit("kd_gb_space_01.png", { 300, -352 });

	std::shared_ptr<ContentActor> Space2 = CreateActor<ContentActor>();
	Space2->SpriteInit("kd_gb_space_02.png", { 342, -408 });

	std::shared_ptr<ContentActor> Space3 = CreateActor<ContentActor>();
	Space3->SpriteInit("kd_gb_space_03.png", { 400, -456 });

	std::shared_ptr<ContentActor> Space4 = CreateActor<ContentActor>();
	Space4->SpriteInit("kd_gb_space_04.png", { 533, -517 });

	std::shared_ptr<ContentActor> Space5 = CreateActor<ContentActor>();
	Space5->SpriteInit("kd_gb_space_05.png", { 607, -530 });

	std::shared_ptr<ContentActor> Space6 = CreateActor<ContentActor>();
	Space6->SpriteInit("kd_gb_space_06.png", { 678, -535 });

	std::shared_ptr<ContentActor> Space7 = CreateActor<ContentActor>();
	Space7->SpriteInit("kd_gb_space_07.png", { 819, -511 });

	std::shared_ptr<ContentActor> Space8 = CreateActor<ContentActor>();
	Space8->SpriteInit("kd_gb_space_08.png", { 882, -487 });

	std::shared_ptr<ContentActor> Space9 = CreateActor<ContentActor>();
	Space9->SpriteInit("kd_gb_space_09.png", { 940, -450 });

	std::shared_ptr<ContentActor> SpaceStartOver = CreateActor<ContentActor>();
	SpaceStartOver->SpriteInit("kd_gb_space_start_over.png", { 1025, -353 });

	std::shared_ptr<ContentActor> SpaceFinish = CreateActor<ContentActor>();
	SpaceFinish->SpriteInit("kd_gb_space_fin.png", { 1055, -295 });

	std::shared_ptr<ContentActor> SpaceFinishComplete = CreateActor<ContentActor>();
	SpaceFinishComplete->SpriteInit("kd_gb_space_fin_complete.png", { 1055, -295 });
	SpaceFinishComplete->Off();
}