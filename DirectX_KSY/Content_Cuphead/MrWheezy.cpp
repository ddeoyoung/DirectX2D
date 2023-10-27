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
	if (nullptr == GameEngineSprite::Find("MrWheezy_Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\MrWheezy\\Boss");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::Play);
	MainRenderer->CreateAnimation("MrWheezy_Intro", "MrWheezy_Intro");
	MainRenderer->SetEndEvent("MrWheezy_Intro", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("MrWheezy_Idle");
		});
	MainRenderer->CreateAnimation("MrWheezy_Idle", "MrWheezy_Idle");
	MainRenderer->CreateAnimation("MrWheezy_Attack", "MrWheezy_Attack");
	MainRenderer->CreateAnimation("MrWheezy_Teleport1", "MrWheezy_Teleport1", 0.05f);
	MainRenderer->SetEndEvent("MrWheezy_Teleport1", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("MrWheezy_Teleport2");
		});
	MainRenderer->CreateAnimation("MrWheezy_Teleport2", "MrWheezy_Teleport2", 0.05f);
	MainRenderer->SetEndEvent("MrWheezy_Teleport2", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("MrWheezy_Teleport3");
		});
	MainRenderer->CreateAnimation("MrWheezy_Teleport3", "MrWheezy_Teleport3", 0.05f);
	MainRenderer->CreateAnimation("MrWheezy_Death_Intro", "MrWheezy_Death_Intro");
	MainRenderer->CreateAnimation("MrWheezy_Death_Loop", "MrWheezy_Death_Loop");

	MainRenderer->AutoSpriteSizeOn();
	Transform.SetLocalPosition({ 1050 , -250 });

	ChangeState(WheezyState::Intro);

	// Create Collision
	BossCollision = CreateComponent<GameEngineCollision>(CollisionOrder::Boss);
	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("MrWheezy_Idle");
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
		case WheezyState::Attack:
			AttackStart();
			break;
		case WheezyState::Teleport:
			TeleportStart();
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
	case WheezyState::Attack:
		return AttackUpdate(_Delta);
	case WheezyState::Teleport:
		return TeleportUpdate(_Delta);
	case WheezyState::Death:
		return DeathUpdate(_Delta);
	default:
		break;
	}
}

void MrWheezy::ChangeAnimationState(const std::string& _StateName)
{
	std::string AnimationName = "MrWheezy_";
	AnimationName += _StateName;

	if (_StateName == "Teleport")
	{
		AnimationName += "1";
	}

	CurState = _StateName;
	MainRenderer->ChangeAnimation(AnimationName);
}
