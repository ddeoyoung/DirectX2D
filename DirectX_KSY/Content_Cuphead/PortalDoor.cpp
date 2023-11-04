#include "PreCompile.h"
#include "PortalDoor.h"

PortalDoor::PortalDoor()
{
}

PortalDoor::~PortalDoor()
{
}

void PortalDoor::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("tutorial_exit_door.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Tutorial");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		// Exit Door
		GameEngineTexture::Load(Dir.GetStringPath() + "\\tutorial_exit_door.png");
		GameEngineSprite::CreateSingle("tutorial_exit_door.png");
	}

	PortalCollision = CreateComponent<GameEngineCollision>(CollisionOrder::Portal);
	PortalCollision->Transform.SetLocalScale({ 150, 150 });

	// Create Sprite
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();
	MainRenderer->SetSprite("tutorial_exit_door.png");
	MainRenderer->AutoSpriteSizeOn();
}

void PortalDoor::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	CollisionCheck(_Delta);
}

void PortalDoor::LevelChange()
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
	default:
		break;
	}
}

void PortalDoor::CollisionCheck(float _Delta)
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