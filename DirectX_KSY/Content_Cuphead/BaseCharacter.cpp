#include "PreCompile.h"
#include "BaseCharacter.h"

BaseCharacter::BaseCharacter()
{
}

BaseCharacter::~BaseCharacter()
{
}

void BaseCharacter::Start()
{
	if (nullptr == GameEngineSprite::Find("Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Cuphead");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();
	MainRenderer->CreateAnimation("Idle", "Idle");
	MainRenderer->CreateAnimation("Run_Normal", "Normal");
	MainRenderer->CreateAnimation("Run_Shoot", "Shoot");
	MainRenderer->ChangeAnimation("Run_Normal");
	MainRenderer->AutoSpriteSizeOn();

	MainRenderer->Transform.SetLocalPosition({250, -550});
}

void BaseCharacter::Update(float _Delta)
{

}