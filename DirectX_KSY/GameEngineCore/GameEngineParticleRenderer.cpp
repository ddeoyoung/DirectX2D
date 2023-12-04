#include "PreCompile.h"
#include "GameEngineParticleRenderer.h"

GameEngineParticleRenderer::GameEngineParticleRenderer()
{
}

GameEngineParticleRenderer::~GameEngineParticleRenderer()
{

}

void GameEngineParticleRenderer::Start()
{
	GameEngineRenderer::Start();

	UpdateUnit.GroupX = 128;

	std::vector<ParticleInfoData> Data;

	Data.resize(ParticleUpdateInfoValue.ParticleMaxCount);

	for (size_t i = 0; i < ParticleUpdateInfoValue.ParticleMaxCount; i++)
	{
		Data[i].CurTime = 0.0f;
		Data[i].MaxTime = ParticleUpdateInfoValue.MaxLife;
		Data[i].Dir = float4::ZERO;
		Data[i].RelativePos = float4::ZERO;
		Data[i].Speed = 100.0f;
		// �� �׾��ִ� ����
		Data[i].iActive = 0;
	}

	UpdateUnit.SetComputeShader("ParticleUpdate_CS");

	// UpdateUnit.ShaderResHelper.SetConstantBufferLink("ParticleUpdateInfo", ParticleUpdateInfoValue);

	// �����쿡 �ִ� �Լ��Դϴ�.
	// InterlockedAnd
	UpdateUnit.ShaderResHelper.SetStructedNew("ParticleinfoBuffer", StructuredBufferType::UAV_INC, Data);
	UpdateUnit.ShaderResHelper.SetStructedNew("ParticleShareBuffer", StructuredBufferType::UAV_INC, nullptr, sizeof(ParticleShareData), 1);

	// ���� ����Ʈ�� �˾Ƽ� �������� �ϴ°̴ϴ�
	// GameEngineRenderer::SetMesh("Rect");
	// GameEngineRenderer::SetMaterial("2DTexture");
}

void GameEngineParticleRenderer::Update(float _DeltaTime)
{
	// ������ ��ƼŬ �����͸� ��ǻƮ���̴��� ����ϰ�
	UpdateUnit.Excute();
}

void GameEngineParticleRenderer::Render(GameEngineCamera* _Camera, float _Delta)
{

}