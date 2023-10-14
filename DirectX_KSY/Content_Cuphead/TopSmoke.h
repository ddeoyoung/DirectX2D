#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class TopSmoke : public ContentActor
{
public:
	// constrcuter destructer
	TopSmoke();
	~TopSmoke();

	// delete Function
	TopSmoke(const TopSmoke& _Other) = delete;
	TopSmoke(TopSmoke&& _Other) noexcept = delete;
	TopSmoke& operator=(const TopSmoke& _Other) = delete;
	TopSmoke& operator=(TopSmoke&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> Renderer = nullptr;
private:

};

