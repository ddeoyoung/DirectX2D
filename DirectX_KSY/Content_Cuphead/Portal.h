#pragma once

enum class PortalValue
{
	None,
	ElderKettleHouse,
	Tutorial,
	OverWorld,
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

	void LevelChange();


protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> PortalCollision = nullptr;

	PortalValue PV = PortalValue::None;
	bool IsPortalOn = false;

	void CollisionCheck(float _Delta);

private:

};

