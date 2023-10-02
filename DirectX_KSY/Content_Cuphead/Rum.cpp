#include "PreCompile.h"
#include "Rum.h"

Rum::Rum()
{
}

Rum::~Rum()
{
}


void Rum::Start()
{
	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Rum_Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\TipsyTroop\\Boss\\Rum");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();

	MainRenderer->CreateAnimation("Rum_Idle", "Rum_Idle", 0.06f);
	MainRenderer->CreateAnimation("Rum_Attack", "Rum_Attack", 0.06f);
	MainRenderer->CreateAnimation("Rum_Death", "Rum_Death", 0.05f);
	MainRenderer->ChangeAnimation("Rum_Idle");

	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::RightBottom);

	Transform.SetLocalPosition({ 1100 , -700 });
}

void Rum::Update(float _Delta)
{

}

void Rum::ChangeState(RumState _State)
{

}

void Rum::StateUpdate(float _Delta)
{

}

void Rum::ChangeAnimationState(const std::string& _StateName)
{

}

void Rum::IdleStart()
{

}

void Rum::IdleUpdate(float _Delta)
{

}

void Rum::AttackStart()
{

}

void Rum::AttackUpdate(float _Delta)
{

}

void Rum::DeathStart()
{

}

void Rum::DeathUpdate(float _Delta)
{

}