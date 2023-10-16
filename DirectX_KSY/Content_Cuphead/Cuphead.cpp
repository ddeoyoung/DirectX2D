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
	MainRenderer->CreateAnimation("Cuphead_Run_Shoot",		"Run_Shoot_Straight", 0.05f);
	MainRenderer->CreateAnimation("Cuphead_Run_Shoot_Diagonal_Up",	"Run_Shoot_Diagonal_Up", 0.05f);

	// Aim
	MainRenderer->CreateAnimation("Cuphead_Aim_Straight",		"Aim_Straight");
	MainRenderer->CreateAnimation("Cuphead_Aim_Up",				"Aim_Up");
	MainRenderer->CreateAnimation("Cuphead_Aim_Down",			"Aim_Down");
	MainRenderer->CreateAnimation("Cuphead_Aim_Diagonal_Up",	"Aim_Diagonal_Up");
	MainRenderer->CreateAnimation("Cuphead_Aim_Diagonal_Down",	"Aim_Diagonal_Down");

	// Shoot
	MainRenderer->CreateAnimation("Cuphead_Shoot_Straight",		"Shoot_Straight", 0.05f);
	MainRenderer->CreateAnimation("Cuphead_Shoot_Up",			"Shoot_Up", 0.05f);
	MainRenderer->CreateAnimation("Cuphead_Shoot_Down",			"Shoot_Down", 0.05f);
	MainRenderer->CreateAnimation("Cuphead_Shoot_Diagonal_Up",	"Shoot_Diagonal_Up", 0.05f);
	MainRenderer->CreateAnimation("Cuphead_Shoot_Diagonal_Down","Shoot_Diagonal_Down", 0.05f);

	// Intro
	MainRenderer->CreateAnimation("Cuphead_Intro_Type_A", "Intro_Type_A", 0.05f);
	MainRenderer->CreateAnimation("Cuphead_Intro_Type_B", "Intro_Type_B", 0.04f);

	// Duck
	MainRenderer->CreateAnimation("Cuphead_Duck",		"Duck");
	MainRenderer->CreateAnimation("Cuphead_Duck_Idle",	"Duck_Idle");
	MainRenderer->CreateAnimation("Cuphead_Duck_Shoot", "Duck_Shoot");

	// Dash
	MainRenderer->CreateAnimation("Cuphead_Dash_Ground",	"Dash_Ground", 0.04f);
	MainRenderer->CreateAnimation("Cuphead_Dash_Air",		"Dash_Air", 0.04f);

	// Jump
	MainRenderer->CreateAnimation("Cuphead_Jump", "Jump", 0.04f);

	// Fall
	MainRenderer->CreateAnimation("Cuphead_Fall", "Fall", 0.04f);

	// Hit
	MainRenderer->CreateAnimation("Cuphead_Hit_Ground", "Cuphead_Hit_Ground", 0.05f, false);
	MainRenderer->CreateAnimation("Cuphead_Hit_Air", "Cuphead_Hit_Air", 0.05f, false);

	// Parry
	MainRenderer->CreateAnimation("Cuphead_Parry", "Cuphead_Parry", 0.05f, false);
	MainRenderer->CreateAnimation("Cuphead_Parry_Pink", "Cuphead_Parry_Pink", 0.05f, false);

	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);


	// Create Collision
	PlayerCollision = CreateComponent<GameEngineCollision>(CollisionOrder::Player);
	PlayerCollision->SetCollisionType(ColType::AABBBOX2D);
	PlayerCollision->Transform.SetLocalScale({ 80, 100 });
	PlayerCollision->Transform.SetLocalPosition({ 0, 70 });
	PlayerCollision->Off();

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
	if (_StateName == "Run" || _StateName == "Run_Shoot")
	{
		if (true == IsRunShoot && _StateName == "Run_Shoot")
		{
			switch (AttDir)
			{
			case AttackDir::Left_Diagonal_Up:
			case AttackDir::Right_Diagonal_Up:
				AnimationName += "_Diagonal_Up";
				break;
			case AttackDir::Left_Straight:
			case AttackDir::Right_Straight:
				//AnimationName += "_Straight";
				break;
			default:
				break;
			}
		}

		else
		{
			AnimationName += "_Normal";
		}
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
	// Shoot
	if (_StateName == "Aim" || _StateName == "Shoot")
	{
		switch (AttDir)
		{
		case AttackDir::None:
			AnimationName += "_Straight"; // ±âº»°ª
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

	// Hit
	if (_StateName == "Hit")
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

	CurState = _StateName;

	MainRenderer->ChangeAnimation(AnimationName);
}