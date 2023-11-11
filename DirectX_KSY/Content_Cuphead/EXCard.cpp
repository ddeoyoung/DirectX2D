#include "PreCompile.h"
#include "EXCard.h"

EXCard::EXCard()
{
}

EXCard::~EXCard()
{
}


void EXCard::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("EXCard_Charge"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\UI\\UI\\EXCard");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::UI);
	MainRenderer->CreateAnimation("EXCard_Charge", "EXCard_Charge", 0.05f, -1, -1, false);
	MainRenderer->ChangeAnimation("EXCard_Charge");
	MainRenderer->AutoSpriteSizeOn();
}

void EXCard::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}
