#include "PreCompile.h"
#include "BossExplosion.h"

BossExplosion::BossExplosion()
{
}

BossExplosion::~BossExplosion()
{
}


void BossExplosion::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("BossExplosion"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Effect");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::FrontgroundEffect);
	MainRenderer->CreateAnimation("BossExplosion", "BossExplosion", 0.05f);
	MainRenderer->ChangeAnimation("BossExplosion");
	MainRenderer->AutoSpriteSizeOn();

}

void BossExplosion::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}