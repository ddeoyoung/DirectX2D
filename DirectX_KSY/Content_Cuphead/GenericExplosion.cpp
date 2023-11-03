#include "PreCompile.h"
#include "GenericExplosion.h"

GenericExplosion::GenericExplosion()
{
}

GenericExplosion::~GenericExplosion()
{
}


void GenericExplosion::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("GenericExplosion_A"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Effect\\GenericExplosion");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::PlayEffect);
	MainRenderer->CreateAnimation("GenericExplosion_A", "GenericExplosion_A", 0.05f, -1, -1, false);
	MainRenderer->CreateAnimation("GenericExplosion_B", "GenericExplosion_B", 0.05f, -1, -1, false);
	MainRenderer->ChangeAnimation("GenericExplosion_A");
	MainRenderer->AutoSpriteSizeOn();

	SetRandom();
}

void GenericExplosion::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	EndCheck();
}

void GenericExplosion::EndCheck()
{
	if (true == MainRenderer->IsCurAnimationEnd())
	{
		Death();
	}
}

void GenericExplosion::SetRandom()
{
	GameEngineRandom NewRandom;
	int Random = NewRandom.RandomInt(1, 2);
	NewRandom.SetSeed(Random);

	switch (Random)
	{
	case 1:
		MainRenderer->ChangeAnimation("GenericExplosion_A");
		break;
	case 2:
		MainRenderer->ChangeAnimation("GenericExplosion_B");
		break;
	default:
		break;
	}
}