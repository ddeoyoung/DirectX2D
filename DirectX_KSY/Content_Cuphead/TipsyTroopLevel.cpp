#include "PreCompile.h"
#include "TipsyTroopLevel.h"

#include "BaseCharacter.h"
#include "Cuphead.h"

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
	Table4->SpriteInit("kingdice_alcohol_bg_table4.png", { 550, -250 });

	std::shared_ptr<ContentActor> Table3 = CreateActor<ContentActor>();
	Table3->SpriteInit("kingdice_alcohol_bg_table3.png", { 350, -380 });

	std::shared_ptr<ContentActor> Table2 = CreateActor<ContentActor>();
	Table2->SpriteInit("kingdice_alcohol_bg_table2.png", { 1000, -450 });

	std::shared_ptr<ContentActor> Table1 = CreateActor<ContentActor>();
	Table1->SpriteInit("kingdice_alcohol_bg_table1.png", { 300, -500 });



	// Ground Background
	CurLevelBackground = CreateActor<ContentBackground>();
	CurLevelBackground->BackgroundInit("kingdice_alcohol_bg_Ground_Table.png", { -80, -480 });

	// Pixel Background
	CurLevelPixelBackground = CreateActor<ContentBackground>();
	CurLevelPixelBackground->PixelBackgroundInit("kingdice_alcohol_bg_Ground_Table_pixel.png");

	// Player
	Player = CreateActor<Cuphead>();
	Player->Transform.SetLocalPosition({ 250, -550 });

}

void TipsyTroopLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}