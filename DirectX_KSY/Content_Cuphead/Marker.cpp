#include "PreCompile.h"
#include "Marker.h"
#include "Dice.h"
#include "KingDice.h"

Marker::Marker()
{
}

Marker::~Marker()
{
}

void Marker::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Marker_Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\KingDice\\StageObject\\Marker");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();
	MainRenderer->CreateAnimation("Marker_Idle", "Marker_Idle");
	MainRenderer->CreateAnimation("Marker_Spin", "Marker_Spin", 0.05f);
	MainRenderer->AutoSpriteSizeOn();

	Transform.SetLocalPosition({ 220, -300 });

	ChangeState(MarkerState::Idle);
}

void Marker::Update(float _Delta)
{
	ContentActor::Update(_Delta);
	StateUpdate(_Delta);
}

void Marker::ChangeState(MarkerState _State)
{
	if (_State != State)
	{
		switch (_State)
		{
		case MarkerState::None:
			break;
		case MarkerState::Idle:
			IdleStart();
			break;
		case MarkerState::Spin:
			SpinStart();
			break;
		default:
			break;
		}
	}

	State = _State;
}

void Marker::StateUpdate(float _Delta)
{
	switch (State)
	{
	case MarkerState::None:
		break;
	case MarkerState::Idle:
		return IdleUpdate(_Delta);
	case MarkerState::Spin:
		return SpinUpdate(_Delta);
	default:
		break;
	}
}

void Marker::ChangeAnimationState(const std::string& _StateName)
{
	std::string AnimationName = "Marker_";
	AnimationName += _StateName;

	CurState = _StateName;
	MainRenderer->ChangeAnimation(AnimationName);
}

void Marker::IdleStart()
{
	ChangeAnimationState("Idle");
}

void Marker::IdleUpdate(float _Delta)
{
	// Dice Hit Check
	if (true == Dice::IsHit)
	{
		ChangeState(MarkerState::Spin);
		return;
	}
}

void Marker::SpinStart()
{
	ChangeAnimationState("Spin");
	SpinCount = Dice::DiceCount;
}

void Marker::SpinUpdate(float _Delta)
{
	switch (SpinCount)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
}