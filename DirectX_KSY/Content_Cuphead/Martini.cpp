#include "PreCompile.h"
#include "Martini.h"

Martini::Martini()
{
}

Martini::~Martini()
{
}


void Martini::Start()
{
	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Martini_Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\TipsyTroop\\Boss\\Martini");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();
	
	MainRenderer->CreateAnimation("Martini_Idle", "Martini_Idle", 0.05f);
	MainRenderer->CreateAnimation("Martini_Attack", "Martini_Attack", 0.04f);
	MainRenderer->CreateAnimation("Martini_Death", "Martini_Death", 0.05f);
	MainRenderer->ChangeAnimation("Martini_Idle");

	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);

	Transform.SetLocalPosition({ 850 , -700 });


	// Create Collision
	BossCollision = CreateComponent<GameEngineCollision>(CollisionOrder::Boss);

	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("Martini_Idle");
	float4 Scale = Texture->GetSpriteData(0).GetScale();
	Scale -= { 60, 80 };

	BossCollision->SetCollisionType(ColType::AABBBOX2D);
	BossCollision->Transform.SetLocalScale(Scale);
	BossCollision->Transform.SetLocalPosition({ 0, Scale.hY() });
	BossCollision->Off();
}

void Martini::Update(float _Delta)
{
	StateUpdate(_Delta);
}

void Martini::ChangeState(MartiniState _State)
{
	int a = 0;

	if (State != _State)
	{
		switch (_State)
		{
		case MartiniState::None:
			break;
		case MartiniState::Idle:
			IdleStart();
			break;
		case MartiniState::Attack:
			AttackStart();
			break;
		case MartiniState::Death:
			DeathStart();
			break;
		default:
			break;
		}
	}

	State = _State;
}

void Martini::StateUpdate(float _Delta)
{
	switch (State)
	{
	case MartiniState::None:
		break;
	case MartiniState::Idle:
		return IdleUpdate(_Delta);
	case MartiniState::Attack:
		return AttackUpdate(_Delta);
	case MartiniState::Death:
		return DeathUpdate(_Delta);
	default:
		break;
	}
}

void Martini::ChangeAnimationState(const std::string& _StateName)
{
	std::string AnimationName = "Martini_";
	AnimationName += _StateName;

	CurState = _StateName;
	MainRenderer->ChangeAnimation(AnimationName);
}

void Martini::IdleStart()
{
	ChangeAnimationState("Idle");
}

void Martini::IdleUpdate(float _Delta)
{

}

void Martini::AttackStart()
{
	ChangeAnimationState("Attack");
}

void Martini::AttackUpdate(float _Delta)
{

}

void Martini::DeathStart()
{
	ChangeAnimationState("Death");
}

void Martini::DeathUpdate(float _Delta)
{

}