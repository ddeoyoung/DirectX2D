#include "PreCompile.h"
#include "Portal.h"

Portal::Portal()
{
}

Portal::~Portal()
{
}

void Portal::Start()
{
	ContentActor::Start();

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::FrontgroundObject);

	PortalCollision = CreateComponent<GameEngineCollision>(CollisionOrder::Portal);
}

void Portal::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	if (PortalScale == float4::ZERO)
	{
		PortalCollision->Transform.SetLocalScale({ 150, 150 });
	}

	else
	{
		PortalCollision->Transform.SetLocalScale(PortalScale);
	}

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
	case PortalValue::Inkwell_One:
		break;
	case PortalValue::Inkwell_Three:
		break;
	case PortalValue::Inkwell_Hell:
		break;
	case PortalValue::Inkwell_Isle:
		GameEngineCore::ChangeLevel("OverWorldLevel");
		break;
	case PortalValue::BossStage:
		GameEngineCore::ChangeLevel("KingDiceLevel");
		break;
	default:
		break;
	}

	IsPortalOn = false;
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
