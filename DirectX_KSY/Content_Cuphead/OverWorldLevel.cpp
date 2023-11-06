#include "PreCompile.h"
#include "OverWorldLevel.h"

#include "OverWorldCharacter.h"
#include "OverWorldFlag.h"

OverWorldLevel::OverWorldLevel()
{
}

OverWorldLevel::~OverWorldLevel()
{
}

void OverWorldLevel::Start()
{
	ContentLevel::Start();

	// Sprite Load
	if (nullptr == GameEngineSprite::Find("IslandFinal.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\OverWorld\\OverWorldMap");

		// Background
		GameEngineTexture::Load(Dir.GetStringPath() + "\\IslandFinal.png");
		GameEngineSprite::CreateSingle("IslandFinal.png");

		// Pixel Background
		GameEngineTexture::Load(Dir.GetStringPath() + "\\IslandFinal_pixel.png");
		GameEngineSprite::CreateSingle("IslandFinal_pixel.png");

		// Background Upper
		GameEngineTexture::Load(Dir.GetStringPath() + "\\IslandFinal_Upper.png");
		GameEngineSprite::CreateSingle("IslandFinal_Upper.png");
	}
}


void OverWorldLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentLevel::LevelStart(_PrevLevel);
	GetMainCamera()->SetYSort(RenderOrder::Play);

	// Background
	CurLevelBackground = CreateActor<ContentBackground>();
	CurLevelBackground->BackgroundInit("IslandFinal.png");

	CurLevelPixelBackground = CreateActor<ContentBackground>();
	CurLevelPixelBackground->PixelBackgroundInit("IslandFinal_pixel.png");
	//CurLevelPixelBackground->GetRenderer()->On();

	// Background Upper
	CurLevelUpperBackground = CreateActor<ContentBackground>();
	CurLevelUpperBackground->UpperBackgroundInit("IslandFinal_Upper.png");

	// Flag To Inkwell Hell
	FlagToHell = CreateActor<OverWorldFlag>();
	FlagToHell->Transform.SetLocalPosition({ 2200, -3450 });
	FlagToHell->SetPortalValue(PortalValue::Inkwell_Hell);

	// Flag To House (Inkwell Island 1)
	FlagToHouse = CreateActor<OverWorldFlag>();
	FlagToHouse->Transform.SetLocalPosition({ 9000, -1150 });
	FlagToHouse->SetPortalValue(PortalValue::Inkwell_One);

	// Portal To  

	// Player
	OverWorldPlayer = CreateActor<OverWorldCharacter>();
	OverWorldPlayer->Transform.SetLocalPosition({ 860, -3400 });

	float4 PlayerPos = OverWorldPlayer->Transform.GetLocalPosition();
	GetMainCamera()->Transform.SetLocalPosition(PlayerPos);
	float4 WindowScale = GameEngineCore::MainWindow.GetScale();
	float4 FadePos = { PlayerPos.X - WindowScale.ihX(), PlayerPos.Y + WindowScale.ihY() };

	// Fade In
	FadeIn->Transform.SetLocalPosition(FadePos);
}

void OverWorldLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);

	if (true == FlagToHell->GetIsPortalOn())
	{
		OverWorldPlayer->Transform.SetLocalPosition({ 9040, -1200 });
	}

	if (true == FlagToHouse->GetIsPortalOn())
	{
		OverWorldPlayer->Transform.SetLocalPosition({ 2200, -3450 });
	}
}

void OverWorldLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}