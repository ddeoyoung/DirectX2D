#include "PreCompile.h"
#include "ElderKettle.h"

ElderKettle::ElderKettle()
{
}

ElderKettle::~ElderKettle()
{
}


void ElderKettle::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("ElderKettle_Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\ElderKettle");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();
	MainRenderer->CreateAnimation("ElderKettle_Idle", "ElderKettle_Idle");
	MainRenderer->CreateAnimation("ElderKettle_PopOut_Start", "ElderKettle_PopOut_Start", 0.1f, -1, -1, false);
	MainRenderer->CreateAnimation("ElderKettle_PopOut_Loop", "ElderKettle_PopOut_Loop");
	MainRenderer->CreateAnimation("ElderKettle_PopOut_End", "ElderKettle_PopOut_End", 0.1f, -1, -1, false);
	MainRenderer->ChangeAnimation("ElderKettle_Idle");
	MainRenderer->AutoSpriteSizeOn();
	Transform.SetLocalPosition({ 1350, -520 });

	// Create Collision
	NPCCollision = CreateComponent<GameEngineCollision>(CollisionOrder::NPC);
	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("ElderKettle_Idle");
	float4 Scale = Texture->GetSpriteData(0).GetScale();
	Scale -= { 20, 20 };
	NPCCollision->SetCollisionType(ColType::AABBBOX2D);
	NPCCollision->Transform.SetLocalScale(Scale);
	NPCCollision->Transform.SetLocalPosition({ 0, 0 });

	ChangeState(ElderKettleState::Idle);
}

void ElderKettle::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	StateUpdate(_Delta);
}

void ElderKettle::ChangeState(ElderKettleState _State)
{
	if (State != _State)
	{
		switch (_State)
		{
		case ElderKettleState::None:
			break;
		case ElderKettleState::Idle:
			IdleStart();
			break;
		case ElderKettleState::PopOut:
			PopOutStart();
			break;
		default:
			break;
		}
	}

	State = _State;
}

void ElderKettle::StateUpdate(float _Delta)
{
	switch (State)
	{
	case ElderKettleState::None:
		break;
	case ElderKettleState::Idle:
		return IdleUpdate(_Delta);
	case ElderKettleState::PopOut:
		return PopOutUpdate(_Delta);
	default:
		break;
	}
}

void ElderKettle::ChangeAnimationState(const std::string& _StateName)
{
	std::string AnimationName = "ElderKettle_";
	AnimationName += _StateName;

	CurState = _StateName;
	MainRenderer->ChangeAnimation(AnimationName);
}

void ElderKettle::IdleStart()
{
	ChangeAnimationState("Idle");
}

void ElderKettle::IdleUpdate(float _Delta)
{

}

void ElderKettle::PopOutStart()
{
	ChangeAnimationState("PopOut");
}

void ElderKettle::PopOutUpdate(float _Delta)
{

}