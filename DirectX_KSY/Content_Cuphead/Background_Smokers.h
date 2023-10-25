#pragma once

// Ό³Έν :
class Background_Smokers : public ContentActor
{
public:
	// constrcuter destructer
	Background_Smokers();
	~Background_Smokers();

	// delete Function
	Background_Smokers(const Background_Smokers& _Other) = delete;
	Background_Smokers(Background_Smokers&& _Other) noexcept = delete;
	Background_Smokers& operator=(const Background_Smokers& _Other) = delete;
	Background_Smokers& operator=(Background_Smokers&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	std::shared_ptr<class GameEngineSpriteRenderer> MainRenderer = nullptr;

private:

};

