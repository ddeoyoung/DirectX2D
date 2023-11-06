#include "PreCompile.h"
#include "Portal.h"
#include "OverWorldLevel.h"
#include "OverWorldCharacter.h"

Portal::Portal()
{
}

Portal::~Portal()
{
}

std::shared_ptr<OverWorldCharacter> OverWorldLevel::OverWorldPlayer;

void Portal::Start()
{
	ContentActor::Start();

	PortalCollision = CreateComponent<GameEngineCollision>(CollisionOrder::Portal);
	PortalCollision->Transform.SetLocalScale({ 150, 150 });

	// Create Sprite
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::FrontgroundObject);
}

void Portal::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	CollisionCheck(_Delta);
}

void Portal::LevelChange()
{
	switch (PV)
	{
	case PortalValue::None:
		break;
	case PortalValue::ElderKettleHouse:
		break;
	case PortalValue::Tutorial:
		GameEngineCore::ChangeLevel("TutorialLevel");
		break;
	case PortalValue::OverWorld:
		GameEngineCore::ChangeLevel("OverWorldLevel");
		break;
	case PortalValue::Inkwell_Hell:
		//PortalToInkwellHell();
		break;
	case PortalValue::Inkwell_One:

		break;
	default:
		break;
	}
}

void Portal::CollisionCheck(float _Delta)
{
	if (true == PortalCollision->Collision(CollisionOrder::Player)
		&& true == GameEngineInput::IsDown('Z', this))
	{
		IsPortalOn = true;
	}
	else
	{
		IsPortalOn = false;
	}
}

void Portal::PortalToInkwellHell()
{
	std::string LevelName = GetLevel()->GetName();
	if (LevelName == "OverWorldLevel")
	{
		OverWorldLevel::OverWorldPlayer->Transform.SetLocalPosition({ 9040, -1200 });
	}
}