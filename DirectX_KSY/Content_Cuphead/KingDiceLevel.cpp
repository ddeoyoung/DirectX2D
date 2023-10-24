#include "PreCompile.h"
#include "KingDiceLevel.h"

#include "ContentBackground.h"
#include "BaseCharacter.h"
#include "Cuphead.h"
#include "KingDice.h"
#include "Marker.h"

#include "FadeAnimation.h"

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
	std::string BossState = Boss->GetCurState();

	if (true == Roulette_Marker->GetIsSpinEnd() && BossState == "Curious")
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
			break;
		case 1:
			SpaceState::Space1;
			LevelName = "TipsyTroopLevel";
			break;
		case 2:
			SpaceState::Space2;
			LevelName = "ChipsBettiganLevel";
			break;
		case 3:
			SpaceState::Space3;
			LevelName = "ChipsBettiganLevel";
			break;
		case 4:
			SpaceState::SpaceSafe1;
			break;
		case 5:
			SpaceState::Space4;
			break;
		case 6:
			SpaceState::Space5;
			break;
		case 7:
			SpaceState::Space6;
			break;
		case 8:
			SpaceState::SpaceSafe2;
			break;
		case 9:
			SpaceState::Space7;
			break;
		case 10:
			SpaceState::Space8;
			break;
		case 11:
			SpaceState::Space9;
			break;
		case 12:
			SpaceState::SpaceSafe3;
			break;
		case 13:
			SpaceState::SpaceStartOver;
			break;
		case 14:
			SpaceState::SpaceFinish;
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