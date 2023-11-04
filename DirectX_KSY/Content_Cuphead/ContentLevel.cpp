#include "PreCompile.h"
#include "ContentLevel.h"

#include "FadeAnimation.h"

ContentLevel::ContentLevel()
{
}

ContentLevel::~ContentLevel()
{
}

ContentLevel* ContentLevel::CurLevel = nullptr;

void ContentLevel::Start()
{
	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	GameEngineInput::AddInputObject(this);
}

void ContentLevel::Update(float _Delta)
{

}

void ContentLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	CurLevel = this;

	// UI - Fade In
	FadeIn = CreateActor<FadeAnimation>(RenderOrder::Max);
	FadeIn->SetFade("In");
}

void ContentLevel::LevelEnd(GameEngineLevel* _NextLevel)
{

}