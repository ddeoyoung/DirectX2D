#include "PreCompile.h"
#include "PipandDotLevel.h"

#include "BaseCharacter.h"
#include "Cuphead.h"

#include "FightText.h"


PipandDotLevel::PipandDotLevel()
{
}

PipandDotLevel::~PipandDotLevel()
{
}


void PipandDotLevel::Start()
{
	ContentLevel::Start();
}

void PipandDotLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);
}

void PipandDotLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentLevel::LevelStart(_PrevLevel);

	LevelStartTextureLoad();
	LevelStartTextureSet();

	// FightText
	std::shared_ptr<FightText> Ready = CreateActor<FightText>();
	Ready->SetFightText("Ready");

	// Background
	//std::shared_ptr<Background_Smokers> Background = CreateActor<Background_Smokers>();

	// Pixel Background
	//CurLevelPixelBackground = CreateActor<ContentBackground>();
	//CurLevelPixelBackground->PixelBackgroundInit("kd_cigar_bg_pixel.png");

	// Player
	//CurLevelPlayer = CreateActor<Cuphead>();
	//CurLevelPlayer->Transform.SetLocalPosition({ 250, -400 });

}

void PipandDotLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}