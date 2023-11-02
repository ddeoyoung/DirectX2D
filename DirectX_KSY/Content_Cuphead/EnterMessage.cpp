#include "PreCompile.h"
#include "EnterMessage.h"

EnterMessage::EnterMessage()
{
}

EnterMessage::~EnterMessage()
{
}


void EnterMessage::Start()
{
	ContentActor::Start();

	// Sprite Load
	if (nullptr == GameEngineSprite::Find("EnterMessage.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\ElderKettle");

		// Enter Message
		GameEngineTexture::Load(Dir.GetStringPath() + "\\EnterMessage.png");
		GameEngineSprite::CreateSingle("EnterMessage.png");
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();
	MainRenderer->SetSprite("EnterMessage.png");
	MainRenderer->AutoSpriteSizeOn();
	Transform.SetLocalPosition({ 810, -370 });

	// Create Collision
	BubbleCollision = CreateComponent<GameEngineCollision>(CollisionOrder::Message);
	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("EnterMessage.png");
	float4 Scale = Texture->GetSpriteData(0).GetScale();
	BubbleCollision->SetCollisionType(ColType::AABBBOX2D);
	BubbleCollision->Transform.SetLocalScale(Scale);
	BubbleCollision->Transform.SetLocalPosition({ 0, -200 });
}

void EnterMessage::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}

bool EnterMessage::InteractionCheck()
{
	bool Check = BubbleCollision->Collision(CollisionOrder::Player);
	if (true == Check)
	{
		MainRenderer->On();
	}
	else if (false == Check)
	{
		MainRenderer->Off();
	}

	return Check;
}
