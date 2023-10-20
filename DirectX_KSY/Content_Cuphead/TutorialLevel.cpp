#include "PreCompile.h"
#include "TutorialLevel.h"

#include "ContentBackground.h"
#include "BaseCharacter.h"
#include "Cuphead.h"

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

	// Front Layer
	FrontLayer = CreateActor<ContentBackground>();
	FrontLayer->BackgroundInit("tutorial_room_front_layer_0001.png");

	// Player
	CurLevelPlayer = CreateActor<Cuphead>();
	CurLevelPlayer->Transform.SetLocalPosition({ 250, -550 });
}

void TutorialLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);

	SetLayerPos();
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