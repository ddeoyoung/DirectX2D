#pragma once
#include "GameEngineActor.h"
#include <map>
#include <list>
#include <memory>

// 카메라도 Actor

// 설명 :
class GameEngineCamera : public GameEngineActor
{
	friend class GameEngineRenderer;
	friend class GameEngineActor;
	friend class GameEngineLevel;

public:
	// constrcuter destructer
	GameEngineCamera();
	~GameEngineCamera();

	// delete Function
	GameEngineCamera(const GameEngineCamera& _Other) = delete;
	GameEngineCamera(GameEngineCamera&& _Other) noexcept = delete;
	GameEngineCamera& operator=(const GameEngineCamera& _Other) = delete;
	GameEngineCamera& operator=(GameEngineCamera&& _Other) noexcept = delete;

protected:

private:
	// 이전과 똑같이 카메라가 랜더러를 관리한다.
	std::map<int, std::list<std::shared_ptr<class GameEngineRenderer>>> Renderers;

};

