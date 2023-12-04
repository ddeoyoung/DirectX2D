#include "PreCompile.h"
#include "GameEngineParticleRenderer.h"
#include "GameEngineStructuredBuffer.h"

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

	UpdateUnit.ShaderResHelper.SetTexture("EngineNoise", "noise_03.jpg");
	UpdateUnit.ShaderResHelper.SetConstantBufferLink("RenderBaseInfo", RenderBaseInfoValue);
	UpdateUnit.ShaderResHelper.SetConstantBufferLink("ParticleUpdateInfo", ParticleUpdateInfoValue);


	ParticleUpdateInfoValue.SpawnRange = 300.0f;

	// �����쿡 �ִ� �Լ��Դϴ�.
	// InterlockedAnd
	// ��ƼŬ������ ���� ���۴� �� ��ƼŬ ���������� ������ �־�� �Ѵٰ� ����
	// New�� ��������ϴ�.
	std::list<std::shared_ptr<GameEngineStructuredBuffer>> Buffer
		= UpdateUnit.ShaderResHelper.SetStructedNew("ParticleinfoBuffer", StructuredBufferType::UAV_INC, Data);
	//	UpdateUnit.ShaderResHelper.SetStructedNew("ParticleShareBuffer", StructuredBufferType::UAV_INC, nullptr, sizeof(ParticleShareData), 1);

		// 

		// ���� ����Ʈ�� �˾Ƽ� �������� �ϴ°̴ϴ�
	GameEngineRenderer::SetMesh("PointMesh");
	GameEngineRenderer::SetMaterial("ParticleRender");

	std::shared_ptr<GameEngineRenderUnit> Unit = CreateAndFindRenderUnit(0);

	Unit->SetRenderMode(RenderMode::Instancing);
	Unit->SetInstancingCount(ParticleUpdateInfoValue.ParticleMaxCount);
	// Unit->ShaderResHelper.SetConstantBufferLink("ParticleUpdateInfo", ParticleUpdateInfoValue);

	// ������ ä�����ִ� �� ��Ʈ��ó�� ���� ��� ��ǻƮ ���̴��� ��Ʈ��ó�� ���۸� �����ؾ� �Ѵ�.
	Unit->ShaderResHelper.SetStructedBufferChange("ParticleinfoRenderBuffer", Buffer.front());

}

void GameEngineParticleRenderer::Update(float _DeltaTime)
{
	RenderBaseInfoValue;

	ParticleUpdateInfoValue.ObjectWorldPos = Transform.GetWorldPosition();

	GameEngineRenderer::Update(_DeltaTime);
	// ������ ��ƼŬ �����͸� ��ǻƮ���̴��� ����ϰ�
	UpdateUnit.Excute();
}

void GameEngineParticleRenderer::Render(GameEngineCamera* _Camera, float _Delta)
{
	GameEngineRenderer::Render(_Camera, _Delta);
}