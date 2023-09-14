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

	// Idle
	MainRenderer->CreateAnimation("Cuphead_Idle", "Idle");

	// Run
	MainRenderer->CreateAnimation("Cuphead_Run_Normal",		"Normal", 0.05f);
	MainRenderer->CreateAnimation("Cuphead_Run_Shoot",		"Shoot");

	// Aim
	MainRenderer->CreateAnimation("Cuphead_Aim_Straight",		"Aim_Straight");
	MainRenderer->CreateAnimation("Cuphead_Aim_Up",				"Aim_Up");
	MainRenderer->CreateAnimation("Cuphead_Aim_Down",			"Aim_Down");
	MainRenderer->CreateAnimation("Cuphead_Aim_Diagonal_Up",	"Aim_Diagonal_Up");
	MainRenderer->CreateAnimation("Cuphead_Aim_Diagonal_Down",	"Aim_Diagonal_Down");

	// Shoot
	MainRenderer->CreateAnimation("Cuphead_Shoot_Straight",		"Shoot_Straight");
	MainRenderer->CreateAnimation("Cuphead_Shoot_Up",			"Shoot_Up");
	MainRenderer->CreateAnimation("Cuphead_Shoot_Down",			"Shoot_Down");
	MainRenderer->CreateAnimation("Cuphead_Shoot_Diagonal_Up",	"Shoot_Diagonal_Up");
	MainRenderer->CreateAnimation("Cuphead_Shoot_Diagonal_Down","Shoot_Diagonal_Down");

	// Intro
	MainRenderer->CreateAnimation("Cuphead_Intro_Type_A", "Intro_Type_A", 0.05f);
	MainRenderer->CreateAnimation("Cuphead_Intro_Type_B", "Intro_Type_B", 0.04f);

	// Duck
	MainRenderer->CreateAnimation("Cuphead_Duck",		"Duck");
	MainRenderer->CreateAnimation("Cuphead_Duck_Idle",	"Duck_Idle");
	MainRenderer->CreateAnimation("Cuphead_Duck_Shoot", "Duck_Shoot");

	// Dash
	MainRenderer->CreateAnimation("Cuphead_Dash_Ground",	"Dash_Ground", 0.03f);
	MainRenderer->CreateAnimation("Cuphead_Dash_Air",		"Dash_Air", 0.03f);

	// Jump
	MainRenderer->CreateAnimation("Cuphead_Jump", "Jump", 0.06f);




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
	}

	// Dash
	if (_StateName == "Dash")
	{
		if (IsJump == false)
		{
			AnimationName += "_Ground";
		}

		else
		{
			AnimationName += "_Air";
		}
	}

	// Aim
	if (_StateName == "Aim")
	{
		AnimationName += "_Straight";
	}

	// Shoot
	if (_StateName == "Shoot")
	{
		switch (AttDir)
		{
		case AttackDir::None:
			break;
		case AttackDir::Left_Up:
			AnimationName += "_Up";
			break;
		case AttackDir::Left_Diagonal_Up:
			AnimationName += "_Diagonal_Up";
			break;
		case AttackDir::Left_Straight:
			AnimationName += "_Straight";
			break;
		case AttackDir::Left_Diagonal_Down:
			AnimationName += "_Diagonal_Down";
			break;
		case AttackDir::Left_Down:
			AnimationName += "_Down";
			break;
		case AttackDir::Right_Up:
			AnimationName += "_Up";
			break;
		case AttackDir::Right_Diagonal_Up:
			AnimationName += "_Diagonal_Up";
			break;
		case AttackDir::Right_Straight:
			AnimationName += "_Straight";
			break;
		case AttackDir::Right_Diagonal_Down:
			AnimationName += "_Diagonal_Down";
			break;
		case AttackDir::Right_Down:
			AnimationName += "_Down";
			break;
		default:
			break;
		}
	}

	CurState = _StateName;

	MainRenderer->ChangeAnimation(AnimationName);
}