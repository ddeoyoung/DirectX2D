#include "PreCompile.h"
#include "KingDice.h"
#include "Dice.h"
#include "Marker.h"
#include "Attack_Card.h"

KingDice::KingDice()
{
}

KingDice::~KingDice()
{
}

bool KingDice::IsDiceOn;

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

	// Set Position
	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X + 27.0f, -HalfWindowScale.Y - 28.0f });


	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::Play);
	HeadRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::PlayFront);
	ArmRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::PlayBack);


	//////////////////////////////////////// Main /////////////////////////////////////////
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
	MainRenderer->CreateAnimation("KingDice_CameraEat_First", "KingDice_CameraEat_First", 0.06f, -1, -1, false);
	MainRenderer->SetEndEvent("KingDice_CameraEat_First", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->Transform.SetLocalPosition({ 0 , 600 });
			_Renderer->SetPivotType(PivotType::Top);
			_Renderer->SetRenderOrder(RenderOrder::Max);
			_Renderer->ChangeAnimation("KingDice_CameraEat_Second");
		});

	MainRenderer->CreateAnimation("KingDice_CameraEat_Second", "KingDice_CameraEat_Second", 0.06f, -1, -1, false);
	MainRenderer->SetEndEvent("KingDice_CameraEat_Second", [](GameEngineSpriteRenderer* _Renderer)
		{
			float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half(); 
			_Renderer->Transform.SetLocalPosition({ HalfWindowScale.X + 20.0f, -HalfWindowScale.Y - 45.0f });
			_Renderer->SetPivotType(PivotType::Bottom);
			_Renderer->GetParent<KingDice>()->SetState(KingDiceState::CameraEat);
			_Renderer->Off();

			// IsLevelChange = true;
			_Renderer->GetParent<KingDice>()->SetLevelChange();
		});

	// Reveal
	MainRenderer->CreateAnimation("KingDice_Reveal", "KingDice_Reveal", 0.05f);

	// Wink
	MainRenderer->CreateAnimation("KingDice_Wink", "KingDice_Wink", 0.08f,-1,-1,false);

	// Curious
	MainRenderer->CreateAnimation("KingDice_Curious_Start", "KingDice_Curious_Start");
	MainRenderer->SetEndEvent("KingDice_Curious_Start", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("KingDice_Curious_Body");
			_Renderer->GetParent<KingDice>()->SetState(KingDiceState::Curious);
			_Renderer->GetParent<KingDice>()->GetHeadRender()->On();
		});

	MainRenderer->CreateAnimation("KingDice_Curious_Body", "KingDice_Curious_Body");

	// Death
	MainRenderer->CreateAnimation("KingDice_Death", "KingDice_Death");

	// Attack
	MainRenderer->CreateAnimation("KingDice_AttackIdle", "KingDice_Idle", 0.05f);
	MainRenderer->CreateAnimation("KingDice_Attack_Left_Start", "KingDice_Attack_Left_Start", 0.05f, -1, -1, false);
	MainRenderer->SetEndEvent("KingDice_Attack_Left_Start", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("KingDice_Attack_Left_Loop");
			_Renderer->GetParent<KingDice>()->SetState(KingDiceState::Attack);
			_Renderer->GetParent<KingDice>()->GetArmRender()->On();
		});
	MainRenderer->CreateAnimation("KingDice_Attack_Left_Loop", "KingDice_Attack_Left_Loop", 0.05f);
	MainRenderer->CreateAnimation("KingDice_Attack_Left_End", "KingDice_Attack_Left_Start", 0.05f, 15, 0, false);
	MainRenderer->SetEndEvent("KingDice_Attack_Left_End", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("KingDice_AttackIdle");
			_Renderer->GetParent<KingDice>()->SetState(KingDiceState::AttackIdle);
		});

	MainRenderer->CreateAnimation("KingDice_Attack_Right_Start", "KingDice_Attack_Right_Start", 0.05f, -1, -1, false);
	MainRenderer->SetEndEvent("KingDice_Attack_Right_Start", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("KingDice_Attack_Right_Loop");
			_Renderer->GetParent<KingDice>()->SetState(KingDiceState::Attack);
			_Renderer->GetParent<KingDice>()->GetArmRender()->On();
		});
	MainRenderer->CreateAnimation("KingDice_Attack_Right_Loop", "KingDice_Attack_Right_Loop", 0.05f);
	MainRenderer->CreateAnimation("KingDice_Attack_Right_End", "KingDice_Attack_Right_Start", 0.05f, 15, 0, false);
	MainRenderer->SetEndEvent("KingDice_Attack_Right_End", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("KingDice_AttackIdle");
			_Renderer->GetParent<KingDice>()->SetState(KingDiceState::AttackIdle);
		});


	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);


	//////////////////////////////////// Head //////////////////////////////////////////
	// Curious Head
	HeadRenderer->CreateAnimation("KingDice_Curious_Head", "KingDice_Curious_Head", 0.04f);
	HeadRenderer->ChangeAnimation("KingDice_Curious_Head");
	HeadRenderer->AutoSpriteSizeOn();
	HeadRenderer->SetPivotType(PivotType::Bottom);
	HeadRenderer->Off();


	//////////////////////////////////// Arm ///////////////////////////////////////////
	// Attack Arm
	ArmRenderer->CreateAnimation("KingDice_Attack_Left_Arm_Start", "KingDice_Attack_Left_Arm_Start", 0.04f, -1, -1, false);
	ArmRenderer->SetEndEvent("KingDice_Attack_Left_Arm_Start", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("KingDice_Attack_Left_Arm");
		});
	ArmRenderer->CreateAnimation("KingDice_Attack_Left_Arm", "KingDice_Attack_Left_Arm", 0.04f);
	ArmRenderer->CreateAnimation("KingDice_Attack_Right_Arm_Start", "KingDice_Attack_Right_Arm_Start", 0.04f, -1, -1, false);
	ArmRenderer->SetEndEvent("KingDice_Attack_Right_Arm_Start", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("KingDice_Attack_Right_Arm");
		});
	ArmRenderer->CreateAnimation("KingDice_Attack_Right_Arm", "KingDice_Attack_Right_Arm", 0.04f);
	ArmRenderer->ChangeAnimation("KingDice_Attack_Left_Arm");
	ArmRenderer->AutoSpriteSizeOn();
	ArmRenderer->SetPivotType(PivotType::Bottom);
	ArmRenderer->Off();


	//////////////////////////////////// Collision ///////////////////////////////////////////
	BossCollision = CreateComponent<GameEngineCollision>(CollisionOrder::Boss);
	BossCollision->SetCollisionType(ColType::AABBBOX2D);
	BossCollision->Transform.SetLocalScale({ 300, 300 });
	BossCollision->Transform.SetLocalPosition({ 0, 200 });
	BossCollision->Off();

	// Setting
	CreateCardPattern();
	ChangeState(KingDiceState::IntroHand);
	HP = 50;
}

void KingDice::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	StateUpdate(_Delta);
	DeathCheck();
}

void KingDice::ChangeState(KingDiceState _State)
{
	if (State != _State)
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
		case KingDiceState::Attack:
			AttackStart();
			break;
		case KingDiceState::AttackIdle:
			AttackIdleStart();
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
	case KingDiceState::Attack:
		return AttackUpdate(_Delta);
	case KingDiceState::AttackIdle:
		return AttackIdleUpdate(_Delta);
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

	// Attack
	if (_StateName == "Attack_Left" || _StateName == "Attack_Right")
	{
		AnimationName += "_Start";
	}

	CurState = _StateName;
	MainRenderer->ChangeAnimation(AnimationName);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////// Attack //////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void KingDice::RandomAttackDir()
{
	GameEngineRandom NewRandom;
	int Random = NewRandom.RandomInt(1, 2);
	NewRandom.SetSeed(Random);

	switch (Random)
	{
	case 1:
		AttackDir = "Left";
		break;
	case 2:
		AttackDir = "Right";
		break;
	default:
		break;
	}
}

void KingDice::CheckAttackCount()
{
	bool CheckLoop = IsAttackLoop();

	if (true == CheckLoop)
	{
		if (true == MainRenderer->IsCurAnimationEnd())
		{
			AttackCount -= 1;
		}
	}
}

void KingDice::SetAttackPos() 
{
	if (AttackDir == "Left")
	{
		Transform.AddLocalPosition({ -50 , -310 });
	}

	else if (AttackDir == "Right")
	{
		Transform.AddLocalPosition({ 50 , -310 });
	}
}

void KingDice::ResetAttackPos()
{
	if (AttackDir == "Left")
	{
		Transform.AddLocalPosition({ 50 , 310 });
	}

	else if (AttackDir == "Right")
	{
		Transform.AddLocalPosition({ -50 , 310 });
	}
}

void KingDice::SetAttackArm()
{
	std::string AnimationName = "KingDice_Attack_" + AttackDir + "_Arm_Start";
	ArmRenderer->ChangeAnimation(AnimationName);

	if (AttackDir == "Left")
	{
		ArmRenderer->Transform.SetLocalPosition({ -300 , 0 });
	}

	else if (AttackDir == "Right")
	{
		ArmRenderer->Transform.SetLocalPosition({ 250 , 0 });
	}
}

void KingDice::SetBossCollision()
{
	BossCollision->On();
	BossCollision->Transform.SetLocalScale({ 300, 300 });
	
	if (AttackDir == "Left")
	{
		BossCollision->Transform.AddLocalPosition({ 50, 310 });
	}

	else if (AttackDir == "Right")
	{
		BossCollision->Transform.AddLocalPosition({ -50, 310 });
	}
}

void KingDice::ResetBossCollision()
{
	BossCollision->Transform.SetLocalScale({ 250, 250 });

	if (AttackDir == "Left")
	{
		BossCollision->Transform.AddLocalPosition({ -50, -310 });
	}

	else if (AttackDir == "Right")
	{
		BossCollision->Transform.AddLocalPosition({ 50, -310 });
	}
}

void KingDice::CreateCards()
{
	std::shared_ptr<Attack_Card> Card = GetLevel()->CreateActor<Attack_Card>();

	CardType Type = CardPattern.back();
	Card->SetCardType(Type);
	CardPattern.pop_back();

	if (AttackDir == "Left")
	{
		// Left = 1
		Card->SetCardAttDir(1);
		Card->Transform.SetLocalScale({ 1.0f, 1.0f });
		Card->Transform.SetLocalPosition({ 275, -550 });
	}
	else if (AttackDir == "Right")
	{
		// Right = -1
		Card->SetCardAttDir(-1);
		Card->Transform.SetLocalScale({ -1.0f, 1.0f });
		Card->Transform.SetLocalPosition({ 1030, -550 });
	}
}

bool KingDice::IsAttackLoop()
{
	if (true == MainRenderer->IsCurAnimation("KingDice_Attack_Left_Loop")
		|| true == MainRenderer->IsCurAnimation("KingDice_Attack_Right_Loop"))
	{
		return true;
	}

	return false;
}

void KingDice::CreateCardPattern()
{
	CardSet.clear();

	CardType Club = CardType::Club;
	CardType Diamond = CardType::Diamond;
	CardType Heart = CardType::Heart;
	CardType Spade = CardType::Spade;

	// 뒤에서부터 생성 시작
	std::vector<CardType> Set1 = { Heart, Club, Spade, Heart, Diamond, Heart, Club, Spade, Diamond, Heart, Club, Spade };
	std::vector<CardType> Set2 = { Diamond, Heart, Club, Spade, Heart, Diamond, Heart, Club, Spade, Diamond, Heart, Club };
	std::vector<CardType> Set3 = { Heart, Spade, Heart, Diamond, Club, Heart, Spade, Heart, Diamond, Heart, Spade, Diamond };
	std::vector<CardType> Set4 = { Club, Heart, Spade, Diamond, Heart, Club, Heart, Spade, Diamond, Heart, Club, Spade };

	CardSet.push_back(Set1);
	CardSet.push_back(Set2);
	CardSet.push_back(Set3);
	CardSet.push_back(Set4);
}

std::vector<CardType> KingDice::GetRandomCardSet()
{
	int Size = static_cast<int>(CardSet.size());

	GameEngineRandom NewRandom;
	int Random = NewRandom.RandomInt(0, Size - 1);
	NewRandom.SetSeed(Random);

	return CardSet[Random];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////// Death //////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void KingDice::DeathCheck()
{
	if (false == IsDeath)
	{
		return;
	}

	ChangeState(KingDiceState::Death);
}