#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class CigSmoke : public ContentActor
{
public:
	// constrcuter destructer
	CigSmoke();
	~CigSmoke();

	// delete Function
	CigSmoke(const CigSmoke& _Other) = delete;
	CigSmoke(CigSmoke&& _Other) noexcept = delete;
	CigSmoke& operator=(const CigSmoke& _Other) = delete;
	CigSmoke& operator=(CigSmoke&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> Renderer = nullptr;

private:

};

