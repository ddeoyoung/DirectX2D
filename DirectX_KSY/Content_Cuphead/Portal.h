#pragma once

enum class PortalValue
{
	None,
	ElderKettleHouse,
	Tutorial,
	OverWorld,
	Inkwell_One,
	Inkwell_Three,
	Inkwell_Hell,
	Inkwell_Isle,
	BossStage,
};


// Ό³Έν :
class Portal : public ContentActor
{
public:
	// constrcuter destructer
	Portal();
	~Portal();

	// delete Function
	Portal(const Portal& _Other) = delete;
	Portal(Portal&& _Other) noexcept = delete;
	Portal& operator=(const Portal& _Other) = delete;
	Portal& operator=(Portal&& _Other) noexcept = delete;

	void SetPortalValue(PortalValue _PV)
	{
		PV = _PV;
	}

	bool GetIsPortalOn()
	{
		return IsPortalOn;
	}

	bool GetIsCollision()
	{
		return IsCollision;
	}

	void SetIsPortalOn(bool _bool)
	{
		IsPortalOn = _bool;
	}

	void LevelChange();

	std::shared_ptr<GameEngineSpriteRenderer> GetRenderer()
	{
		return MainRenderer;
	}

	void SetPortalScale(float4 _Scale)
	{
		PortalScale = _Scale;
	}

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> PortalCollision = nullptr;

	PortalValue PV = PortalValue::None;
	bool IsPortalOn = false;
	bool IsCollision = false;
	float4 PortalScale = float4::ZERO;
	void CollisionCheck(float _Delta);

private:

};

