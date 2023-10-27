#include "PreCompile.h"
#include "Background_Smokers.h"

Background_Smokers::Background_Smokers()
{
}

Background_Smokers::~Background_Smokers()
{
}


void Background_Smokers::Start()
{
	ContentActor::Start();

	// Background
	if (nullptr == GameEngineSprite::Find("kd_cigar_bg_smokers_loop.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\MrWheezy\\StageObject\\Background");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_cigar_bg_smokers_loop.png");
		GameEngineSprite::CreateSingle("kd_cigar_bg_smokers_loop.png");
	}

	MainRenderer = CreateComponent<GameEngineSpriteRenderer>(RenderOrder::Background);
	MainRenderer->SetSprite("kd_cigar_bg_smokers_loop.png");
	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->Transform.SetLocalPosition({ 640.0f , -275.0f });

	MainRenderer->SetSampler("EngineBaseWRAPSampler");

}

void Background_Smokers::Update(float _Delta)
{
	ContentActor::Update(_Delta);

	MainRenderer->RenderBaseInfoValue.VertexUVPlus.X += _Delta * 0.01;
}