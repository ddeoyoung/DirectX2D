#include "PreCompile.h"
#include "Attack_Spew.h"

Attack_Spew::Attack_Spew()
{
}

Attack_Spew::~Attack_Spew()
{
}

void Attack_Spew::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Rum_Attack_Spew"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\TipsyTroop\\Boss\\Rum\\Rum_Attack");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();
	MainRenderer->CreateAnimation("Rum_Attack_Spew", "Rum_Attack_Spew", 0.07f, false);
	MainRenderer->SetEndEvent("Rum_Attack_Spew", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->Off();
		});
	MainRenderer->ChangeAnimation("Rum_Attack_Spew");
	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::RightBottom);

	// Create Collision
	AttackCollision = CreateComponent<GameEngineCollision>(CollisionOrder::BossAttack);
	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("Rum_Attack_Spew");
	float4 Scale = Texture->GetSpriteData(0).GetScale();
	Scale -= { 100.0f, 130.0f };
	AttackCollision->SetCollisionType(ColType::AABBBOX2D);
	AttackCollision->Transform.SetLocalScale(Scale);
	AttackCollision->Transform.AddLocalPosition({ -250 , 80});
}

void Attack_Spew::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	EndCheck();
}

void Attack_Spew::EndCheck()
{
	if (true == MainRenderer->IsCurAnimationEnd())
	{
		Death();
	}
}