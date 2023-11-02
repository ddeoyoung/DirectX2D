#pragma once

// Ό³Έν :
class MusicNote : public ContentActor
{
public:
	// constrcuter destructer
	MusicNote();
	~MusicNote();

	// delete Function
	MusicNote(const MusicNote& _Other) = delete;
	MusicNote(MusicNote&& _Other) noexcept = delete;
	MusicNote& operator=(const MusicNote& _Other) = delete;
	MusicNote& operator=(MusicNote&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	void SetRandomNote();

private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
};

