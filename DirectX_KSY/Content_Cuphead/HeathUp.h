#pragma once

// Ό³Έν :
class HeathUp : public ContentActor
{
public:
	// constrcuter destructer
	HeathUp();
	~HeathUp();

	// delete Function
	HeathUp(const HeathUp& _Other) = delete;
	HeathUp(HeathUp&& _Other) noexcept = delete;
	HeathUp& operator=(const HeathUp& _Other) = delete;
	HeathUp& operator=(HeathUp&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
private:

};

