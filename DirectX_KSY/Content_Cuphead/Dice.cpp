#include "PreCompile.h"
#include "Dice.h"

Dice::Dice()
{
}

Dice::~Dice()
{
}

void Dice::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Dice_Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\KingDice\\AttackObject\\KingDice_Dice");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();

	MainRenderer->CreateAnimation("Dice_Idle", "Dice_Idle");
	MainRenderer->CreateAnimation("Dice_One", "Dice_One");
	MainRenderer->CreateAnimation("Dice_Two", "Dice_Two");
	MainRenderer->CreateAnimation("Dice_Three", "Dice_Three");
	MainRenderer->CreateAnimation("Dice_Death", "Dice_Death");
	MainRenderer->CreateAnimation("Dice_Death_One", "Dice_Death_One");
	MainRenderer->CreateAnimation("Dice_Death_Two", "Dice_Death_Two");
	MainRenderer->CreateAnimation("Dice_Death_Three", "Dice_Death_Three");

	MainRenderer->ChangeAnimation("Dice_Idle");
	MainRenderer->AutoSpriteSizeOn();


	// Parry Collision
	ParryCollision = CreateComponent<GameEngineCollision>(CollisionOrder::Parry);

	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("Dice_Idle");
	float4 Scale = Texture->GetSpriteData(0).GetScale();

	ParryCollision->SetCollisionType(ColType::AABBBOX2D);
	ParryCollision->Transform.SetLocalScale(Scale);
}

void Dice::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}

