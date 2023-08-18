#pragma once

// 다이렉트x의 목적은 뭐다.
// 그래픽카드를 이용해서 3D 연산을 대신 맡기는것.
// 그래픽카드란 3D연산을 위한 완전히 최적화된 연산장치이다.
// 픽셀개수만큼의 동시연산이 가능하다. 1+1  동시에 1280 x 720
// 우리가 이걸 C++로짜면
// for(int i = 0; i < 1280 x 720 ; ++i)
// {
// }

// 설명 :
class GameEngineDevice
{
public:
	// constrcuter destructer
	GameEngineDevice();
	~GameEngineDevice();

	// delete Function
	GameEngineDevice(const GameEngineDevice& _Other) = delete;
	GameEngineDevice(GameEngineDevice&& _Other) noexcept = delete;
	GameEngineDevice& operator=(const GameEngineDevice& _Other) = delete;
	GameEngineDevice& operator=(GameEngineDevice&& _Other) noexcept = delete;

	void Initiallize(const class GameEngineWindow& _Window);


protected:

private:
	IDXGIAdapter* GetHighPerformanceAdapter();

	// 그래픽카드의 메모리관련 접근 권한 인터페이스
	// Ex) 이미지 정점를 만들고 지울 수 있는 권한
	ID3D11Device* Device = nullptr;

	// 그래픽카드의 연산(렌더링)관련 접근 권한 인터페이스
	// Ex) 로드된 이미지나 만들어진 정점을 화면에 렌더링
	ID3D11DeviceContext* Context = nullptr;

	// 화면 출력 처리용 인터페이스
	IDXGISwapChain* SwapChain = nullptr;

	void CreateSwapChain();
};

