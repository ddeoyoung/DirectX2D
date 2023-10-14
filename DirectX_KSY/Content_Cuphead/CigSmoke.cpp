#include "PreCompile.h"
#include "CigSmoke.h"

CigSmoke::CigSmoke()
{
}

CigSmoke::~CigSmoke()
{
}

void CigSmoke::Start()
{
	ContentActor::Start();

	if (nullptr == GameEngineSprite::Find("CigSmoke"))
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

	Renderer = CreateComponent<GameEngineSpriteRenderer>();
	Renderer->SetMaterial("2DTextureOver");

	Renderer->CreateAnimation("CigSmoke", "CigSmoke");
	Renderer->ChangeAnimation("CigSmoke");
	Renderer->AutoSpriteSizeOn();
	Renderer->SetPivotType(PivotType::Bottom);

	Renderer->Transform.SetLocalPosition({ 813, -145 });
}

void CigSmoke::Update(float _Delta)
{
	ContentActor::Update(_Delta);
}