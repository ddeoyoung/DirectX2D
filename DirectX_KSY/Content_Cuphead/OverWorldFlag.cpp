#include "PreCompile.h"
#include "OverWorldFlag.h"

OverWorldFlag::OverWorldFlag()
{
}

OverWorldFlag::~OverWorldFlag()
{
}


void OverWorldFlag::Start()
{
	Portal::Start();

	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Flag_Start"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\OverWorld\\OverWorld_Flag");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	//MainRenderer->SetOrder(RenderOrder::Play);
	MainRenderer->CreateAnimation("Flag_Start", "Flag_Start", 0.05f, -1, -1, false);
	MainRenderer->SetEndEvent("Flag_Start", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Flag_Loop");
		});
	MainRenderer->CreateAnimation("Flag_Loop", "Flag_Loop", 0.05f);
	MainRenderer->ChangeAnimation("Flag_Start");
	MainRenderer->SetRenderOrder(RenderOrder::Play);
	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->Off();


	PortalCollision->Transform.SetLocalScale({ 70, 80 });


	Collision = CreateComponent<GameEngineCollision>(CollisionOrder::NPC);
	Collision->SetCollisionType(ColType::AABBBOX2D);
	Collision->Transform.SetLocalScale({ 500, 500 });
	Collision->Transform.SetLocalPosition({ 0, 0 });
}

void OverWorldFlag::Update(float _Delta)
{
	Portal::Update(_Delta);


	if (false == IsFlagUp)
	{
		bool Check = Collision->Collision(CollisionOrder::Player);
		if (true == Check)
		{
			MainRenderer->On();
			MainRenderer->ChangeAnimation("Flag_Start");
			IsFlagUp = true;
		}
	}
}
