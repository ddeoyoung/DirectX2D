#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class KingDiceTable : public GameEngineActor
{
public:
	static KingDiceTable* KDTable;

public:
	// constrcuter destructer
	KingDiceTable();
	~KingDiceTable();

	// delete Function
	KingDiceTable(const KingDiceTable& _Other) = delete;
	KingDiceTable(KingDiceTable&& _Other) noexcept = delete;
	KingDiceTable& operator=(const KingDiceTable& _Other) = delete;
	KingDiceTable& operator=(KingDiceTable&& _Other) noexcept = delete;

	GameEngineColor GetColor(float4 _Pos, GameEngineColor _DefaultColor = {255, 255, 255, 255});

protected:
	void Start() override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> Renderer;
};

