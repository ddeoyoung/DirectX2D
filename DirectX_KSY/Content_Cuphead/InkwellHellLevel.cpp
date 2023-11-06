#include "PreCompile.h"
#include "InkwellHellLevel.h"

#include "OverWorldLevel.h"
#include "Portal.h"
#include "OverWorldCharacter.h"

InkwellHellLevel::InkwellHellLevel()
{
}

InkwellHellLevel::~InkwellHellLevel()
{
}

void InkwellHellLevel::Start()
{
	ContentLevel::Start();

	// Sprite Load
	if (nullptr == GameEngineSprite::Find("InkwellHell.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\OverWorld\\OverWorldMap\\Inkwell_Hell");

		// Background
		GameEngineTexture::Load(Dir.GetStringPath() + "\\InkwellHell.png");
		GameEngineSprite::CreateSingle("InkwellHell.png");

		// Pixel Background
		GameEngineTexture::Load(Dir.GetStringPath() + "\\InkwellHell_pixel.png");
		GameEngineSprite::CreateSingle("InkwellHell_pixel.png");

		// Background Upper
		GameEngineTexture::Load(Dir.GetStringPath() + "\\InkwellHell_Upper.png");
		GameEngineSprite::CreateSingle("InkwellHell_Upper.png");
	}
}


void InkwellHellLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentLevel::LevelStart(_PrevLevel);

	// Background
	CurLevelBackground = CreateActor<ContentBackground>();
	CurLevelBackground->BackgroundInit("InkwellHell.png");

	CurLevelPixelBackground = CreateActor<ContentBackground>();
	CurLevelPixelBackground->PixelBackgroundInit("InkwellHell_pixel.png");
	//CurLevelPixelBackground->GetRenderer()->On();

	// Background Upper
	CurLevelUpperBackground = CreateActor<ContentBackground>();
	CurLevelUpperBackground->UpperBackgroundInit("InkwellHell_Upper.png");

	// Entrance To Inkwell Isle
	PortalToInkwell = CreateActor<Portal>();
	PortalToInkwell->Transform.SetLocalPosition({ 630, -1700 });
	PortalToInkwell->SetPortalValue(PortalValue::Inkwell_Hell);

	// Entrance To Boss Stage
	PortalToBossStage = CreateActor<Portal>();
	PortalToBossStage->Transform.SetLocalPosition({ 1400, -913 });
	PortalToBossStage->SetPortalValue(PortalValue::Inkwell_Hell);

	// Player
	OverWorldPlayer->Transform.SetLocalPosition({ 630, -1700 });

	float4 PlayerPos = OverWorldPlayer->Transform.GetLocalPosition();
	GetMainCamera()->Transform.SetLocalPosition(PlayerPos);
	float4 WindowScale = GameEngineCore::MainWindow.GetScale();
	float4 FadePos = { PlayerPos.X - WindowScale.ihX(), PlayerPos.Y + WindowScale.ihY() };

	// Fade In
	FadeIn->Transform.SetLocalPosition(FadePos);
}

void InkwellHellLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);
}

void InkwellHellLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}