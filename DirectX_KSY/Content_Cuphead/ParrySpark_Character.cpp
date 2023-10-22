#include "PreCompile.h"
#include "ParrySpark_Character.h"

ParrySpark_Character::ParrySpark_Character()
{
}

ParrySpark_Character::~ParrySpark_Character()
{
}


void ParrySpark_Character::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Cuphead_Parry_Effect"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Cuphead\\Parry\\Cuphead_Parry_Effect");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::PlayEffect);
	MainRenderer->CreateAnimation("Cuphead_Parry_Effect", "Cuphead_Parry_Effect", 0.05f, false);
	MainRenderer->ChangeAnimation("Cuphead_Parry_Effect");
	MainRenderer->AutoSpriteSizeOn();

}

void ParrySpark_Character::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	EndCheck();
}

void ParrySpark_Character::EndCheck()
{
	if (true == MainRenderer->IsCurAnimationEnd())
	{
		Death();
	}
}