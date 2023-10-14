#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class Cuphead_And_Mugman : public ContentActor
{
public:
	// constrcuter destructer
	Cuphead_And_Mugman();
	~Cuphead_And_Mugman();

	// delete Function
	Cuphead_And_Mugman(const Cuphead_And_Mugman& _Other) = delete;
	Cuphead_And_Mugman(Cuphead_And_Mugman&& _Other) noexcept = delete;
	Cuphead_And_Mugman& operator=(const Cuphead_And_Mugman& _Other) = delete;
	Cuphead_And_Mugman& operator=(Cuphead_And_Mugman&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> Renderer;
};

