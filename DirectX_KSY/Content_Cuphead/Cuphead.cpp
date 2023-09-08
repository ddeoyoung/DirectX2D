#include "PreCompile.h"
#include "Cuphead.h"

Cuphead::Cuphead()
{
}

Cuphead::~Cuphead()
{
}

void Cuphead::Start()
{
	BaseCharacter::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Cuphead");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::Play);
	MainRenderer->CreateAnimation("Cuphead_Idle", "Idle");
	MainRenderer->CreateAnimation("Cuphead_Run_Normal", "Normal");
	MainRenderer->CreateAnimation("Cuphead_Run_Shoot", "Shoot");
	MainRenderer->CreateAnimation("Cuphead_Intro_Type_A", "Intro_Type_A", 0.05f);
	MainRenderer->CreateAnimation("Cuphead_Intro_Type_B", "Intro_Type_B", 0.04f);
	MainRenderer->CreateAnimation("Cuphead_Duck", "Duck");
	MainRenderer->CreateAnimation("Cuphead_Duck_Idle", "Duck_Idle");
	MainRenderer->CreateAnimation("Cuphead_Duck_Shoot", "Duck_Shoot");
	MainRenderer->CreateAnimation("Cuphead_Dash_Ground", "Dash_Ground", 0.05f);
	MainRenderer->CreateAnimation("Cuphead_Dash_Air", "Dash_Air", 0.05f);
	MainRenderer->CreateAnimation("Cuphead_Jump", "Jump"/*, 0.03f*/);


	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);

	ChangeState(CharacterState::Intro);
}

void Cuphead::ChangeAnimationState(const std::string& _StateName)
{
	std::string AnimationName = "Cuphead_";
	AnimationName += _StateName;


	// Intro
	GameEngineRandom NewRandom;
	int Random = NewRandom.RandomInt(1, 2);
	NewRandom.SetSeed(Random);

	if (_StateName == "Intro")
	{
		switch (Random)
		{
		case 1:
			AnimationName += "_Type_A";
			break;
		case 2:
			AnimationName += "_Type_B";
			break;
		default:
			break;
		}
	}

	// Run
	if (_StateName == "Run")
	{
		AnimationName += "_Normal";

		switch (Dir)
		{
		case ActorDir::Left:
			break;
		case ActorDir::Right:
			break;
		case ActorDir::Up:
			break;
		case ActorDir::Down:
			break;
		default:
			break;
		}
	}

	// Dash
	if (_StateName == "Dash")
	{
		AnimationName += "_Ground";
	}

	CurState = _StateName;

	MainRenderer->ChangeAnimation(AnimationName);
}