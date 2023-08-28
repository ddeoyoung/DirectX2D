#pragma once
#include "GameEngineObject.h"
#include "GameEngineComponent.h"

// ���� : GameEngineRenderer���� Order�� ������ �Ǵ� ������ �ǹ��մϴ�.
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

	// ī�޶��� ��쿡�� 
	// �̰� ������ ȣ��Ǿ� �մϴ�.
	// �ϳ��� �������� �������� �������� ī�޶� �ٶ� �� �ִ�.
	void SetViewCameraSelect(int _Order);

protected:
	void Start();
	virtual void Render(GameEngineCamera* _Camera, float _Delta);

private:
	std::map<class GameEngineCamera*, int> ViewInfo;
	std::shared_ptr<class GameEngineInputLayOut> LayOut = nullptr;

};

