#include "PreCompile.h"
#include "ContentsCore.h"

#include <GameEngineCore/GameEngineGUI.h>

#include "ContentGUI.h"

void ContentsCore::ContentRes()
{
	GameEngineRenderTarget::IsDepth = false;
	GameEngineLevel::IsDebug = false;

	{
		// Content Shader Load
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("ContentsResources");
		Dir.MoveChild("Content_Shader");
		std::vector<GameEngineFile> Files = Dir.GetAllFile({ ".fx" });

		for (size_t i = 0; i < Files.size(); i++)
		{
			GameEngineFile& File = Files[i];
			GameEngineShader::AutoCompile(File);
		}
	}

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

	// IMGUI
	GameEngineGUI::CreateGUIWindow<ContentGUI>("ContentGUI");


	// Shader
	{
		std::shared_ptr<GameEngineMaterial> Mat = GameEngineMaterial::Create("OldFilm");
		Mat->SetVertexShader("OldFilm_VS");
		Mat->SetPixelShader("OldFilm_PS");
		Mat->SetDepthState("AlwaysDepth");
	}
}