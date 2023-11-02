#include "PreCompile.h"
#include "Attack_Card.h"
#include "KingDice.h"

Attack_Card::Attack_Card()
{
}

Attack_Card::~Attack_Card()
{
}


void Attack_Card::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Cigar_CiggyDemon"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\KingDice\\AttackObject\\KingDice_Card");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::BackgroundEffect);
	MainRenderer->CreateAnimation("Card_Club_Start", "Card_Club_Start", 0.05f, -1, -1, false);
	MainRenderer->SetEndEvent("Card_Club_Start", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Card_Club");
		});
	MainRenderer->CreateAnimation("Card_Diamond_Start", "Card_Diamond_Start", 0.05f, -1, -1, false);
	MainRenderer->SetEndEvent("Card_Diamond_Start", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Card_Diamond");
		});
	MainRenderer->CreateAnimation("Card_Heart_Start", "Card_Heart_Start", 0.05f, -1, -1, false);
	MainRenderer->SetEndEvent("Card_Heart_Start", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Card_Heart");
		});
	MainRenderer->CreateAnimation("Card_Spade_Start", "Card_Spade_Start", 0.05f, -1, -1, false);
	MainRenderer->SetEndEvent("Card_Spade_Start", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Card_Spade");
		});

	MainRenderer->CreateAnimation("Card_Club", "Card_Club", 0.05f);
	MainRenderer->CreateAnimation("Card_Diamond", "Card_Diamond", 0.05f);
	MainRenderer->CreateAnimation("Card_Heart", "Card_Heart", 0.05f);
	MainRenderer->CreateAnimation("Card_Spade", "Card_Spade", 0.05f);
	MainRenderer->ChangeAnimation("Card_Club_Start");
	MainRenderer->AutoSpriteSizeOn();





}

void Attack_Card::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	if (nullptr == AttackCollision)
	{
		SetCollisionType();
	}

	MoveUpdate(_Delta);
}

void Attack_Card::SetCardAttDir(int _AttDir)
{
	Dir = _AttDir;
}

void Attack_Card::SetCardType(CardType _CardType)
{
	switch (_CardType)
	{
	case CardType::None:
		break;
	case CardType::Club:
		MainRenderer->ChangeAnimation("Card_Club_Start");
		break;
	case CardType::Diamond:
		MainRenderer->ChangeAnimation("Card_Diamond_Start");
		break;
	case CardType::Heart:
		MainRenderer->ChangeAnimation("Card_Heart_Start");
		break;
	case CardType::Spade:
		MainRenderer->ChangeAnimation("Card_Spade_Start");
		break;
	default:
		break;
	}

	CurCardType = _CardType;
}

void Attack_Card::MoveUpdate(float _Delta)
{
	float4 MovePos = Dir * _Delta * 300.0f;
	Transform.AddLocalPosition(MovePos);
}

void Attack_Card::SetCollisionType()
{
	// Create Collision
	if (CurCardType == CardType::Heart)
	{
		AttackCollision = CreateComponent<GameEngineCollision>(CollisionOrder::ParryObject);
	}

	else
	{
		AttackCollision = CreateComponent<GameEngineCollision>(CollisionOrder::BossAttack);
	}

	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("Card_Club");
	float4 Scale = Texture->GetSpriteData(0).GetScale();
	Scale -= { 100.0f, 40.0f };
	AttackCollision->SetCollisionType(ColType::AABBBOX2D);
	AttackCollision->Transform.SetLocalScale(Scale);
}