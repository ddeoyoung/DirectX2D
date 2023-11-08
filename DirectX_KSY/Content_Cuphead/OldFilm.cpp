#include "PreCompile.h"
#include "OldFilm.h"
#include <GameEngineCore/GameEngineCore.h>

OldFilm::OldFilm()
{
}

OldFilm::~OldFilm()
{
}

void OldFilm::Start()
{
	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("OldFilm"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Content_Shader");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	std::shared_ptr<GameEngineRenderTarget> Target = GameEngineCore::GetCurLevel()->GetMainCamera()->GetCameraAllRenderTarget();

	if (nullptr != Target)
	{
		ResultTarget = Target->CreateChildRenderTarget({ 0 });
	}

	EffectUnit.SetMesh("fullrect");
	EffectUnit.SetMaterial("OldFilm");
	FilmSprite = GameEngineSprite::Find("OldFilm");
	EffectUnit.ShaderResHelper.SetSampler("Tex0Sampler", "POINT");
}

void OldFilm::EffectProcess(float _DeltaTime)
{
	ResultTarget->Setting();

	EffectUnit.ShaderResHelper.SetTexture("Tex0", FilmSprite->GetSpriteData(CurIndex).Texture);
	
	Time += _DeltaTime;
	if (0.02f <= Time)
	{
		Time = 0.0f;
		++CurIndex;
	}

	if (CurIndex >= FilmSprite->GetSpriteCount())
	{
		CurIndex = 0;
	}

	EffectUnit.Render();

	GameEngineRenderTarget::RenderTargetReset();
}