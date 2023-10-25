#include "PreCompile.h"
#include "FightText.h"

FightText::FightText()
{
}

FightText::~FightText()
{
}

void FightText::Start()
{
	ContentActor::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("FightText"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\UI\\FightText");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::Max);
	MainRenderer->CreateAnimation("FightText_Ready", "FightText_Ready", 0.05f, false);
	MainRenderer->SetEndEvent("FightText_Ready", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->Off();
		});
	MainRenderer->CreateAnimation("FightText_KnockOut", "FightText_KnockOut", 0.05f, false);
	MainRenderer->SetEndEvent("FightText_KnockOut", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->Off();
		});

	MainRenderer->ChangeAnimation("FightText_Ready");
	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetAutoScaleRatio(2.5);
	MainRenderer->Transform.SetLocalPosition({ 640, -360 });
}

void FightText::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	EndCheck();
}

void FightText::SetFightText(const std::string& _Name)
{
	std::string Name = "FightText_";

	if (_Name == "KnockOut" || _Name == "Ready")
	{
		Name += _Name;
		MainRenderer->ChangeAnimation(Name);
	}
}

void FightText::EndCheck()
{
	if (true == MainRenderer->IsCurAnimationEnd())
	{
		Death();
	}
}