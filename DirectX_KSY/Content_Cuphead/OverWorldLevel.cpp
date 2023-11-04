#include "PreCompile.h"
#include "OverWorldLevel.h"

#include "OverWorldCharacter.h"

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
	if (nullptr == GameEngineSprite::Find("Island1.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\OverWorld\\OverWorldMap");

		// Background
		GameEngineTexture::Load(Dir.GetStringPath() + "\\Island1.png");
		GameEngineSprite::CreateSingle("Island1.png");

		// Pixel Background
		GameEngineTexture::Load(Dir.GetStringPath() + "\\Island1_pixel.png");
		GameEngineSprite::CreateSingle("Island1_pixel.png");
	}
}

void OverWorldLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);
}

void OverWorldLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentLevel::LevelStart(_PrevLevel);

	// Background
	CurLevelBackground = CreateActor<ContentBackground>();
	CurLevelBackground->BackgroundInit("Island1.png");

	CurLevelPixelBackground = CreateActor<ContentBackground>();
	CurLevelPixelBackground->PixelBackgroundInit("Island1_pixel.png");
	//CurLevelPixelBackground->GetRenderer()->On();

	// Player
	OverWorldPlayer = CreateActor<OverWorldCharacter>();
	OverWorldPlayer->Transform.SetLocalPosition({ 800, -878 });

	float4 PlayerPos = OverWorldPlayer->Transform.GetLocalPosition();
	GetMainCamera()->Transform.SetLocalPosition(PlayerPos);
	float4 WindowScale = GameEngineCore::MainWindow.GetScale();
	float4 FadePos = { PlayerPos.X - WindowScale.ihX(), PlayerPos.Y + WindowScale.ihY()};

	// Fade In
	FadeIn->Transform.SetLocalPosition(FadePos);
}

void OverWorldLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}