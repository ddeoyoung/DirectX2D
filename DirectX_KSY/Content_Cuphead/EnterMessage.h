#pragma once

// Ό³Έν :
class EnterMessage : public ContentActor
{
public:
	// constrcuter destructer
	EnterMessage();
	~EnterMessage();

	// delete Function
	EnterMessage(const EnterMessage& _Other) = delete;
	EnterMessage(EnterMessage&& _Other) noexcept = delete;
	EnterMessage& operator=(const EnterMessage& _Other) = delete;
	EnterMessage& operator=(EnterMessage&& _Other) noexcept = delete;

	bool InteractionCheck();
	void SetBubbleCollisionPos(float4 _Pos)
	{
		BubbleCollision->Transform.SetLocalPosition(_Pos);
	}

protected:
	void Start() override;
	void Update(float _Delta) override;


private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
	std::shared_ptr<class GameEngineCollision> BubbleCollision = nullptr;
};

