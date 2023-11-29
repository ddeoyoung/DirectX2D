#include "PreCompile.h"
#include "TitleMenuButton.h"

TitleMenuButton::TitleMenuButton()
{
}

TitleMenuButton::~TitleMenuButton()
{
}


void TitleMenuButton::Start()
{
	ContentActor::Start();

	if (nullptr == GameEngineSprite::Find("Menu_Start.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Title\\Menu");

		// Start
		GameEngineTexture::Load(Dir.GetStringPath() + "\\Menu_Start.png");
		GameEngineSprite::CreateSingle("Menu_Start.png");

		// Start Dark
		GameEngineTexture::Load(Dir.GetStringPath() + "\\Menu_Start_Dark.png");
		GameEngineSprite::CreateSingle("Menu_Start_Dark.png");

		// Exit
		GameEngineTexture::Load(Dir.GetStringPath() + "\\Menu_Exit.png");
		GameEngineSprite::CreateSingle("Menu_Exit.png");

		// Exit Dark
		GameEngineTexture::Load(Dir.GetStringPath() + "\\Menu_Exit_Dark.png");
		GameEngineSprite::CreateSingle("Menu_Exit_Dark.png");
	}

	StartRenderer = CreateComponent<GameEngineSpriteRenderer>();
	StartRenderer->SetSprite("Menu_Start.png");
	StartRenderer->AutoSpriteSizeOn();
	StartRenderer->Transform.SetLocalPosition({ 640, -330 });

	ExitRenderer = CreateComponent<GameEngineSpriteRenderer>();
	ExitRenderer->SetSprite("Menu_Exit_Dark.png");
	ExitRenderer->AutoSpriteSizeOn();
	ExitRenderer->Transform.SetLocalPosition({ 640, -380 });

	CurButtonType = MenuButtonType::Start;
}

void TitleMenuButton::Update(float _Delta)
{
	ContentActor::Update(_Delta);
	SelectButton();
}

void TitleMenuButton::SelectButton()
{
	if (true == GameEngineInput::IsDown(VK_UP, this))
	{
		CurButtonType = MenuButtonType::Start;
		StartRenderer->SetSprite("Menu_Start.png");
		ExitRenderer->SetSprite("Menu_Exit_Dark.png");
	}

	else if (true == GameEngineInput::IsDown(VK_DOWN, this))
	{
		CurButtonType = MenuButtonType::Exit;
		StartRenderer->SetSprite("Menu_Start_Dark.png");
		ExitRenderer->SetSprite("Menu_Exit.png");
	}

	if (true == GameEngineInput::IsDown(VK_SPACE, this))
	{
		switch (CurButtonType)
		{
		case MenuButtonType::Start:
			IsLevelChange = true;
			IsGameExit = false;
			break;
		case MenuButtonType::Exit:
			// 게임 종료
			IsLevelChange = false;
			IsGameExit = true;
			break;
		default:
			IsLevelChange = false;
			IsGameExit = false;
			break;
		}
	}
}