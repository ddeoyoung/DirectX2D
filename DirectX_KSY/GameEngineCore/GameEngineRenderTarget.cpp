#include "PreCompile.h"
#include "GameEngineRenderTarget.h"
#include "GameEngineCore.h"

bool GameEngineRenderTarget::IsDepth = true;

GameEngineRenderTarget::GameEngineRenderTarget()
{
}

GameEngineRenderTarget::~GameEngineRenderTarget()
{
}


// ���̷�Ʈ���� �������� �ϰ� �츮�� �ᱹ device�� ���ؽ�Ʈ��
void GameEngineRenderTarget::Clear()
{
	for (size_t i = 0; i < RTV.size(); i++)
	{
		GameEngineCore::GetContext()->ClearRenderTargetView(RTV[i], ClearColor[i].Arr1D);
	}

	ID3D11DepthStencilView* DSV = DepthTexture != nullptr ? DepthTexture->GetDSV() : nullptr;

	if (nullptr != DSV)
	{
		GameEngineCore::GetContext()->ClearDepthStencilView(DSV, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
	}
}

void GameEngineRenderTarget::Setting()
{
	ID3D11DepthStencilView* DSV = DepthTexture != nullptr ? DepthTexture->GetDSV() : nullptr;

	if (0 >= RTV.size())
	{
		MsgBoxAssert("��������� ���� ����Ÿ���� �����Ϸ��� �߽��ϴ�.");
		return;
	}

	if (false == IsDepth)
	{
		DSV = nullptr;
	}

	GameEngineCore::GetContext()->OMSetRenderTargets(static_cast<UINT>(RTV.size()), &RTV[0], DSV);
}

void GameEngineRenderTarget::AddNewTexture(DXGI_FORMAT _Format, float4 _Scale, float4 _Color)
{
	D3D11_TEXTURE2D_DESC Desc = { 0 };
	Desc.ArraySize = 1;
	Desc.Width = _Scale.uiX();
	Desc.Height = _Scale.uiY();
	Desc.Format = _Format;
	Desc.SampleDesc.Count = 1;
	Desc.SampleDesc.Quality = 0;
	Desc.MipLevels = 1;
	// ����Ʈ
	// �� �ؽ�ó�� �޸𸮸� �׷���ī�尡 ������ �ض�.
	Desc.Usage = D3D11_USAGE_DEFAULT;
	Desc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_RENDER_TARGET | D3D11_BIND_FLAG::D3D11_BIND_SHADER_RESOURCE;
	// �뵵 ����Ÿ������ ����ϱ� ���ؼ� �����.
	// D3D11_BIND_SHADER_RESOURCE �ؽ�ó�� ���̴��� �����Ҽ� �ְ� �ϱ� ���ؼ� �����.

	std::shared_ptr<GameEngineTexture> Tex = GameEngineTexture::Create(Desc);
	Textures.push_back(Tex);

	// ����Ʈ�� ����
	D3D11_VIEWPORT ViewPortData;
	ViewPortData.TopLeftX = 0;
	ViewPortData.TopLeftY = 0;
	ViewPortData.Width = static_cast<float>(_Scale.uiX());
	ViewPortData.Height = static_cast<float>(_Scale.uiY());
	ViewPortData.MinDepth = 0.0f;
	ViewPortData.MaxDepth = 1.0f;

	RTV.push_back(Tex->GetRTV());
	SRV.push_back(Tex->GetSRV());
	ClearColor.push_back(_Color);
	ViewPort.push_back(ViewPortData);

}

void GameEngineRenderTarget::CreateDepthTexture(int _Index/* = 0*/)
{
	// �ؽ�ó�� ���� ����� ù��° �۾�
	D3D11_TEXTURE2D_DESC Desc = { 0, };

	// �ؽ�ó�� 3�������� ������̳��ε�.
	Desc.ArraySize = 1;

	Desc.Width = Textures[_Index]->GetScale().uiX();
	Desc.Height = Textures[_Index]->GetScale().uiY();

	// 0~���� 1������ float�̱� ������. 
	// 1����Ʈ�� ����� 24��Ʈ float�� ����ϴ�.
	// ���� 8��Ʈ�� ���ٽ��̶�� ������ ����ϴµ� ���� ����帮�ڽ��ϴ�.
	Desc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;

	Desc.SampleDesc.Count = 1;
	Desc.SampleDesc.Quality = 0;

	Desc.MipLevels = 1;
	// �׷���ī�忡 �־����.
	Desc.Usage = D3D11_USAGE_DEFAULT;

	Desc.CPUAccessFlags = 0;
	Desc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_DEPTH_STENCIL;
	DepthTexture = GameEngineTexture::Create(Desc);
}