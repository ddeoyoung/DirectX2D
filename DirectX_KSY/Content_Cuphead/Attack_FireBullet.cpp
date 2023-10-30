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
	//TrailRenderer->CreateAnimation("FireBullet_Trail", "FireBullet_Trail", -1, -1, false);
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
}

void Attack_FireBullet::MoveUpdate(float _Delta)
{
	Pos += float4::LEFT * AttDir * _Delta * 100.0f;

	Dis += _Delta * 200.0f;

	if (300.0f <= Dis)
	{
		Dis = 300.0f;
	}

	Angle += _Delta * 360.0f;

	Arm = float4::GetUnitVectorFromDeg(Angle);

	Transform.SetLocalPosition(Pos + (Arm * Dis));

	// Transform.AddLocalPosition(Pos);
	float4 MovePos = float4::LEFT * AttDir * _Delta * 500.0f;
	// Transform.AddLocalPosition(MovePos);

	LiveTime -= _Delta;
	if (LiveTime < 0.0f)
	{
		Death();
	}
}