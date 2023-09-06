#include "PreCompile.h"
#include "PlayLevel.h"

#include "KingDiceBackground.h"
#include "KingDiceTable.h"
#include "BaseCharacter.h"
#include "Cuphead.h"

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::Start()
{

}

void PlayLevel::Update(float _Delta)
{

}

void PlayLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	std::shared_ptr<KingDiceBackground> Background = CreateActor<KingDiceBackground>();
	std::shared_ptr<KingDiceTable> Table = CreateActor<KingDiceTable>();

	std::shared_ptr<BaseCharacter> Character = CreateActor<Cuphead>();

	Character->Transform.SetLocalPosition({ 250, -550 });
}

void PlayLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}