#include "PreCompile.h"
#include "Attack_Chips.h"

Attack_Chips::Attack_Chips()
{
}

Attack_Chips::~Attack_Chips()
{
}

void Attack_Chips::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("CigSmoke"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\ChipsBettigan\\Boss");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();

	MainRenderer->CreateAnimation("Chips_Spin_Middle", "Chips_Spin_Middle");
	MainRenderer->CreateAnimation("Chips_Spin_Bottom", "Chips_Spin_Bottom");

	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);
}

void Attack_Chips::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}

void Attack_Chips::SetChips(float4 _BossPos, const std::string& _ChipType)
{
	float4 ChipPos = _BossPos;
	std::string ChipType = "Chips_Spin_" + _ChipType;

	// Animation
	MainRenderer->Transform.SetLocalPosition(ChipPos);
	MainRenderer->ChangeAnimation(ChipType);

	// Collision
	AttackCollision = CreateComponent<GameEngineCollision>(CollisionOrder::Boss);

	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("Chips_Spin_Middle");
	float4 Scale = Texture->GetSpriteData(0).GetScale();
	ChipPos.Y += Scale.ihY();

	AttackCollision->SetCollisionType(ColType::AABBBOX2D);
	AttackCollision->Transform.SetLocalScale(Scale);
	AttackCollision->Transform.SetLocalPosition(ChipPos);
	AttackCollision->Off();
}