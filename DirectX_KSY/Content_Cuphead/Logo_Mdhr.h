#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class Logo_Mdhr : public GameEngineActor
{
public:
	// constrcuter destructer
	Logo_Mdhr();
	~Logo_Mdhr();

	// delete Function
	Logo_Mdhr(const Logo_Mdhr& _Other) = delete;
	Logo_Mdhr(Logo_Mdhr&& _Other) noexcept = delete;
	Logo_Mdhr& operator=(const Logo_Mdhr& _Other) = delete;
	Logo_Mdhr& operator=(Logo_Mdhr&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> Renderer;
};

