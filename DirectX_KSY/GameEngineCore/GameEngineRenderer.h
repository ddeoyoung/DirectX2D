#pragma once
#include "GameEngineObject.h"
#include "GameEngineComponent.h"

// 설명 : GameEngineRenderer에게 Order는 랜더링 되는 순서를 의미합니다.
class GameEngineRenderer : public GameEngineComponent
{
	friend class GameEngineCamera;

public:
	// constrcuter destructer
	GameEngineRenderer();
	~GameEngineRenderer();

	// delete Function
	GameEngineRenderer(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer(GameEngineRenderer&& _Other) noexcept = delete;
	GameEngineRenderer& operator=(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer& operator=(GameEngineRenderer&& _Other) noexcept = delete;

	// 카메라의 경우에는 
	// 이게 무조건 호출되야 합니다.
	// 하나의 랜더러를 여러개의 여러개의 카메라가 바라볼 수 있다.
	void SetViewCameraSelect(int _Order);

protected:
	void Start();
	virtual void Render(GameEngineCamera* _Camera, float _Delta);

private:
	std::map<class GameEngineCamera*, int> ViewInfo;
	std::shared_ptr<class GameEngineInputLayOut> LayOut = nullptr;

};

