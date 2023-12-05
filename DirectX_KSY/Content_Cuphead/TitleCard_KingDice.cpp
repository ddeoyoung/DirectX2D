#include "PreCompile.h"
#include "TitleCard_KingDice.h"

TitleCard_KingDice::TitleCard_KingDice()
{
}

TitleCard_KingDice::~TitleCard_KingDice()
{
}


void TitleCard_KingDice::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("TitleCard_KingDice.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\UI\\TitleCard");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\TitleCard_KingDice.png");
		GameEngineSprite::CreateSingle("TitleCard_KingDice.png");
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::UI);
	MainRenderer->SetSprite("TitleCard_KingDice.png");
	MainRenderer->Transform.SetLocalPosition({ 640, -360 });
}

void TitleCard_KingDice::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	float PopSpeed = 3.0f;
	float4 StartScale = { 0.1f, 0.1f, 1.0f};
	float4 CardScale = { 1.0f, 1.0f, 1.0f};

	CardScaleRatio += _Delta;
	float4 PopScale = float4::LerpClamp(StartScale, CardScale, PopSpeed * CardScaleRatio);
	
	MainRenderer->Transform.SetLocalScale(PopScale);
}