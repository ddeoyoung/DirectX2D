#pragma once

// Ό³Έν :
class GenericExplosion : public ContentActor
{
public:
	// constrcuter destructer
	GenericExplosion();
	~GenericExplosion();

	// delete Function
	GenericExplosion(const GenericExplosion& _Other) = delete;
	GenericExplosion(GenericExplosion&& _Other) noexcept = delete;
	GenericExplosion& operator=(const GenericExplosion& _Other) = delete;
	GenericExplosion& operator=(GenericExplosion&& _Other) noexcept = delete;

	void EndCheck();

protected:
	void Start() override;
	void Update(float _Delta) override;

	void SetRandom();

private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
};

