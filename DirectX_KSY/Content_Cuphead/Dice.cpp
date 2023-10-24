#include "PreCompile.h"
#include "Dice.h"

Dice::Dice()
{
}

Dice::~Dice()
{
}

int Dice::DiceCount;
bool Dice::IsHit;

void Dice::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Dice_Idle"))
	{
		// Dice
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
	MainRenderer->CreateAnimation("Dice_Death_One", "Dice_Death_One");
	MainRenderer->SetEndEvent("Dice_Death_One", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Dice_Death");
		});
	MainRenderer->CreateAnimation("Dice_Death_Two", "Dice_Death_Two");
	MainRenderer->SetEndEvent("Dice_Death_Two", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Dice_Death");
		});
	MainRenderer->CreateAnimation("Dice_Death_Three", "Dice_Death_Three");
	MainRenderer->SetEndEvent("Dice_Death_Three", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Dice_Death");
		});
	MainRenderer->CreateAnimation("Dice_Death", "Dice_Death");
	MainRenderer->SetEndEvent("Dice_Death", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->Off();
			_Renderer->GetParent<Dice>()->Death();
		});
	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetOrder(RenderOrder::Play);

	// Create Parry Collision
	ParryCollision = CreateComponent<GameEngineCollision>(CollisionOrder::ParryObject);
	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("Dice_Idle");
	float4 Scale = Texture->GetSpriteData(0).GetScale();
	ParryCollision->SetCollisionType(ColType::AABBBOX2D);
	ParryCollision->Transform.SetLocalScale(Scale);

	//DiceCount = 0;
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
		case DiceState::Hit:
			HitStart();
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
	case DiceState::Hit:
		return HitUpdate(_Delta);
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

	if (_StateName == "Hit" || _StateName == "Death")
	{
		switch (DiceCount)
		{
		case 1:
			AnimationName += "_One";
			break;
		case 2:
			AnimationName += "_Two";
			break;
		case 3:
			AnimationName += "_Three";
			break;
		default:
			break;
		}
	}

	CurState = _StateName;
	MainRenderer->ChangeAnimation(AnimationName); 
}

void Dice::IdleStart()
{
	ChangeAnimationState("Idle");
	IdleTimer = 0.0f;
	DiceCount = 0;
	IsHit = false;
}

void Dice::IdleUpdate(float _Delta)
{
	IdleTimer += _Delta;
	if (IdleTimer > 1.2f && DiceCount == 0)
	{
		IdleTimer = 0.0f;
	}

	// Player Parry
	bool ParryCheck = ParryCollision->Collision(CollisionOrder::Player);

	if (true == ParryCheck && true == GameEngineInput::IsDown('Z', this))
	{
		if (IdleTimer <= 0.2f || IdleTimer > 1.0f)
		{
			DiceCount = 1;
		}

		else if (IdleTimer > 0.2f && IdleTimer <= 0.6f)
		{
			DiceCount = 2;
		}

		else if (IdleTimer > 0.6f && IdleTimer <= 1.0f)
		{
			DiceCount = 3;
		}

		IsHit = ParryCheck;
		ParryCollision->Death();
		ChangeState(DiceState::Hit);
		return;
	}
}

void Dice::HitStart()
{
	ChangeAnimationState("Hit");
	HitTimer = 1.5f;
}

void Dice::HitUpdate(float _Delta)
{
	HitTimer -= _Delta;
	if (HitTimer < 0.0f)
	{
		ChangeState(DiceState::Death);
		return;
	}
}

void Dice::DeathStart()
{
	ChangeAnimationState("Death");
}
void Dice::DeathUpdate(float _Delta)
{

}