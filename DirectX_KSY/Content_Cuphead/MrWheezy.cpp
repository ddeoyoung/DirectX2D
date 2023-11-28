#include "PreCompile.h"
#include "MrWheezy.h"
#include "Attack_FireBullet.h"
#include "Attack_CiggyDemon.h"
#include "BossExplosion.h"

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

	// Create Animation - King Dice
	KingDiceRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::Frontground);
	KingDiceRenderer->CreateAnimation("MrWheezy_Intro_Hand", "MrWheezy_Intro_Hand", 0.07f, -1, -1, false);
	KingDiceRenderer->SetEndEvent("MrWheezy_Intro_Hand", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->Off();
		});
	KingDiceRenderer->ChangeAnimation("MrWheezy_Intro_Hand");
	KingDiceRenderer->AutoSpriteSizeOn();

	FireRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::Frontground);
	FireRenderer->CreateAnimation("MrWheezy_Intro_Hand_Flame", "MrWheezy_Intro_Hand_Flame", 0.07f, -1, -1, false);
	FireRenderer->SetEndEvent("MrWheezy_Intro_Hand_Flame", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->Off();
		});
	FireRenderer->ChangeAnimation("MrWheezy_Intro_Hand_Flame");
	FireRenderer->AutoSpriteSizeOn();

	// Create Animation - Boss
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::Play);
	MainRenderer->CreateAnimation("MrWheezy_Intro", "MrWheezy_Intro", 0.07f, -1, -1, false);
	MainRenderer->SetEndEvent("MrWheezy_Intro", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("MrWheezy_Idle");
			_Renderer->GetParent<MrWheezy>()->SetState(WheezyState::Idle);
		});
	MainRenderer->CreateAnimation("MrWheezy_Idle", "MrWheezy_Idle", 0.05f);
	MainRenderer->CreateAnimation("MrWheezy_Attack", "MrWheezy_Attack", 0.08f);
	MainRenderer->CreateAnimation("MrWheezy_Teleport1", "MrWheezy_Teleport1", 0.05f, -1, -1, false);
	MainRenderer->SetEndEvent("MrWheezy_Teleport1", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("MrWheezy_Teleport2");
		});
	MainRenderer->CreateAnimation("MrWheezy_Teleport2", "MrWheezy_Teleport2", 0.05f, -1, -1, false);
	MainRenderer->SetEndEvent("MrWheezy_Teleport2", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("MrWheezy_Teleport3");
		});
	MainRenderer->CreateAnimation("MrWheezy_Teleport3", "MrWheezy_Teleport3", 0.05f, -1, -1, false);
	MainRenderer->CreateAnimation("MrWheezy_Death_Intro", "MrWheezy_Death_Intro", -1, -1, false);
	MainRenderer->SetEndEvent("MrWheezy_Death_Intro", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("MrWheezy_Death_Loop");
		});
	MainRenderer->CreateAnimation("MrWheezy_Death_Loop", "MrWheezy_Death_Loop");

	MainRenderer->AutoSpriteSizeOn();
	Transform.SetLocalPosition({ 1050 , -250 });

	KingDiceRenderer->Transform.SetLocalPosition({ -300, 300 });
	KingDiceRenderer->SetPivotType(PivotType::Top);
	FireRenderer->Transform.SetLocalPosition({ -80, 160 });

	// Test
	MainRenderer->CreateAnimation("MrWheezy_Appear1", "MrWheezy_Teleport3", 0.05f, 15, 0, false);
	MainRenderer->SetEndEvent("MrWheezy_Appear1", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("MrWheezy_Appear2");
		});
	MainRenderer->CreateAnimation("MrWheezy_Appear2", "MrWheezy_Teleport2", 0.05f, 16, 0, false);
	MainRenderer->SetEndEvent("MrWheezy_Appear2", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("MrWheezy_Appear3");
		});
	MainRenderer->CreateAnimation("MrWheezy_Appear3", "MrWheezy_Teleport1", 0.05f, 7, 0, false);


	// Create Collision
	BossCollision = CreateComponent<GameEngineCollision>(CollisionOrder::Boss);
	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("MrWheezy_Idle");
	float4 Scale = Texture->GetSpriteData(0).GetScale();
	Scale -= { 80.0f, 60.0f };
	BossCollision->SetCollisionType(ColType::AABBBOX2D);
	BossCollision->Transform.SetLocalScale(Scale);
	BossCollision->Transform.SetLocalPosition({ 0, 0 });

	ChangeState(WheezyState::Intro);
	HP = 30;
}

void MrWheezy::Update(float _Delta)
{
	ContentActor::Start();
	StateUpdate(_Delta);
	CreateCiggyDemon(_Delta);
	DeathCheck();
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
		case WheezyState::Appear:
			AppearStart();
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
	case WheezyState::Appear:
		return AppearUpdate(_Delta);
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

	if (_StateName == "Teleport" || _StateName == "Appear")
	{
		AnimationName += "1";
	}

	if (_StateName == "Death")
	{
		AnimationName += "_Intro";
	}

	CurState = _StateName;
	MainRenderer->ChangeAnimation(AnimationName);
	MainRenderer->Transform.SetLocalScale({ Dir * 1.0f, 1.0f });
}

void MrWheezy::ReverseDir()
{
	Dir *= (-1);
}

void MrWheezy::CreateCiggyDemon(float _Delta)
{
	CiggyDemonInter -= _Delta;
	if (CiggyDemonInter < 0.0f)
	{
		std::shared_ptr<Attack_CiggyDemon> CiggyDemon = GetLevel()->CreateActor<Attack_CiggyDemon>();
		CiggyDemonInter = 3.0f;
	}
}

void MrWheezy::CreateFireBullet()
{
	std::shared_ptr<Attack_FireBullet> FireBullet = GetLevel()->CreateActor<Attack_FireBullet>();
	FireBullet->SetAttDir(Dir);

	float4 BossPos = Transform.GetLocalPosition();
	BossPos.Y -= 140.0f;

	switch (Dir)
	{
	case 1:
		BossPos.X -= 200.0f;
		break;
	case -1:
		BossPos.X += 200.0f;
		break;
	default:
		break;
	}

	FireBullet->Transform.SetLocalPosition(BossPos);
	FireBullet->SetPos(BossPos);
}

void MrWheezy::DeathCheck()
{
	if (false == IsDeath)
	{
		return;
	}

	ChangeState(WheezyState::Death);
}

void MrWheezy::CreateDeathEffect()
{
	std::shared_ptr<BossExplosion> DeathEffect = GetLevel()->CreateActor<BossExplosion>();
	float4 BossPos = Transform.GetLocalPosition();
	DeathEffect->SetPos(BossPos);
}