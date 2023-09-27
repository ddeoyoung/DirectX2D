#include "PreCompile.h"
#include "TipsyTroopLevel.h"

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

	// Background
	if (nullptr == GameEngineSprite::Find("kingdice_alcohol_bg_backdrop.png"))
	{
		// Far Background (Drop)
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\TipsyTroop\\StageObject");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_backdrop.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_backdrop.png");

		// Ground Background (Table)
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_Ground_Table.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_Ground_Table.png");

		// Pixel Background
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kingdice_alcohol_bg_Ground_Table_pixel.png");
		GameEngineSprite::CreateSingle("kingdice_alcohol_bg_Ground_Table_pixel.png");
	}
}

void TipsyTroopLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}