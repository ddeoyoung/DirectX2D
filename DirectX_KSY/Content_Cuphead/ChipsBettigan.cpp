#include "PreCompile.h"
#include "ChipsBettigan.h"
#include "Attack_Chips.h"
#include "BossExplosion.h"

ChipsBettigan::ChipsBettigan()
{
}

ChipsBettigan::~ChipsBettigan()
{
}

void ChipsBettigan::Start()
{
	ContentActor::Start();

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

	// Death
	MainRenderer->CreateAnimation("Chips_Death_Fall", "Chips_Death_Fall");
	MainRenderer->SetEndEvent("Chips_Death_Fall", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Chips_Death_HeadCrash");
		});
	MainRenderer->CreateAnimation("Chips_Death_HeadCrash", "Chips_Death_HeadCrash", 0.05f, -1, -1, false);
	MainRenderer->SetEndEvent("Chips_Death_HeadCrash", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Chips_Death_Finish");
		});
	MainRenderer->CreateAnimation("Chips_Death_Finish", "Chips_Death_Finish");
	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);
	Transform.SetLocalPosition({ 1100 , -650 });


	// Create Collision
	BossCollision = CreateComponent<GameEngineCollision>(CollisionOrder::Boss);

	std::shared_ptr<GameEngineSprite> Texture = GameEngineSprite::Find("Chips_Idle");
	float4 Scale = Texture->GetSpriteData(0).GetScale();
	Scale -= { 80.0f, 60.0f };

	BossCollision->SetCollisionType(ColType::AABBBOX2D);
	BossCollision->Transform.SetLocalScale(Scale);
	BossCollision->Transform.SetLocalPosition({ 0, Scale.hY() });


	// Setting
	ChangeState(ChipsState::Idle);
	HP = 30;
	ChipSet.reserve(20);
}

void ChipsBettigan::Update(float _Delta)
{
	ContentActor::Start();

	StateUpdate(_Delta);
	DeathCheck();
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
	}

	if (_StateName == "Death")
	{
		AnimationName += "_Fall";
		CheckDeathDir();
	}

	CurState = _StateName;
	MainRenderer->ChangeAnimation(AnimationName);
}

void ChipsBettigan::CreateChips()
{
	float4 TextureScale = { 250, 550 };
	float4 BossPos = Transform.GetWorldPosition();
	float4 BottomPos = { BossPos.X, BossPos.Y - TextureScale.ihY() };

	// Bottom
	if (nullptr == Chips1)
	{
		Chips1 = GetLevel()->CreateActor<Attack_Chips>();
		Chips1->SetChips(BottomPos, "Bottom");
		ChipSet.push_back(Chips1);
	}
	
	if (nullptr == Chips2)
	{
		Chips2 = GetLevel()->CreateActor<Attack_Chips>();
		Chips2->SetChips({ BottomPos.X , BottomPos.Y + 40 }, "Bottom");
		ChipSet.push_back(Chips2);
	}

	if (nullptr == Chips3)
	{
		Chips3 = GetLevel()->CreateActor<Attack_Chips>();
		Chips3->SetChips({ BottomPos.X , BottomPos.Y + 80 }, "Bottom");
		ChipSet.push_back(Chips3);
	}

	if (nullptr == Chips4)
	{
		Chips4 = GetLevel()->CreateActor<Attack_Chips>();
		Chips4->SetChips({ BottomPos.X , BottomPos.Y + 120 }, "Bottom");
		ChipSet.push_back(Chips4);
	}

	// Middle
	if (nullptr == Chips5)
	{
		Chips5 = GetLevel()->CreateActor<Attack_Chips>();
		Chips5->SetChips({ BottomPos.X , BottomPos.Y + 160 }, "Middle");
		ChipSet.push_back(Chips5);
	}

	if (nullptr == Chips6)
	{
		Chips6 = GetLevel()->CreateActor<Attack_Chips>();
		Chips6->SetChips({ BottomPos.X , BottomPos.Y + 200 }, "Middle");
		ChipSet.push_back(Chips6);
	}

	if (nullptr == Chips7)
	{
		Chips7 = GetLevel()->CreateActor<Attack_Chips>();
		Chips7->SetChips({ BottomPos.X , BottomPos.Y + 240 }, "Middle");
		ChipSet.push_back(Chips7);
	}

	for (size_t i = 0; i < ChipSet.size(); i++)
	{
		//ChipSet[i]->Death();
		ChipSet[i]->On();
	}
}

void ChipsBettigan::StretchChips(float _Delta, bool _IsStretch)
{
	// Stretch Up
	if (false == _IsStretch)
	{
		SpinDir = 1;
	}

	// Stretch Down
	if (true == _IsStretch)
	{
		SpinDir = -1;
	}

	float4 MovePos = { 0.0f, CHIPSTRETCHSPEED * _Delta * SpinDir };

	// Head
	Transform.AddLocalPosition(MovePos);

	// Middle, Bottom
	for (int i = 0; i < ChipSet.size(); i++)
	{
		float ChipSpeed = 15.0f * (i + 1);
		float4 MoveChipPos = { 0.0f, ChipSpeed * _Delta * SpinDir };

		if (nullptr == ChipSet[i])
		{
			return;
		}

		ChipSet[i]->Transform.AddLocalPosition(MoveChipPos);
	}
}


// Head, Middle, Bottom 분리해서 공격
void ChipsBettigan::SpinAttack(float _Delta)
{
	int Dir = 1;

	if (true == IsMove)
	{
		Dir = 1;
	}

	if (false == IsMove)
	{
		Dir = -1;
	}

	float4 MovePos = { Dir * CHIPATTACKSPEED * _Delta, 0.0f };

	// First
	if (false == FirstAttack && AttackTimer > 0.0f)
	{
		Transform.AddLocalPosition(MovePos);

		ChipSet[0]->Transform.AddLocalPosition(MovePos);
		ChipSet[1]->Transform.AddLocalPosition(MovePos);
		ChipSet[2]->Transform.AddLocalPosition(MovePos);
		ChipSet[3]->Transform.AddLocalPosition(MovePos);

		AttackTimer -= _Delta;
	}

	if (false == FirstAttack && AttackTimer < 0.0f)
	{
		AttackTimer = CHIPATTACKTIME;
		FirstAttack = true;
	}

	// Second
	if (true == FirstAttack && false == SecondAttack && AttackTimer > 0.0f)
	{
		ChipSet[4]->Transform.AddLocalPosition(MovePos);
		ChipSet[5]->Transform.AddLocalPosition(MovePos);

		// 임시 예외처리
		if (nullptr != ChipSet[6])
		{
			ChipSet[6]->Transform.AddLocalPosition(MovePos);
		}

		AttackTimer -= _Delta;
	}

	if (true == FirstAttack && false == SecondAttack && AttackTimer < 0.0f)
	{
		AttackTimer = CHIPATTACKTIME;
		SecondAttack = true;
	}

}

void ChipsBettigan::DeathChips()
{
	for (size_t i = 0; i < ChipSet.size(); i++)
	{
		//ChipSet[i]->Death();
		ChipSet[i]->Off();
	}
}

void ChipsBettigan::CheckIdleDir()
{
	if (IsMove == false)
	{
		// Right
		Transform.SetLocalScale({ 1.0f, 1.0f });
	}

	if (IsMove == true)
	{
		// Left
		// 기본
		Transform.SetLocalScale({ -1.0f , 1.0f });
	}
}

bool ChipsBettigan::CheckAttackDir()
{
	if (false == IsMove)
	{
		IsMove = true;
		return true;
	}
	
	else if (true == IsMove)
	{
		IsMove = false;
		return false;
	}

	return false;
}

void ChipsBettigan::CheckDeathDir()
{
	if (SpinDir == 1)
	{
		Transform.SetLocalScale({ 1.0f, 1.0f });
	}

	if (SpinDir == -1)
	{
		Transform.SetLocalScale({ -1.0f , 1.0f });
	}
}

void ChipsBettigan::DeathCheck()
{
	if (false == IsDeath)
	{
		return;
	}

	DeathChips();
	ChangeState(ChipsState::Death);
}

void ChipsBettigan::CreateDeathEffect()
{
	std::shared_ptr<BossExplosion> DeathEffect = GetLevel()->CreateActor<BossExplosion>();
	float4 BossPos = Transform.GetLocalPosition();
	BossPos.Y = -550.0f;
	DeathEffect->SetPos(BossPos);
}