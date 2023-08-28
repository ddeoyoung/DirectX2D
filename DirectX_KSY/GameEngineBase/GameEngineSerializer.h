#pragma once
#include <vector>

// 실제적으로 컴퓨터의 모든 데이터는 바이트 덩어리라고 할 수 있다.
// 그 바이트 덩어리를 내가 원하는 만큼 내가 원하는 양으로 
// 읽어들이거나 컨트롤 할 수 있게 만들어주는 클래스다.

// 설명 :
class GameEngineSerializer
{
public:
	// constrcuter destructer
	GameEngineSerializer();
	~GameEngineSerializer();

	//// delete Function
	//GameEngineSerializer(const GameEngineSerializer& _Other) = delete;
	//GameEngineSerializer(GameEngineSerializer&& _Other) noexcept = delete;
	//GameEngineSerializer& operator=(const GameEngineSerializer& _Other) = delete;
	//GameEngineSerializer& operator=(GameEngineSerializer&& _Other) noexcept = delete;

	void BufferResize(size_t _BufferSize)
	{
		Data.resize(_BufferSize);
	}

	size_t GetBufferSize()
	{
		return Data.size();
	}

	template<typename PtrType>
	PtrType* GetDataPtr()
	{
		return reinterpret_cast<PtrType*>(&Data[0]);
	}

protected:

private:
	std::vector<char> Data;
};
