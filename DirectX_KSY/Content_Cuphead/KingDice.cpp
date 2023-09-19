#include "PreCompile.h"
#include "KingDice.h"

KingDice::KingDice()
{
}

KingDice::~KingDice()
{
}

void KingDice::Start()
{
	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("KingDice_Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\KingDice\\Boss");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}


	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();

	MainRenderer->CreateAnimation("KingDice_IntroHand", "KingDice_IntroHand", 0.04f, false);
	MainRenderer->SetEndEvent("KingDice_IntroHand", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("KingDice_IntroBody");
		});
	MainRenderer->CreateAnimation("KingDice_IntroBody", "KingDice_IntroBody", 0.04f, false);
	MainRenderer->SetEndEvent("KingDice_IntroBody", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("KingDice_Idle");
		});
	MainRenderer->CreateAnimation("KingDice_Idle", "KingDice_Idle", 0.05f);
	MainRenderer->CreateAnimation("KingDice_Reveal", "KingDice_Reveal");
	MainRenderer->CreateAnimation("KingDice_CameraEat", "KingDice_CameraEat");
	MainRenderer->CreateAnimation("KingDice_Death", "KingDice_Death");
	MainRenderer->ChangeAnimation("KingDice_IntroHand");

	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({HalfWindowScale.X + 20.0f, -HalfWindowScale.Y -45.0f});
}

void KingDice::Update(float _Delta)
{

}

void KingDice::ChangeState(KingDiceState _State)
{
	if (_State != State)
	{
		switch (State)
		{
		case KingDiceState::None:
			break;
		case KingDiceState::IntroHand:
			IntroHandStart();
			break;
		case KingDiceState::IntroBody:
			IntroBodyStart();
			break;
		case KingDiceState::Idle:
			IdleStart();
			break;
		case KingDiceState::Wink:
			break;
		case KingDiceState::Curious:
			break;
		case KingDiceState::Reveal:
			break;
		case KingDiceState::CameraEat:
			break;
		case KingDiceState::Death:
			break;
		default:
			break;
		}
	}

	State = _State;
}

void KingDice::StateUpdate(float _Delta)
{

}