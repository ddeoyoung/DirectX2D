#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class Attack_Chips : public GameEngineActor
{
public:
	// constrcuter destructer
	Attack_Chips();
	~Attack_Chips();

	// delete Function
	Attack_Chips(const Attack_Chips& _Other) = delete;
	Attack_Chips(Attack_Chips&& _Other) noexcept = delete;
	Attack_Chips& operator=(const Attack_Chips& _Other) = delete;
	Attack_Chips& operator=(Attack_Chips&& _Other) noexcept = delete;

	void SetChips(float4 _BossPos, const std::string& _ChipType);

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;

private:

};

