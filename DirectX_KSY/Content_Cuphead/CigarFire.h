#pragma once

// Ό³Έν :
class CigarFire : public ContentActor
{
public:
	// constrcuter destructer
	CigarFire();
	~CigarFire();

	// delete Function
	CigarFire(const CigarFire& _Other) = delete;
	CigarFire(CigarFire&& _Other) noexcept = delete;
	CigarFire& operator=(const CigarFire& _Other) = delete;
	CigarFire& operator=(CigarFire&& _Other) noexcept = delete;

	void SetFireTypeAndPos(const std::string& _Type, float4 _Pos);

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;
private:

};

