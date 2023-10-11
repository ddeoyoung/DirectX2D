#include "PreCompile.h"
#include "ChipsBettigan.h"
#include "Attack_Chips.h"

ChipsBettigan::ChipsBettigan()
{
}

ChipsBettigan::~ChipsBettigan()
{
}

void ChipsBettigan::Start()
{
	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Chips_Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\ChipsBettigan\\Boss");
		
		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();

	MainRenderer->CreateAnimation("Chips_Intro", "Chips_Intro");
	MainRenderer->SetEndEvent("Chips_Intro", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Chips_Idle");
		});
	MainRenderer->CreateAnimation("Chips_Idle", "Chips_Idle", 0.05f);
	MainRenderer->CreateAnimation("Chips_Spin_Head", "Chips_Spin_Head");
	//MainRenderer->CreateAnimation("Chips_Spin_Middle", "Chips_Spin_Middle");
	//MainRenderer->CreateAnimation("Chips_Spin_Bottom", "Chips_Spin_Bottom");
	MainRenderer->CreateAnimation("Chips_Death_Fall", "Chips_Death_Fall");
	MainRenderer->SetEndEvent("Chips_Death_Fall", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Chips_Death_HeadCrash");
		});
	MainRenderer->CreateAnimation("Chips_Death_HeadCrash", "Chips_Death_HeadCrash");

	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);
	Transform.SetLocalPosition({ 1000 , -650 });

	ChangeState(ChipsState::Idle);


	// Boss Attack - Middle, Bottom
	//MiddleRenderer = CreateComponent<GameEngineSpriteRenderer>();
	//BottomRenderer = CreateComponent<GameEngineSpriteRenderer>();

	//MiddleRenderer->CreateAnimation("Chips_Spin_Middle", "Chips_Spin_Middle");
	//BottomRenderer->CreateAnimation("Chips_Spin_Bottom", "Chips_Spin_Bottom");

	//MiddleRenderer->AutoSpriteSizeOn();
	//BottomRenderer->AutoSpriteSizeOn();
	//MiddleRenderer->Transform.SetLocalPosition( { 0, -100.0f } );
	//BottomRenderer->Transform.SetLocalPosition( { 0, -300.0f } );


	// Create Collision
	BossCollision = CreateComponent<GameEngineCollision>(CollisionOrder::Boss);

	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("Chips_Idle");
	float4 Scale = Texture->GetSpriteData(0).GetScale();
	Scale -= { 80.0f, 60.0f };

	BossCollision->SetCollisionType(ColType::AABBBOX2D);
	BossCollision->Transform.SetLocalScale(Scale);
	BossCollision->Transform.SetLocalPosition({ 0, Scale.hY() });
	BossCollision->Off();
}

void ChipsBettigan::Update(float _Delta)
{
	StateUpdate(_Delta);
}

void ChipsBettigan::ChangeState(ChipsState _State)
{
	if (_State != State)
	{
		switch (_State)
		{
		case ChipsState::None:
			break;
		case ChipsState::Intro:
			IntroStart();
			break;
		case ChipsState::Idle:
			IdleStart();
			break;
		case ChipsState::Spin:
			SpinStart();
			break;
		case ChipsState::Death:
			DeathStart();
			break;
		default:
			break;
		}
	}

	State = _State;
}

void ChipsBettigan::StateUpdate(float _Delta)
{
	switch (State)
	{
	case ChipsState::None:
		break;
	case ChipsState::Intro:
		return IntroUpdate(_Delta);
	case ChipsState::Idle:
		return IdleUpdate(_Delta);
	case ChipsState::Spin:
		return SpinUpdate(_Delta);
	case ChipsState::Death:
		return DeathUpdate(_Delta);
	default:
		break;
	}
}

void ChipsBettigan::ChangeAnimationState(const std::string& _StateName)
{
	std::string AnimationName = "Chips_";
	AnimationName += _StateName;

	if (_StateName == "Spin")
	{
		AnimationName += "_Head";

		//MiddleRenderer->ChangeAnimation("Chips_Spin_Middle");
		//BottomRenderer->ChangeAnimation("Chips_Spin_Bottom");
	}

	CurState = _StateName;
	MainRenderer->ChangeAnimation(AnimationName);
}

// Head, Middle, Bottom 분리해서 공격
void ChipsBettigan::SpinAttack()
{
	// Middle, Bottom => BossAttack
}

void ChipsBettigan::CreateChips()
{
	float4 TextureScale = { 250, 550 };
	float4 BossPos = Transform.GetWorldPosition();
	float4 BottomPos = { BossPos.X, BossPos.Y - TextureScale.ihY() };


	// Bottom
	std::shared_ptr<Attack_Chips> Chips1 = GetLevel()->CreateActor<Attack_Chips>();
	Chips1->SetChips(BottomPos, "Bottom");
	ChipSet.push_back(Chips1);

	std::shared_ptr<Attack_Chips> Chips2 = GetLevel()->CreateActor<Attack_Chips>();
	Chips2->SetChips({ BottomPos.X , BottomPos.Y + 40 }, "Bottom");
	ChipSet.push_back(Chips2);

	std::shared_ptr<Attack_Chips> Chips3 = GetLevel()->CreateActor<Attack_Chips>();
	Chips3->SetChips({ BottomPos.X , BottomPos.Y + 80 }, "Bottom");
	ChipSet.push_back(Chips3);

	std::shared_ptr<Attack_Chips> Chips4 = GetLevel()->CreateActor<Attack_Chips>();
	Chips4->SetChips({ BottomPos.X , BottomPos.Y + 120 }, "Bottom");
	ChipSet.push_back(Chips4);


	// Middle
	std::shared_ptr<Attack_Chips> Chips5 = GetLevel()->CreateActor<Attack_Chips>();
	Chips5->SetChips({ BottomPos.X , BottomPos.Y + 160 }, "Middle");
	ChipSet.push_back(Chips5);

	std::shared_ptr<Attack_Chips> Chips6 = GetLevel()->CreateActor<Attack_Chips>();
	Chips6->SetChips({ BottomPos.X , BottomPos.Y + 200 }, "Middle");
	ChipSet.push_back(Chips6);

	std::shared_ptr<Attack_Chips> Chips7 = GetLevel()->CreateActor<Attack_Chips>();
	Chips7->SetChips({ BottomPos.X , BottomPos.Y + 240 }, "Middle");
	ChipSet.push_back(Chips7);
}

void ChipsBettigan::StretchChips(float _Delta)
{
	float4 MovePos = { 0.0f, STRETCHSPEED * _Delta };

	// Head
	Transform.AddLocalPosition(MovePos);

	// Middle, Bottom
	for (int i = 0; i < ChipSet.size(); i++)
	{
		float ChipSpeed = 15.0f * (i + 1);
		float4 MoveChipPos = { 0.0f, ChipSpeed * _Delta };
		ChipSet[i]->Transform.AddLocalPosition(MoveChipPos);
	}
}