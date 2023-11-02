#pragma once

// Ό³Έν :
class FadeAnimation : public ContentActor
{
public:
	// constrcuter destructer
	FadeAnimation();
	~FadeAnimation();

	// delete Function
	FadeAnimation(const FadeAnimation& _Other) = delete;
	FadeAnimation(FadeAnimation&& _Other) noexcept = delete;
	FadeAnimation& operator=(const FadeAnimation& _Other) = delete;
	FadeAnimation& operator=(FadeAnimation&& _Other) noexcept = delete;

	void SetFade(const std::string& _Name);
	bool IsCurAnimationEnd();

protected:
	void Start() override;
	void Update(float _Delta) override;

	void EndCheck();

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;

private:

};

