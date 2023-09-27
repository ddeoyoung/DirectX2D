#include "PreCompile.h"
#include "Martini.h"

Martini::Martini()
{
}

Martini::~Martini()
{
}


void Martini::Start()
{
	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Martini_Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\TipsyTroop\\Boss\\Martini");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();

	MainRenderer->CreateAnimation("Martini_Idle", "Martini_Idle", 0.05f);
	MainRenderer->ChangeAnimation("Martini_Idle");

	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);

	Transform.SetLocalPosition({ 850 , -700 });
}

void Martini::Update(float _Delta)
{

}

void Martini::ChangeState(MartiniState _State)
{

}

void Martini::StateUpdate(float _Delta)
{

}

void Martini::ChangeAnimationState(const std::string& _StateName)
{

}

void Martini::IdleStart()
{

}

void Martini::IdleUpdate(float _Delta)
{

}

void Martini::AttackStart()
{

}

void Martini::AttackUpdate(float _Delta)
{

}

void Martini::DeathStart()
{

}

void Martini::DeathUpdate(float _Delta)
{

}