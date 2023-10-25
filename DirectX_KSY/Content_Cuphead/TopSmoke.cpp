#include "PreCompile.h"
#include "TopSmoke.h"

TopSmoke::TopSmoke()
{
}

TopSmoke::~TopSmoke()
{
}

void TopSmoke::Start()
{
	ContentActor::Start();

	if (nullptr == GameEngineSprite::Find("TopSmoke"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\ChipsBettigan\\StageObject");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	Renderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::FrontgroundEffect);
	Renderer->SetMaterial("2DTextureOver");

	Renderer->CreateAnimation("TopSmoke", "TopSmoke");
	Renderer->ChangeAnimation("TopSmoke");

	Renderer->AutoSpriteSizeOn();
	Renderer->SetPivotType(PivotType::Top);
	Renderer->Transform.SetLocalPosition({ 640.0f , 0.0f });
}

void TopSmoke::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}