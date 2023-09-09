#include "PreCompile.h"
#include "TutorialMap.h"

TutorialMap::TutorialMap()
{
}

TutorialMap::~TutorialMap()
{
}

void TutorialMap::Start()
{
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

	Renderer = CreateComponent<GameEngineSpriteRenderer>();
	Renderer->SetSprite("tutorial_room_back_layer_0001.png");

	Renderer = CreateComponent<GameEngineSpriteRenderer>();
	Renderer->SetSprite("TutorialBitMap.png");
	Renderer->Off();

	Renderer = CreateComponent<GameEngineSpriteRenderer>();
	Renderer->SetSprite("TutorialMap.png");

	Renderer = CreateComponent<GameEngineSpriteRenderer>();
	Renderer->SetSprite("tutorial_room_front_layer_0001.png");
}