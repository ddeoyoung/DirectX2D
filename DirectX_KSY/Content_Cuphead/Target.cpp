#include "PreCompile.h"
#include "Target.h"

Target::Target()
{
}

Target::~Target()
{
}


void Target::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Tutorial_Target"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Tutorial");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		// Target
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}

		// Pytamid
		GameEngineTexture::Load(Dir.GetStringPath() + "\\tutorial_pyramid_topper.png");
		GameEngineSprite::CreateSingle("tutorial_pyramid_topper.png");
	}

	// Create Sprite
	TopperRenderer = CreateComponent<GameEngineSpriteRenderer>();
	TopperRenderer->SetSprite("tutorial_pyramid_topper.png");
	TopperRenderer->Transform.AddLocalPosition({ 0, -125 });

	// Create Animation
	TargetRenderer = CreateComponent<GameEngineSpriteRenderer>();
	TargetRenderer->CreateAnimation("Tutorial_Target", "Tutorial_Target");
	TargetRenderer->ChangeAnimation("Tutorial_Target");
	TargetRenderer->AutoSpriteSizeOn();
	//TargetRenderer->Transform.SetLocalPosition({ 0, 0 });

	// Create Collision
	TargetCollision = CreateComponent<GameEngineCollision>(CollisionOrder::ShootObject);
	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("Tutorial_Target");
	float4 Scale = Texture->GetSpriteData(0).GetScale();
	TargetCollision->SetCollisionType(ColType::AABBBOX2D);
	TargetCollision->Transform.SetLocalScale(Scale);
	TargetCollision->Transform.SetLocalPosition({ 0, 0 });
}

void Target::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}
