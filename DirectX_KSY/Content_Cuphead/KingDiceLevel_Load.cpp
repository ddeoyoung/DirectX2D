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

}