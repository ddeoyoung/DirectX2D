#include "PreCompile.h"
#include "OverWorldLevel.h"

#include "OverWorldCharacter.h"
#include "OverWorldFlag.h"
#include "FadeAnimation.h"

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

	// Flag To Inkwell Three
	FlagToThree = CreateActor<OverWorldFlag>();
	FlagToThree->Transform.SetLocalPosition({ 2200, -3450 });
	FlagToThree->SetPortalValue(PortalValue::Inkwell_Three);

	// Flag To Inkwell One
	FlagToOne = CreateActor<OverWorldFlag>();
	FlagToOne->Transform.SetLocalPosition({ 9000, -1150 });
	FlagToOne->SetPortalValue(PortalValue::Inkwell_One);

	// Portal To Inkwell Hell
	PortalToHell = CreateActor<Portal>();
	PortalToHell->Transform.SetLocalPosition({ 9660, -630 });
	PortalToHell->SetPortalValue(PortalValue::Inkwell_Hell);
	PortalToHell->GetRenderer()->Off();

	// Player
	if (nullptr == OverWorldPlayer)
	{
		OverWorldPlayer = CreateActor<OverWorldCharacter>();
		OverWorldPlayer->Transform.SetLocalPosition({ 860, -3400 });
	}
	if (LastPlayerPos != float4::ZERO)
	{
		OverWorldPlayer->Transform.SetLocalPosition(LastPlayerPos);
	}

	float4 PlayerPos = OverWorldPlayer->Transform.GetLocalPosition();
	GetMainCamera()->Transform.SetLocalPosition(PlayerPos);
	float4 WindowScale = GameEngineCore::MainWindow.GetScale();
	float4 FadePos = { PlayerPos.X - WindowScale.ihX(), PlayerPos.Y + WindowScale.ihY() };

	// Fade In
	FadeIn->Transform.SetLocalPosition(FadePos);

	// Fade Out
	FadeOut = CreateActor<FadeAnimation>();
	FadeOut->SetFade("Out");
	FadeOut->Off();
}

void OverWorldLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);

	if (true == FlagToThree->GetIsPortalOn())
	{
		OverWorldPlayer->Transform.SetLocalPosition({ 9040, -1200 });
	}

	if (true == FlagToOne->GetIsPortalOn())
	{
		OverWorldPlayer->Transform.SetLocalPosition({ 2200, -3450 });
	}

	if (true == PortalToHell->GetIsPortalOn())
	{
		FadeOut->On();
		//float4 PlayerPos = OverWorldPlayer->Transform.GetLocalPosition();
		//float4 WindowScale = GameEngineCore::MainWindow.GetScale();
		//float4 FadePos = { PlayerPos.X - WindowScale.ihX(), PlayerPos.Y + WindowScale.ihY() };

		float4 WindowScale = GameEngineCore::MainWindow.GetScale();
		float4 CameraPos = GetMainCamera()->Transform.GetLocalPosition();
		float4 FadePos = { CameraPos.X - WindowScale.ihX(), CameraPos.Y + WindowScale.ihY() };
		FadeOut->Transform.SetLocalPosition(FadePos);

		LastPlayerPos = OverWorldPlayer->Transform.GetLocalPosition();
	}

	if (true == FadeOut->IsCurAnimationEnd())
	{
		IsHell = true;
	}

	if (true == IsHell)
	{
		IsHell = false;
		PortalToHell->SetIsPortalOn(false);
		GameEngineCore::ChangeLevel("InkwellHellLevel");
	}
}

void OverWorldLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}