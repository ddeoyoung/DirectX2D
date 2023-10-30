#include "PreCompile.h"
#include "PipandDotLevel.h"

void PipandDotLevel::LevelStartTextureLoad()
{
	// Pixel Background
	if (nullptr == GameEngineSprite::Find("kd_domino_bg_white_pixel.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\PipandDot\\StageObject\\Background");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_domino_bg_white_pixel.png");
		GameEngineSprite::CreateSingle("kd_domino_bg_white_pixel.png");
	}


	// Frontground - Domino
	if (nullptr == GameEngineSprite::Find("kd_domino_fg_domino_001.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\PipandDot\\StageObject\\Frontground");

		// 1
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_domino_fg_domino_001.png");
		GameEngineSprite::CreateSingle("kd_domino_fg_domino_001.png");

		// 2
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_domino_fg_domino_002.png");
		GameEngineSprite::CreateSingle("kd_domino_fg_domino_002.png");

		// 3
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_domino_fg_domino_003.png");
		GameEngineSprite::CreateSingle("kd_domino_fg_domino_003.png");

		// 4
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_domino_fg_domino_004.png");
		GameEngineSprite::CreateSingle("kd_domino_fg_domino_004.png");

		// 5
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_domino_fg_domino_005.png");
		GameEngineSprite::CreateSingle("kd_domino_fg_domino_005.png");
	}

	// Frontground - Gear, Wheel
	if (nullptr == GameEngineSprite::Find("kd_domino_fg_domino_001.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\PipandDot\\StageObject\\Frontground");

		// Gear Big
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_domino_fg_gear_big.png");
		GameEngineSprite::CreateSingle("kd_domino_fg_gear_big.png");

		// Gear Mid
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_domino_fg_gear_med.png");
		GameEngineSprite::CreateSingle("kd_domino_fg_gear_med.png");

		// Gear Small
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_domino_fg_gear_small.png");
		GameEngineSprite::CreateSingle("kd_domino_fg_gear_small.png");

		// Wheel
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_domino_fg_wheel.png");
		GameEngineSprite::CreateSingle("kd_domino_fg_wheel.png");
	}

	// Blend
	if (nullptr == GameEngineSprite::Find("kd_domino_vignette.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\PipandDot\\StageObject\\Frontground");

		// Vignette
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_domino_vignette.png");
		GameEngineSprite::CreateSingle("kd_domino_vignette.png");
	}
}

void PipandDotLevel::LevelStartTextureSet()
{

}