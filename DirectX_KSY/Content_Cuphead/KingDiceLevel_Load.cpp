#include "PreCompile.h"
#include "KingDiceLevel.h"

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
}