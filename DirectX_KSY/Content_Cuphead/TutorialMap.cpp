#include "PreCompile.h"
#include "TutorialMap.h"

TutorialMap* TutorialMap::TutorialBack;

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

GameEngineColor TutorialMap::GetColor(float4 _Pos, GameEngineColor _DefaultColor)
{
	_Pos.Y *= -1.0f;

	std::shared_ptr<GameEngineTexture> Texture = GameEngineTexture::Find("TutorialBitMap.png");

	return Texture->GetColor(_Pos, _DefaultColor);
}