#include "PreCompile.h"
#include "TutorialLevel.h"

#include "ContentBackground.h"
#include "BaseCharacter.h"
#include "Cuphead.h"

#include "Sphere.h"
#include "Target.h"
#include "PortalDoor.h"
#include "FadeAnimation.h"

TutorialLevel::TutorialLevel()
{
}

TutorialLevel::~TutorialLevel()
{
}

void TutorialLevel::Start()
{
	ContentLevel::Start();

	// Sprite Load
	if (nullptr == GameEngineSprite::Find("TutorialMap.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Tutorial");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\TutorialMap.png");
		GameEngineSprite::CreateSingle("TutorialMap.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\TutorialBitMap.png");
		GameEngineSprite::CreateSingle("TutorialBitMap.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\tutorial_room_front_layer_0001.png");
		GameEngineSprite::CreateSingle("tutorial_room_front_layer_0001.png");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\tutorial_room_back_layer_0001.png");
		GameEngineSprite::CreateSingle("tutorial_room_back_layer_0001.png");
	}

	// Back Layer
	BackLayer = CreateActor<ContentBackground>();
	BackLayer->BackgroundInit("tutorial_room_back_layer_0001.png");

	// Background
	CurLevelBackground = CreateActor<ContentBackground>();
	CurLevelBackground->BackgroundInit("TutorialMap.png");

	CurLevelPixelBackground = CreateActor<ContentBackground>();
	CurLevelPixelBackground->PixelBackgroundInit("TutorialBitMap.png");

	// Target
	TargetObject = CreateActor<Target>();
	TargetObject->Transform.SetLocalPosition({ 3564, -240});

	// Sphere
	Sphere1 = CreateActor<Sphere>();
	Sphere1->Transform.SetLocalPosition({ 3891, -317 });

	Sphere2 = CreateActor<Sphere>();
	Sphere2->Transform.SetLocalPosition({ 4093, -317 });

	Sphere3 = CreateActor<Sphere>();
	Sphere3->Transform.SetLocalPosition({ 4293, -317 });

	// Front Layer
	FrontLayer = CreateActor<ContentBackground>();
	FrontLayer->BackgroundInit("tutorial_room_front_layer_0001.png");

	// Player
	CurLevelPlayer = CreateActor<Cuphead>();
	CurLevelPlayer->Transform.SetLocalPosition({ 250, -550 });

	// Exit Door
	if (nullptr == ExitDoor)
	{
		ExitDoor = CreateActor<PortalDoor>();
	}
	ExitDoor->Transform.SetLocalPosition({ 6642, -468 });
	ExitDoor->SetPortalValue(PortalValue::OverWorld);

	// Fade
	if (nullptr == Fade)
	{
		Fade = CreateActor<FadeAnimation>();
	}
	Fade->Transform.SetLocalPosition({ 5620, 0 });
	Fade->Off();
}

void TutorialLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);

	SetLayerPos();

	bool PortalCheck = ExitDoor->GetIsPortalOn();
	if (false == IsLevelChange)
	{
		if (true == PortalCheck)
		{
			Fade->On();
			Fade->SetFade("Out");
			IsLevelChange = true;
		}
	}

	else if (true == IsLevelChange)
	{
		if (true == Fade->IsCurAnimationEnd())
		{
			ExitDoor->LevelChange();
		}
	}
}

void TutorialLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentLevel::LevelStart(_PrevLevel);
}

void TutorialLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}

void TutorialLevel::SetLayerPos()
{
	// BackLayer, FrontLayer -> Camera 따라가야함
	float4 CameraPos = GetMainCamera()->Transform.GetLocalPosition();
	float4 WindowScaleHalf = GameEngineCore::MainWindow.GetScale().Half();
	float4 LayerPos = { CameraPos.X - WindowScaleHalf.X, CameraPos.Y + WindowScaleHalf.Y };

	BackLayer->Transform.SetLocalPosition(LayerPos);
	FrontLayer->Transform.SetLocalPosition(LayerPos);
}