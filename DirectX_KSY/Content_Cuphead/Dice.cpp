#include "PreCompile.h"
#include "Dice.h"

Dice::Dice()
{
}

Dice::~Dice()
{
}

void Dice::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Dice_Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\KingDice\\AttackObject\\KingDice_Dice");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();
	MainRenderer->CreateAnimation("Dice_Idle", "Dice_Idle", 0.05f);
	MainRenderer->CreateAnimation("Dice_Hit_One", "Dice_Hit_One");
	MainRenderer->CreateAnimation("Dice_Hit_Two", "Dice_Hit_Two");
	MainRenderer->CreateAnimation("Dice_Hit_Three", "Dice_Hit_Three");
	MainRenderer->CreateAnimation("Dice_Death", "Dice_Death");
	MainRenderer->CreateAnimation("Dice_Death_One", "Dice_Death_One");
	MainRenderer->CreateAnimation("Dice_Death_Two", "Dice_Death_Two");
	MainRenderer->CreateAnimation("Dice_Death_Three", "Dice_Death_Three");
	MainRenderer->AutoSpriteSizeOn();


	// Create Parry Collision
	ParryCollision = CreateComponent<GameEngineCollision>(CollisionOrder::ParryObject);
	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("Dice_Idle");
	float4 Scale = Texture->GetSpriteData(0).GetScale();
	ParryCollision->SetCollisionType(ColType::AABBBOX2D);
	ParryCollision->Transform.SetLocalScale(Scale);


	ChangeState(DiceState::Idle);
}

void Dice::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	StateUpdate(_Delta);
}

void Dice::ChangeState(DiceState _State)
{
	if (_State != State)
	{
		switch (_State)
		{
		case DiceState::None:
			break;
		case DiceState::Idle:
			IdleStart();
			break;
		case DiceState::HitOne:
			HitOneStart();
			break;
		case DiceState::HitTwo:
			HitTwoStart();
			break;
		case DiceState::HitThree:
			HitThreeStart();
			break;
		case DiceState::Death:
			DeathStart();
			break;
		default:
			break;
		}
	}

	State = _State;
}

void Dice::StateUpdate(float _Delta)
{
	switch (State)
	{
	case DiceState::None:
		break;
	case DiceState::Idle:
		return IdleUpdate(_Delta);
	case DiceState::HitOne:
		return HitOneUpdate(_Delta);
	case DiceState::HitTwo:
		return HitTwoUpdate(_Delta);
	case DiceState::HitThree:
		return HitThreeUpdate(_Delta);
	case DiceState::Death:
		return DeathUpdate(_Delta);
	default:
		break;
	}
}

void Dice::ChangeAnimationState(const std::string& _StateName)
{
	std::string AnimationName = "Dice_";
	AnimationName += _StateName;

	CurState = _StateName;
	MainRenderer->ChangeAnimation(AnimationName); 
}

void Dice::IdleStart()
{
	ChangeAnimationState("Idle");
	IdleTimer = 0.0f;
}

void Dice::IdleUpdate(float _Delta)
{
	IdleTimer += _Delta;
	if (IdleTimer > 1.2f)
	{
		IdleTimer = 0.0f;
	}

	// Player Parry
	IsHit = ParryCollision->Collision(CollisionOrder::Player);

	if (true == IsHit && true == GameEngineInput::IsPress('Z', this))
	{
		// 2
		if (IdleTimer > 0.0f && IdleTimer <= 0.4f)
		{
			ChangeState(DiceState::HitTwo);
			return;
		}
		// 3
		else if (IdleTimer > 0.4f && IdleTimer <= 0.8f)
		{
			ChangeState(DiceState::HitThree);
			return;
		}
		// 1
		else if (IdleTimer > 0.8f && IdleTimer <= 1.2f)
		{
			ChangeState(DiceState::HitOne);
			return;
		}

		IsHit = false;
	}
}

void Dice::HitOneStart()
{
	ChangeAnimationState("Hit_One");
}

void Dice::HitOneUpdate(float _Delta)
{

}

void Dice::HitTwoStart()
{
	ChangeAnimationState("Hit_Two");
}

void Dice::HitTwoUpdate(float _Delta)
{

}

void Dice::HitThreeStart()
{
	ChangeAnimationState("Hit_Three");
}

void Dice::HitThreeUpdate(float _Delta)
{

}

void Dice::DeathStart()
{
	ChangeAnimationState("Death");
}
void Dice::DeathUpdate(float _Delta)
{

}