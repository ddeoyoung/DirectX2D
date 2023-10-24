#pragma once

enum class MarkerState
{
	None,
	Idle,
	Spin,
};

#define SPINSPEED 10.0f

// Ό³Έν :
class Marker : public ContentActor
{
public:
	// constrcuter destructer
	Marker();
	~Marker();

	// delete Function
	Marker(const Marker& _Other) = delete;
	Marker(Marker&& _Other) noexcept = delete;
	Marker& operator=(const Marker& _Other) = delete;
	Marker& operator=(Marker&& _Other) noexcept = delete;

	static bool IsSpinEnd;

	int GetCurRouletteSpace()
	{
		return CurRouletteSpace;
	}

	bool GetIsSpinEnd()
	{
		return IsSpinEnd;
	}

protected:
	void ChangeState(MarkerState _State);
	void StateUpdate(float _Delta);
	void ChangeAnimationState(const std::string& _StateName);
	
	void IdleStart();
	void IdleUpdate(float _Delta);

	void SpinStart();
	void SpinUpdate(float _Delta);

	void SetRouletteMarker();
	void MoveMarker(float4 _Delta);

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;

	std::string CurState = "";
	MarkerState State = MarkerState::None;
	std::vector<float4> RouletteSpace;
	int CurRouletteSpace = 0;

private:
	int CurCount = 0;
	int SpinCount = 0;
	bool IsSpinStart = false;
};

