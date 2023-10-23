#include "PreCompile.h"
#include "HitFX.h"

HitFX::HitFX()
{
}

HitFX::~HitFX()
{
}


void HitFX::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Dash_Dust"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Cuphead\\Hit\\Cuphead_HitFX");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();
	MainRenderer->CreateAnimation("Cuphead_Hit_FXa", "Cuphead_Hit_FXa", 0.07f, false);
	MainRenderer->SetEndEvent("Cuphead_Hit_FXa", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->Off();
		});
	MainRenderer->CreateAnimation("Cuphead_Hit_FXb", "Cuphead_Hit_FXb", 0.07f, false);
	MainRenderer->SetEndEvent("Cuphead_Hit_FXb", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->Off();
		});
	MainRenderer->CreateAnimation("Cuphead_Hit_FXc", "Cuphead_Hit_FXc", 0.07f, false);
	MainRenderer->SetEndEvent("Cuphead_Hit_FXc", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->Off();
		});
	MainRenderer->AutoSpriteSizeOn();

	RandomFX();
}

void HitFX::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	EndCheck();
}

void HitFX::RandomFX()
{
	std::string AnimationName = "Cuphead_Hit_FX";

	GameEngineRandom NewRandom;
	int Random = NewRandom.RandomInt(1, 3);
	NewRandom.SetSeed(Random);

	switch (Random)
	{
	case 1:
		AnimationName += "a";
		break;
	case 2:
		AnimationName += "b";
		break;
	case 3:
		AnimationName += "c";
	default:
		break;
	}

	MainRenderer->ChangeAnimation(AnimationName);
}

void HitFX::EndCheck()
{
	if (true == MainRenderer->IsCurAnimationEnd())
	{
		Death();
	}
}