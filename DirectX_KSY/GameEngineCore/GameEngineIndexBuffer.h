#pragma once
#include "GameEngineDirectBuffer.h"

// Ό³Έν :
class GameEngineIndexBuffer :
	public GameEngineResources<GameEngineIndexBuffer>, public GameEngineDirectBuffer
{
	friend class GameEngineInputLayOut;

public:
	// constrcuter destructer
	GameEngineIndexBuffer();
	~GameEngineIndexBuffer();

	// delete Function
	GameEngineIndexBuffer(const GameEngineIndexBuffer& _Other) = delete;
	GameEngineIndexBuffer(GameEngineIndexBuffer&& _Other) noexcept = delete;
	GameEngineIndexBuffer& operator=(const GameEngineIndexBuffer& _Other) = delete;
	GameEngineIndexBuffer& operator=(GameEngineIndexBuffer&& _Other) noexcept = delete;

	static std::shared_ptr<GameEngineIndexBuffer> Create(const std::string_view& _Name, const std::vector<unsigned int>& _Data)
	{
		std::shared_ptr<GameEngineIndexBuffer> Res = GameEngineResources::CreateRes(_Name);
		Res->ResCreate(&_Data[0], _Data.size());
		return nullptr;
	}

	void Setting();

protected:

private:
	const class GameEngineInputLayOutInfo* VertexInfoPtr;

	void ResCreate(const void* _Data, size_t _IndexCount);

	DXGI_FORMAT Format = DXGI_FORMAT::DXGI_FORMAT_R32_UINT;
	UINT IndexSize = 4;
	UINT IndexCount = 0;
	UINT Offset = 0;
};


