#include "PreCompile.h"
#include "Attack_Liquid.h"

Attack_Liquid::Attack_Liquid()
{
}

Attack_Liquid::~Attack_Liquid()
{
}

void Attack_Liquid::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Scotch_Attack_Liquid"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\TipsyTroop\\Boss\\Scotch\\Scotch_Attack");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();
	MainRenderer->CreateAnimation("Scotch_Attack_Liquid", "Scotch_Attack_Liquid", 0.07f, false);
	MainRenderer->ChangeAnimation("Scotch_Attack_Liquid");
	MainRenderer->AutoSpriteSizeOn();
}

void Attack_Liquid::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	EndCheck();
}

void Attack_Liquid::EndCheck()
{
	if (true == MainRenderer->IsCurAnimationEnd())
	{
		Death();
	}
}