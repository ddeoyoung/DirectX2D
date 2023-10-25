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
	if (nullptr == GameEngineSprite::Find("FightText_Ready"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\FightText");

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

	MainRenderer->Off();
	ReadyTimer = 0.0f;
	IsReady = false;
}

void FightText::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	// Ready
	if (TextName == "FightText_Ready")
	{
		ReadyTimer += _Delta;
		if (ReadyTimer > 1.0f && IsReady == false)
		{
			IsReady = true;
			MainRenderer->On();
			MainRenderer->ChangeAnimation(TextName);
		}

		else if (true == IsReady)
		{
			EndCheck();
		}
	}

	// Knock Out
	else if (TextName == "FightText_KnockOut")
	{
		MainRenderer->On();
		MainRenderer->ChangeAnimation(TextName);

		EndCheck();
	}
}

void FightText::SetFightText(const std::string& _Name)
{
	TextName = "FightText_";

	if (_Name == "KnockOut" || _Name == "Ready")
	{
		TextName += _Name;
	}
}

void FightText::EndCheck()
{
	if (true == MainRenderer->IsCurAnimationEnd())
	{
		Death();
	}
}