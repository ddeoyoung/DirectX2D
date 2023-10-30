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

	CheckRouletteSpace();
	ChangeToSubBossStage();

	if (true == IsFightKingDice)
	{
		FightKingDiceStart();
	}
}

void KingDiceLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentLevel::LevelStart(_PrevLevel);

	LevelStartTextureLoad();
	LevelStartTextureSet();

	// Marker
	Roulette_Marker = CreateActor<Marker>(ObjectOrder::Marker);
	
	// Boss
	Boss = CreateActor<KingDice>();
	Boss->On();
	Boss->SetState(KingDiceState::IntroHand);

	// Player
	CurLevelPlayer = CreateActor<Cuphead>();
	CurLevelPlayer->Transform.SetLocalPosition({ 250, -550 });

	// LevelChange
	LevelName = "";
}

void KingDiceLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
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
			Boss->SetIsSafeSpace(true);
			LevelName = "TipsyTroopLevel";
			break;
		case 2:
			SpaceState::Space2;
			Boss->SetIsSafeSpace(true);
			LevelName = "ChipsBettiganLevel";
			break;
		case 3:
			SpaceState::Space3;
			Boss->SetIsSafeSpace(true);
			LevelName = "MrWheezyLevel";
			break;
		case 4:
			SpaceState::SpaceSafe1;
			Boss->SetIsSafeSpace(true);
			break;
		case 5:
			SpaceState::Space4;
			Boss->SetIsSafeSpace(true);
			//LevelName = "PipandDotLevel";
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
		GameEngineCore::ChangeLevel(LevelName);
	}
}

void KingDiceLevel::FightKingDiceStart()
{
	// FightText
	std::shared_ptr<FightText> Ready = CreateActor<FightText>();
	Ready->SetFightText("Ready");

	// Boss
	//Boss->SetState(KingDiceState::);
}

void KingDiceLevel::FightKingDiceUpdate(float _Delta)
{

}