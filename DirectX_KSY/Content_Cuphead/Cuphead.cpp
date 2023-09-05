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
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();
	MainRenderer->CreateAnimation("Cuphead_Idle", "Idle");
	MainRenderer->CreateAnimation("Cuphead_Run_Normal", "Normal");
	MainRenderer->CreateAnimation("Cuphead_Run_Shoot", "Shoot");
	MainRenderer->CreateAnimation("Cuphead_Intro", "Type_A", 0.05f);

	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->Transform.SetLocalPosition({ 250, -550 });

	ChangeState(CharacterState::Intro);
}

void Cuphead::ChangeAnimationState(const std::string& _StateName)
{
	std::string AnimationName = "Cuphead_";
	AnimationName += _StateName;

	if (_StateName == "Run")
	{
		AnimationName += "_Normal";
	}

	CurState = _StateName;

	MainRenderer->ChangeAnimation(AnimationName);
}