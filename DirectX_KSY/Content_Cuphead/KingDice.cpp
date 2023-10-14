#include "PreCompile.h"
#include "KingDice.h"
#include "Dice.h"

KingDice::KingDice()
{
}

KingDice::~KingDice()
{
}

void KingDice::Start()
{
	ContentActor::Start();

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
	HeadRenderer = CreateComponent<GameEngineSpriteRenderer>();

	// Intro
	MainRenderer->CreateAnimation("KingDice_IntroHand", "KingDice_IntroHand", 0.04f, false);
	MainRenderer->SetEndEvent("KingDice_IntroHand", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("KingDice_IntroBody");
			_Renderer->GetParent<KingDice>()->SetState(KingDiceState::IntroBody);
		});
	MainRenderer->CreateAnimation("KingDice_IntroBody", "KingDice_IntroBody", 0.04f, false);
	MainRenderer->SetEndEvent("KingDice_IntroBody", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("KingDice_Idle");
			_Renderer->GetParent<KingDice>()->SetState(KingDiceState::Idle);
		});

	// Idle
	MainRenderer->CreateAnimation("KingDice_Idle", "KingDice_Idle", 0.05f);

	// CameraEat
	MainRenderer->CreateAnimation("KingDice_CameraEat_First", "KingDice_CameraEat_First", 0.06f, false);
	MainRenderer->SetEndEvent("KingDice_CameraEat_First", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->Transform.SetLocalPosition({ 0 , 600 });
			_Renderer->SetPivotType(PivotType::Top);
			_Renderer->SetRenderOrder(RenderOrder::Max);
			_Renderer->ChangeAnimation("KingDice_CameraEat_Second");
		});

	MainRenderer->CreateAnimation("KingDice_CameraEat_Second", "KingDice_CameraEat_Second", 0.06f, false);
	MainRenderer->SetEndEvent("KingDice_CameraEat_Second", [](GameEngineSpriteRenderer* _Renderer)
		{
			float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half(); 
			_Renderer->Transform.SetLocalPosition({ HalfWindowScale.X + 20.0f, -HalfWindowScale.Y - 45.0f });
			_Renderer->SetPivotType(PivotType::Bottom);
			//_Renderer->GetParent<KingDice>()->SetState(KingDiceState::CameraEat);
			_Renderer->GetParent<KingDice>()->SetSubStage();
		});

	MainRenderer->CreateAnimation("KingDice_Reveal", "KingDice_Reveal", 0.05f, false);
	MainRenderer->CreateAnimation("KingDice_Wink", "KingDice_Wink", 0.07f);

	MainRenderer->CreateAnimation("KingDice_Curious_Start", "KingDice_Curious_Start");
	MainRenderer->SetEndEvent("KingDice_Curious_Start", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("KingDice_Curious_Body");
			_Renderer->GetParent<KingDice>()->SetState(KingDiceState::Curious);
			_Renderer->GetParent<KingDice>()->GetHeadRender()->On();
		});

	MainRenderer->CreateAnimation("KingDice_Curious_Body", "KingDice_Curious_Body");
	MainRenderer->CreateAnimation("KingDice_Death", "KingDice_Death");

	MainRenderer->SetRenderOrder(RenderOrder::Max);
	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);


	// Curious Head
	HeadRenderer->CreateAnimation("KingDice_Curious_Head", "KingDice_Curious_Head", 0.05f);
	HeadRenderer->ChangeAnimation("KingDice_Curious_Head");
	HeadRenderer->SetRenderOrder(RenderOrder::Max);
	HeadRenderer->AutoSpriteSizeOn();
	HeadRenderer->SetPivotType(PivotType::Bottom);
	HeadRenderer->Off();

	ChangeState(KingDiceState::Curious);

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	//Transform.SetLocalPosition({HalfWindowScale.X + 20.0f, -HalfWindowScale.Y -45.0f});
	Transform.SetLocalPosition({ HalfWindowScale.X + 27.0f, -HalfWindowScale.Y - 28.0f });
}

void KingDice::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	StateUpdate(_Delta);
}

void KingDice::ChangeState(KingDiceState _State)
{
	if (_State != State)
	{
		switch (_State)
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
			WinkStart();
			break;
		case KingDiceState::Curious:
			CuriousStart();
			break;
		case KingDiceState::Reveal:
			RevealStart();
			break;
		case KingDiceState::CameraEat:
			CameraEatStart();
			break;
		case KingDiceState::Death:
			DeathStart();
			break;
		default:
			break;
		}
	}

	State = _State;
}

void KingDice::StateUpdate(float _Delta)
{
	switch (State)
	{
	case KingDiceState::None:
		break;
	case KingDiceState::IntroHand:
		return IntroHandUpdate(_Delta);
	case KingDiceState::IntroBody:
		return IntroBodyUpdate(_Delta);
	case KingDiceState::Idle:
		return IdleUpdate(_Delta);
	case KingDiceState::Wink:
		return WinkUpdate(_Delta);
	case KingDiceState::Curious:
		return CuriousUpdate(_Delta);
	case KingDiceState::Reveal:
		return RevealUpdate(_Delta);
	case KingDiceState::CameraEat:
		return CameraEatUpdate(_Delta);
	case KingDiceState::Death:
		return DeathUpdate(_Delta);
	default:
		break;
	}
}

void KingDice::ChangeAnimationState(const std::string& _StateName)
{
	std::string AnimationName = "KingDice_";
	AnimationName += _StateName;


	// CameraEat
	if (_StateName == "CameraEat")
	{
		AnimationName += "_First";
	}

	// Curious
	if (_StateName == "Curious")
	{
		AnimationName += "_Start";
	}

	CurState = _StateName;
	MainRenderer->ChangeAnimation(AnimationName);
}

void KingDice::SetSubStage()
{
	GameEngineCore::ChangeLevel("ChipsBettiganLevel");
}