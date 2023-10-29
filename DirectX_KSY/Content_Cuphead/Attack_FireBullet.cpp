#include "PreCompile.h"
#include "Attack_FireBullet.h"

Attack_FireBullet::Attack_FireBullet()
{
}

Attack_FireBullet::~Attack_FireBullet()
{
}


void Attack_FireBullet::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Cigar_FireBullet"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\MrWheezy\\AttackObejct");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();
	MainRenderer->CreateAnimation("Cigar_FireBullet", "Cigar_FireBullet", -1, -1, false);
	MainRenderer->SetEndEvent("Cigar_FireBullet", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->Off();
		});
	MainRenderer->ChangeAnimation("Cigar_FireBullet");
	MainRenderer->AutoSpriteSizeOn();


	// Create Collision
	AttackCollision = CreateComponent<GameEngineCollision>(CollisionOrder::BossAttack);
	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("Cigar_FireBullet");
	float4 Scale = Texture->GetSpriteData(0).GetScale();
	Scale -= { 40.0f, 40.0f };
	AttackCollision->SetCollisionType(ColType::AABBBOX2D);
	AttackCollision->Transform.SetLocalScale(Scale);
}

void Attack_FireBullet::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}
