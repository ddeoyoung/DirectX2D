#pragma once

// Ό³Έν :
class JumpDust : public ContentActor
{
public:
	// constrcuter destructer
	JumpDust();
	~JumpDust();

	// delete Function
	JumpDust(const JumpDust& _Other) = delete;
	JumpDust(JumpDust&& _Other) noexcept = delete;
	JumpDust& operator=(const JumpDust& _Other) = delete;
	JumpDust& operator=(JumpDust&& _Other) noexcept = delete;

	void EndCheck();

protected:
	void Start() override;
	void Update(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
};

