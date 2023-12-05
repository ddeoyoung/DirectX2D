#include "PreCompile.h"
#include "OverWorldLevel.h"

#include "OverWorldCharacter.h"
#include "OverWorldFlag.h"
#include "FadeAnimation.h"
#include "OverWorldHouse.h"
#include "EnterMessage.h"

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
	if (nullptr == CurLevelBackground)
	{
		CurLevelBackground = CreateActor<ContentBackground>();
		CurLevelBackground->BackgroundInit("IslandFinal.png");

		CurLevelPixelBackground = CreateActor<ContentBackground>();
		CurLevelPixelBackground->PixelBackgroundInit("IslandFinal_pixel.png");
		//CurLevelPixelBackground->GetRenderer()->On();

		// Background Upper
		CurLevelUpperBackground = CreateActor<ContentBackground>();
		CurLevelUpperBackground->UpperBackgroundInit("IslandFinal_Upper.png");
	}
	
	// Flag To Inkwell Three
	if (nullptr == FlagToThree)
	{
		FlagToThree = CreateActor<OverWorldFlag>();
		FlagToThree->Transform.SetLocalPosition({ 2200, -3450 });
		FlagToThree->SetPortalValue(PortalValue::Inkwell_Three);
	}

	// Flag To Inkwell One
	if (nullptr == FlagToOne)
	{
		FlagToOne = CreateActor<OverWorldFlag>();
		FlagToOne->Transform.SetLocalPosition({ 9000, -1150 });
		FlagToOne->SetPortalValue(PortalValue::Inkwell_One);
	}

	// Portal To Inkwell Hell
	if (nullptr == PortalToHell)
	{
		PortalToHell = CreateActor<Portal>();
		PortalToHell->Transform.SetLocalPosition({ 9660, -630 });
		PortalToHell->SetPortalValue(PortalValue::Inkwell_Hell);
		PortalToHell->GetRenderer()->Off();
	}

	// Portal To Elder Kettle House
	if (nullptr == TutorialHouse)
	{
		TutorialHouse = CreateActor<OverWorldHouse>();
		TutorialHouse->Transform.SetLocalPosition({ 820, -3240 });
		TutorialHouse->SetPortalValue(PortalValue::ElderKettleHouse);
	}

	// Enter Message
	if (nullptr == EnterBubbleToThree)
	{
		EnterBubbleToThree = CreateActor<EnterMessage>();
		EnterBubbleToThree->SetBubbleCollisionPos({0, -200});
		EnterBubbleToThree->Transform.SetLocalPosition({ 2200, -3350 });

	}

	if (nullptr == EnterBubbleToOne)
	{
		EnterBubbleToOne = CreateActor<EnterMessage>();
		EnterBubbleToOne->SetBubbleCollisionPos({ 0, -200 });
		EnterBubbleToOne->Transform.SetLocalPosition({ 9000, -1050 });
	}

	// Player
	if (nullptr == OverWorldPlayer)
	{
		OverWorldPlayer = CreateActor<OverWorldCharacter>();
		OverWorldPlayer->Transform.SetLocalPosition({ 860, -3400 });
	}
	OverWorldPlayer->SetIsCameraLerp(true);

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
	if (nullptr == FadeOut)
	{
		FadeOut = CreateActor<FadeAnimation>();
		FadeOut->SetFade("Out");
		FadeOut->Off();
	}
}

void OverWorldLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);
	CheckPortal();
	CheckLevelChange();

	EnterBubbleToThree->InteractionCheck();
	EnterBubbleToOne->InteractionCheck();
}

void OverWorldLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);

	// Background
	if (nullptr != CurLevelBackground)
	{
		CurLevelBackground = nullptr;
		CurLevelPixelBackground = nullptr;
		CurLevelUpperBackground = nullptr;
	}

	// Flag To Inkwell Three
	if (nullptr != FlagToThree)
	{
		FlagToThree = nullptr;
	}

	// Flag To Inkwell One
	if (nullptr != FlagToOne)
	{
		FlagToOne = nullptr;
	}

	// Portal To Inkwell Hell
	if (nullptr != PortalToHell)
	{
		PortalToHell = nullptr;
	}

	// Portal To Elder Kettle House
	if (nullptr != TutorialHouse)
	{
		TutorialHouse = nullptr;
	}

	// Enter Message
	if (nullptr != EnterBubbleToThree)
	{
		EnterBubbleToThree = nullptr;
	}

	if (nullptr != EnterBubbleToOne)
	{
		EnterBubbleToOne = nullptr;
	}

	// Fade Out
	if (nullptr != FadeOut)
	{
		FadeOut->Death();
		FadeOut = nullptr;
	}
}

void OverWorldLevel::CheckPortal()
{
	// Flag
	if (true == FlagToThree->GetIsPortalOn())
	{
		OverWorldPlayer->Transform.SetLocalPosition({ 9040, -1200 });
	}

	if (true == FlagToOne->GetIsPortalOn())
	{
		OverWorldPlayer->Transform.SetLocalPosition({ 2200, -3450 });
	}

	// Inkwell Hell
	if (true == PortalToHell->GetIsPortalOn()
		|| true == TutorialHouse->GetIsPortalOn())
	{
		OverWorldPlayer->SetIsCameraLerp(false);
		FadeOut->On();
		float4 WindowScale = GameEngineCore::MainWindow.GetScale();
		float4 CameraPos = GetMainCamera()->Transform.GetLocalPosition();
		float4 FadePos = { CameraPos.X - WindowScale.ihX(), CameraPos.Y + WindowScale.ihY() };
		FadeOut->Transform.SetLocalPosition(FadePos);
		LastPlayerPos = OverWorldPlayer->Transform.GetLocalPosition();
	}
}

void OverWorldLevel::CheckLevelChange()
{
	// Check FadeOut End
	if (true == FadeOut->IsCurAnimationEnd())
	{
		if (true == PortalToHell->GetIsCollision())
		{
			IsHell = true;
		}

		else if (true == TutorialHouse->GetIsCollision())
		{
			IsHouse = true;
		}
	}

	// Level Change
	if (true == IsHell)
	{
		IsHell = false;
		PortalToHell->SetIsPortalOn(false);
		GameEngineCore::ChangeLevel("InkwellHellLevel");
	}

	if (true == IsHouse)
	{
		IsHouse = false;
		TutorialHouse->SetIsPortalOn(false);
		GameEngineCore::ChangeLevel("ElderKettleLevel");
	}
}