#pragma once

enum class PortalValue
{
	None,
	ElderKettleHouse,
	Tutorial,
	OverWorld,
};

// Ό³Έν :
class PortalDoor : public ContentActor
{
public: 
	// constrcuter destructer
	PortalDoor();
	~PortalDoor();

	// delete Function
	PortalDoor(const PortalDoor& _Other) = delete;
	PortalDoor(PortalDoor&& _Other) noexcept = delete;
	PortalDoor& operator=(const PortalDoor& _Other) = delete;
	PortalDoor& operator=(PortalDoor&& _Other) noexcept = delete;

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

private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> PortalCollision = nullptr;

	PortalValue PV = PortalValue::None;
	bool IsPortalOn = false;

	void CollisionCheck(float _Delta);
};

