#include "PreCompile.h"
#include "KingDiceLevel.h"

#include "ContentBackground.h"
#include "BaseCharacter.h"
#include "Cuphead.h"
#include "KingDice.h"
#include "Marker.h"

#include "FadeAnimation.h"
#include "FightText.h"

KingDiceLevel::KingDiceLevel()
{
}

KingDiceLevel::~KingDiceLevel()
{
}

void KingDiceLevel::Start()
{
	ContentLevel::Start();
}

void KingDiceLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);

	if (false == IsFightKingDice)
	{
		CheckRouletteSpace();
		ChangeToSubBossStage();
		
		if (true == IsFightKingDice)
		{
			FightKingDiceStart();
		}
	}

	if (true == IsFightKingDice)
	{
		FightKingDiceUpdate(_Delta);
	}

	CheckStageClear();
	CreateFadeOut(_Delta);

	
	// Ending (Outro Level)
	if (true == FadeOut->IsCurAnimationEnd())
	{
		GameEngineCore::ChangeLevel("OutroLevel");
	}
}

void KingDiceLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentLevel::LevelStart(_PrevLevel);

	LevelStartTextureLoad();
	LevelStartTextureSet();

	// Marker
	if (nullptr == Roulette_Marker)
	{
		Roulette_Marker = CreateActor<Marker>();
	}
	
	// Boss
	if (nullptr == Boss)
	{
		Boss = CreateActor<KingDice>();
		Boss->On();
		Boss->SetState(KingDiceState::IntroHand);
	}

	// Player
	if (nullptr == CurLevelPlayer)
	{
		CurLevelPlayer = CreateActor<Cuphead>();
		CurLevelPlayer->Transform.SetLocalPosition({ 250, -550 });
	}
	
	// LevelChange
	LevelName = "";

	// Fade Out
	if (nullptr == FadeOut)
	{
		FadeOut = CreateActor<FadeAnimation>();
		FadeOut->SetFade("Out");
		FadeOut->Off();
	}
}

void KingDiceLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);

	if (nullptr != Boss)
	{
		Boss->Death();
		Boss = nullptr;
	}

	if (nullptr != CurLevelPlayer)
	{
		CurLevelPlayer->Death();
		CurLevelPlayer = nullptr;
	}
}

bool KingDiceLevel::CheckMarkerEnd()
{
	if (true == Marker::IsSpinEnd)
	{
		return true;
	}
	
	return false;
}

void KingDiceLevel::CheckRouletteSpace()
{
	bool Check = CheckMarkerEnd();
	int SpaceNum = Roulette_Marker->GetCurRouletteSpace();


	if (true == Check)
	{
		switch (SpaceNum)
		{
		case 0:
			SpaceState::SpaceStart;
			Boss->SetIsSafeSpace(true);
			break;
		case 1:
			SpaceState::Space1;
			Boss->SetIsSafeSpace(false);
			LevelName = "TipsyTroopLevel";
			break;
		case 2:
			SpaceState::Space2;
			Boss->SetIsSafeSpace(false);
			LevelName = "ChipsBettiganLevel";
			break;
		case 3:
			SpaceState::Space3;
			Boss->SetIsSafeSpace(false);
			LevelName = "MrWheezyLevel";
			break;
		case 4:
			SpaceState::SpaceSafe1;
			Boss->SetIsSafeSpace(true);
			break;
		case 5:
			SpaceState::Space4;
			Boss->SetIsSafeSpace(true);
			break;
		case 6:
			SpaceState::Space5;
			Boss->SetIsSafeSpace(true);
			break;
		case 7:
			SpaceState::Space6;
			Boss->SetIsSafeSpace(true);
			break;
		case 8:
			SpaceState::SpaceSafe2;
			Boss->SetIsSafeSpace(true);
			break;
		case 9:
			SpaceState::Space7;
			Boss->SetIsSafeSpace(true);
			break;
		case 10:
			SpaceState::Space8;
			Boss->SetIsSafeSpace(true);
			break;
		case 11:
			SpaceState::Space9;
			Boss->SetIsSafeSpace(true);
			break;
		case 12:
			SpaceState::SpaceSafe3;
			Boss->SetIsSafeSpace(true);
			break;
		case 13:
			SpaceState::SpaceStartOver;
			Boss->SetIsSafeSpace(true);
			break;
		case 14:
			SpaceState::SpaceFinish;
			IsFightKingDice = true;
			break;
		default:
			break;
		}

	}
}

void KingDiceLevel::ChangeToSubBossStage()
{
	if (true == Boss->GetLevelChange())
	{
		Boss->SetLevelChange(false);
		GameEngineCore::ChangeLevel(LevelName);
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////    Fight    //////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void KingDiceLevel::FightKingDiceStart()
{
	if (nullptr == ReadyText)
	{
		ReadyText = CreateActor<FightText>();
		ReadyText->SetFightText("Ready");
	}

	CurLevelPlayer->SetCharacterState(CharacterState::Intro);
}

void KingDiceLevel::FightKingDiceUpdate(float _Delta)
{
	ReadyTime += _Delta;
	if (ReadyTime > 3.0f)
	{
		if ("Attack" != Boss->GetCurState())
		{
			Boss->SetState(KingDiceState::Attack);
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////// //////    Stage Clear    ///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void KingDiceLevel::CheckStageClear()
{
	bool CheckKingDiceDeath = Boss->GetIsDeath();

	if (false == IsStageClear
		&& true == CheckKingDiceDeath)
	{
		IsStageClear = true;
		CreateKnockOut();
		CreateBossExplosion();
	}
}

void KingDiceLevel::CreateKnockOut()
{
	// Knock Out
	KnockOut = CreateActor<FightText>();
	KnockOut->SetFightText("KnockOut");
}

void KingDiceLevel::CreateBossExplosion()
{
	Boss->CreateDeathEffect();
}

void KingDiceLevel::CreateFadeOut(float _Delta)
{
	if (true == IsStageClear)
	{
		StageClearTime += _Delta;
		if (StageClearTime > 5.0f)
		{
			FadeOut->On();
		}
	}
}