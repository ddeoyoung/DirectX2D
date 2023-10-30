#include "PreCompile.h"
#include "Attack_FireBullet.h"
#include "MrWheezy.h"

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
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::Play);
	MainRenderer->CreateAnimation("Cigar_FireBullet", "Cigar_FireBullet", 0.05f);
	MainRenderer->ChangeAnimation("Cigar_FireBullet");
	MainRenderer->AutoSpriteSizeOn();
	

	//TrailRenderer = CreateComponent<GameEngineSpriteRenderer>();
	//TrailRenderer->CreateAnimation("FireBullet_Trail", "FireBullet_Trail"/*, 0.08f, -1, -1, false*/);
	//TrailRenderer->SetEndEvent("FireBullet_Trail", [](GameEngineSpriteRenderer* _Renderer)
	//	{
	//		_Renderer->Off();
	//	});
	//TrailRenderer->ChangeAnimation("FireBullet_Trail");
	//TrailRenderer->AutoSpriteSizeOn();


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

	MoveUpdate(_Delta);
	EndCheck(_Delta);
}

void Attack_FireBullet::MoveUpdate(float _Delta)
{
	Pos += float4::LEFT * (float)AttDir * _Delta * 200.0f;
	Dis += 100.0f * _Delta;
	Angle += 360.0f * _Delta;
	Arm = float4::GetUnitVectorFromDeg(Angle);

	if (120.0f <= Dis)
	{
		Dis = 120.0f;
	}

	Transform.SetLocalPosition(Pos + (Arm * Dis));
}

void Attack_FireBullet::EndCheck(float _Delta)
{
	LiveTime -= _Delta;
	if (LiveTime < 0.0f)
	{
		Death();
	}
}