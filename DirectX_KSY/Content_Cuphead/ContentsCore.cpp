#include "PreCompile.h"
#include "ContentsCore.h"
#include "LogoLevel.h"
#include "TitleLevel.h"
#include "IntroLevel.h"
#include "TutorialLevel.h"
#include "OverWorldLevel.h"
#include "KingDiceLevel.h"
#include "TipsyTroopLevel.h"
#include "ChipsBettiganLevel.h"
#include "OutroLevel.h"

#include <GameEngineCore/GameEngineBlend.h>

ContentsCore::ContentsCore()
{
}

ContentsCore::~ContentsCore()
{
}

void ContentsCore::Start()
{
	ContentRes();
	GameEngineRenderTarget::IsDepth = false;

	GameEngineCore::CreateLevel<LogoLevel>("LogoLevel");
	GameEngineCore::CreateLevel<TitleLevel>("TitleLevel");
	GameEngineCore::CreateLevel<IntroLevel>("IntroLevel");
	GameEngineCore::CreateLevel<TutorialLevel>("TutorialLevel");
	GameEngineCore::CreateLevel<OverWorldLevel>("OverWorldLevel");
	GameEngineCore::CreateLevel<KingDiceLevel>("KingDiceLevel");
	GameEngineCore::CreateLevel<TipsyTroopLevel>("TipsyTroopLevel");
	GameEngineCore::CreateLevel<ChipsBettiganLevel>("ChipsBettiganLevel");
	GameEngineCore::CreateLevel<OutroLevel>("OutroLevel");

	GameEngineCore::ChangeLevel("ChipsBettiganLevel");
}

void ContentsCore::Update(float _Delta)
{
	
}

void ContentsCore::Release()
{
}

void ContentsCore::ContentRes()
{
	// OverRay
	{
		D3D11_BLEND_DESC Desc = {};
		Desc.IndependentBlendEnable = false;
		Desc.RenderTarget[0].BlendEnable = true;
		Desc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

		Desc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
		Desc.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
		Desc.RenderTarget[0].DestBlend = D3D11_BLEND_ONE;

		Desc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
		Desc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ZERO;
		Desc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ONE;

		std::shared_ptr<GameEngineBlend> Blend = GameEngineBlend::Create("OverRay", Desc);
	}

	{
		std::shared_ptr<GameEngineMaterial> Mat = GameEngineMaterial::Create("2DTextureOver");
		Mat->SetVertexShader("TextureShader_VS");
		Mat->SetPixelShader("TextureShader_PS");
		Mat->SetBlendState("OverRay");
	}
}