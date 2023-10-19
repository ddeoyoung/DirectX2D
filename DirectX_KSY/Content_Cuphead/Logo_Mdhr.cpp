#include "PreCompile.h"
#include "Logo_Mdhr.h"

Logo_Mdhr::Logo_Mdhr()
{
}

Logo_Mdhr::~Logo_Mdhr()
{
}

void Logo_Mdhr::Start()
{
	ContentActor::Start();

	if (nullptr == GameEngineSprite::Find("Logo"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	Renderer = CreateComponent<GameEngineSpriteRenderer>();
	Renderer->CreateAnimation("Logo", "Logo", 0.03f);
	Renderer->ChangeAnimation("Logo");
	Renderer->AutoSpriteSizeOn();

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Renderer->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y });
}

void Logo_Mdhr::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}