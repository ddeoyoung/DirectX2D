#include "PreCompile.h"
#include "MrWheezy.h"

MrWheezy::MrWheezy()
{
}

MrWheezy::~MrWheezy()
{
}


void MrWheezy::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Chips_Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\ChipsBettigan\\Boss");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();

	MainRenderer->CreateAnimation("Chips_Intro", "Chips_Intro");
	MainRenderer->SetEndEvent("Chips_Intro", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Chips_Idle");
		});
	MainRenderer->CreateAnimation("Chips_Idle", "Chips_Idle", 0.05f);
	MainRenderer->CreateAnimation("Chips_Spin_Head", "Chips_Spin_Head");
	MainRenderer->CreateAnimation("Chips_Death_Fall", "Chips_Death_Fall");
	MainRenderer->SetEndEvent("Chips_Death_Fall", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Chips_Death_HeadCrash");
		});
	MainRenderer->CreateAnimation("Chips_Death_HeadCrash", "Chips_Death_HeadCrash", false);
	MainRenderer->SetEndEvent("Chips_Death_HeadCrash", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Chips_Death_Finish");
		});
	MainRenderer->CreateAnimation("Chips_Death_Finish", "Chips_Death_Finish");

	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);
	Transform.SetLocalPosition({ 1100 , -650 });

	ChangeState(WheezyState::Idle);

	// Create Collision
	BossCollision = CreateComponent<GameEngineCollision>(CollisionOrder::Boss);

	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("Chips_Idle");
	float4 Scale = Texture->GetSpriteData(0).GetScale();
	Scale -= { 80.0f, 60.0f };

	BossCollision->SetCollisionType(ColType::AABBBOX2D);
	BossCollision->Transform.SetLocalScale(Scale);
	BossCollision->Transform.SetLocalPosition({ 0, Scale.hY() });
}

void MrWheezy::Update(float _Delta)
{
	ContentActor::Start();

	StateUpdate(_Delta);
}

void MrWheezy::ChangeState(WheezyState _State)
{
	if (_State != State)
	{
		switch (_State)
		{
		case WheezyState::None:
			break;
		case WheezyState::Intro:
			IntroStart();
			break;
		case WheezyState::Idle:
			IdleStart();
			break;
		case WheezyState::Death:
			DeathStart();
			break;
		default:
			break;
		}
	}

	State = _State;
}

void MrWheezy::StateUpdate(float _Delta)
{
	switch (State)
	{
	case WheezyState::None:
		break;
	case WheezyState::Intro:
		return IntroUpdate(_Delta);
	case WheezyState::Idle:
		return IdleUpdate(_Delta);
	case WheezyState::Death:
		return DeathUpdate(_Delta);
	default:
		break;
	}
}

void MrWheezy::ChangeAnimationState(const std::string& _StateName)
{
	std::string AnimationName = "Weezy_";
	AnimationName += _StateName;


	CurState = _StateName;
	MainRenderer->ChangeAnimation(AnimationName);
}
