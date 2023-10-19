#include "PreCompile.h"
#include "Marker.h"

Marker::Marker()
{
}

Marker::~Marker()
{
}

void Marker::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Marker_Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\KingDice\\StageObject\\Marker");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();

	MainRenderer->CreateAnimation("Marker_Idle", "Marker_Idle");
	MainRenderer->CreateAnimation("Marker_Spin", "Marker_Spin");

	MainRenderer->ChangeAnimation("Marker_Idle");
	MainRenderer->AutoSpriteSizeOn();

	Transform.SetLocalPosition({ 220, -300 });
}

void Marker::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}