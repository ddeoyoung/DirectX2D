#include "PreCompile.h"
#include "OverWorldCharacter.h"

OverWorldCharacter::OverWorldCharacter()
{
}

OverWorldCharacter::~OverWorldCharacter()
{
}

void OverWorldCharacter::Start()
{
	ContentActor::Start();


	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("OverWorld_Cuphead_Idle"))
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
	MainRenderer->CreateAnimation("OverWorld_Cuphead_Idle_Right", "OverWorld_Cuphead_Idle_Right", 0.05f);
	MainRenderer->CreateAnimation("OverWorld_Cuphead_Idle_Up", "OverWorld_Cuphead_Idle_Up", 0.05f);
	MainRenderer->CreateAnimation("OverWorld_Cuphead_Idle_Down", "OverWorld_Cuphead_Idle_Down", 0.05f);
	MainRenderer->CreateAnimation("OverWorld_Cuphead_Idle_Diagonal_Up", "OverWorld_Cuphead_Idle_Diagonal_Up", 0.05f);
	MainRenderer->CreateAnimation("OverWorld_Cuphead_Idle_Diagonal_Down", "OverWorld_Cuphead_Idle_Diagonal_Down", 0.05f);

	// Walk
	MainRenderer->CreateAnimation("OverWorld_Cuphead_Walk_Right", "OverWorld_Cuphead_Walk_Right", 0.05f);
	MainRenderer->CreateAnimation("OverWorld_Cuphead_Walk_Up", "OverWorld_Cuphead_Walk_Up", 0.05f);
	MainRenderer->CreateAnimation("OverWorld_Cuphead_Walk_Down", "OverWorld_Cuphead_Walk_Down", 0.05f);
	MainRenderer->CreateAnimation("OverWorld_Cuphead_Walk_Diagonal_Up", "OverWorld_Cuphead_Walk_Diagonal_Up", 0.05f);
	MainRenderer->CreateAnimation("OverWorld_Cuphead_Walk_Diagonal_Down", "OverWorld_Cuphead_Walk_Diagonal_Down", 0.05f);

	MainRenderer->ChangeAnimation("OverWorld_Cuphead_Idle_Right");
	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);


	ChangeState(OverWorldCharacterState::Idle);
}

void OverWorldCharacter::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	StateUpdate(_Delta);
}

void OverWorldCharacter::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentActor::LevelStart(_PrevLevel);
}

void OverWorldCharacter::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentActor::LevelEnd(_NextLevel);
}

void OverWorldCharacter::ChangeState(OverWorldCharacterState _State)
{
	if (_State != State)
	{
		switch (_State)
		{
		case OverWorldCharacterState::None:
			break;
		case OverWorldCharacterState::Idle:
			IdleStart();
			break;
		case OverWorldCharacterState::Walk:
			WalkStart();
			break;
		case OverWorldCharacterState::Win:
			WinStart();
			break;
		default:
			break;
		}
	}

	State = _State;
}

void OverWorldCharacter::StateUpdate(float _Delta)
{
	switch (State)
	{
	case OverWorldCharacterState::None:
		break;
	case OverWorldCharacterState::Idle:
		IdleUpdate(_Delta);
	case OverWorldCharacterState::Walk:
		WalkUpdate(_Delta);
	case OverWorldCharacterState::Win:
		WinUpdate(_Delta);
	default:
		break;
	}
}

void OverWorldCharacter::ChangeAnimationState(const std::string& _StateName)
{
	std::string AnimationName = "OverWorld_Cuphead_";
	AnimationName += _StateName;

	CurState = _StateName;
	MainRenderer->ChangeAnimation(AnimationName);
}

void OverWorldCharacter::DirCheck()
{

}