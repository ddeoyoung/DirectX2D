#include "PreCompile.h"
#include "OverWorldHouse.h"

OverWorldHouse::OverWorldHouse()
{
}

OverWorldHouse::~OverWorldHouse()
{
}


void OverWorldHouse::Start()
{
	Portal::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("OverWorld_House"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\OverWorld");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	MainRenderer->CreateAnimation("OverWorld_House", "OverWorld_House", 0.05f);
	MainRenderer->ChangeAnimation("OverWorld_House");
	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetRenderOrder(RenderOrder::BackgroundObject);

	PortalCollision->Transform.SetLocalScale({ 70, 80 });
}

void OverWorldHouse::Update(float _Delta)
{
	Portal::Update(_Delta);
}
