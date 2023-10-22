#pragma once
#include <GameEngineCore\GameEngineActor.h>

// Ό³Έν :
class ContentActor : public GameEngineActor
{
public:
	// constrcuter destructer
	ContentActor();
	~ContentActor();

	// delete Function
	ContentActor(const ContentActor& _Other) = delete;
	ContentActor(ContentActor&& _Other) noexcept = delete;
	ContentActor& operator=(const ContentActor& _Other) = delete;
	ContentActor& operator=(ContentActor&& _Other) noexcept = delete;


	void SpriteInit(const std::string_view& _Texture,  const float4 _Position, int _Order = 0, float _ScaleRatio = 1.0f);

	template<typename EnumType>
	void SpriteInit(const std::string_view& _Texture, const float4 _Position, EnumType _Order = 0, float _ScaleRatio = 1.0f)
	{
		return SpriteInit(_Texture, _Position, static_cast<int>(_Order), _ScaleRatio);
	}

	void AnimationInit();

protected:
	void Start() override;
	void Update(float _Delta) override;

	void CreateParrySpark();

private:
	std::shared_ptr<GameEngineSpriteRenderer> StaticRenderer = nullptr;
	std::shared_ptr<class ParrySpark_Object> ParryEffect = nullptr;
};

