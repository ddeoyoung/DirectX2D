#include "PreCompile.h"
#include "TutorialDoor.h"

TutorialDoor::TutorialDoor()
{
}

TutorialDoor::~TutorialDoor()
{
}

void TutorialDoor::Start()
{
	Portal::Start();

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

	PortalCollision->Transform.SetLocalScale({ 150, 150 });

	// Create Sprite
	MainRenderer->SetSprite("tutorial_exit_door.png");
	MainRenderer->AutoSpriteSizeOn();
}

void TutorialDoor::Update(float _Delta)
{
	Portal::Update(_Delta);
}
