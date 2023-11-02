#include "PreCompile.h"
#include "MusicNote.h"

MusicNote::MusicNote()
{
}

MusicNote::~MusicNote()
{
}



void MusicNote::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("MusicNote"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\ElderKettle");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();
	MainRenderer->CreateAnimation("MusicNote_One", "MusicNote_One", 0.05f);
	MainRenderer->CreateAnimation("MusicNote_Two", "MusicNote_Two", 0.05f);
	MainRenderer->AutoSpriteSizeOn();


	SetRandomNote();
}

void MusicNote::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	if (true == MainRenderer->IsCurAnimationEnd())
	{
		SetRandomNote();
	}
}

void MusicNote::SetRandomNote()
{
	GameEngineRandom NewRandom;
	int Random = NewRandom.RandomInt(1, 2);
	NewRandom.SetSeed(Random);

	switch (Random)
	{
	case 1:
		MainRenderer->ChangeAnimation("MusicNote_One");
		break;
	case 2:
		MainRenderer->ChangeAnimation("MusicNote_Two");
		break;
	default:
		break;
	}
}