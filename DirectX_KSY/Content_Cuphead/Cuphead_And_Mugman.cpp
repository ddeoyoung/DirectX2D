#include "PreCompile.h"
#include "Cuphead_And_Mugman.h"

Cuphead_And_Mugman::Cuphead_And_Mugman()
{
}

Cuphead_And_Mugman::~Cuphead_And_Mugman()
{
}

void Cuphead_And_Mugman::Start()
{
	ContentActor::Start();

	if (nullptr == GameEngineSprite::Find("Cuphead_And_Mugman"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Title");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	Renderer = CreateComponent<GameEngineSpriteRenderer>();
	Renderer->CreateAnimation("Cuphead_And_Mugman", "Cuphead_And_Mugman", 0.04f);
	Renderer->ChangeAnimation("Cuphead_And_Mugman");

	Renderer->AutoSpriteSizeOn();
	Renderer->SetPivotType(PivotType::Bottom);

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Renderer->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y -400.0f });
}

void Cuphead_And_Mugman::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}