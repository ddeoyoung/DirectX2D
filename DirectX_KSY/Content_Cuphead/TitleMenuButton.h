#pragma once
#include <GameEngineCore\GameEngineActor.h>

enum class MenuButtonType
{
	None,
	Start,
	Exit,
};

// Ό³Έν :
class TitleMenuButton : public ContentActor
{
public:
	// constrcuter destructer
	TitleMenuButton();
	~TitleMenuButton();

	// delete Function
	TitleMenuButton(const TitleMenuButton& _Other) = delete;
	TitleMenuButton(TitleMenuButton&& _Other) noexcept = delete;
	TitleMenuButton& operator=(const TitleMenuButton& _Other) = delete;
	TitleMenuButton& operator=(TitleMenuButton&& _Other) noexcept = delete;

	bool GetIsLevelChange()
	{
		return IsLevelChange;
	}

	bool GetIsGameExit()
	{
		return IsGameExit;
	}

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> StartRenderer;
	std::shared_ptr<class GameEngineSpriteRenderer> ExitRenderer;

	bool IsLevelChange = false;
	bool IsGameExit = false;
	MenuButtonType ButtonType = MenuButtonType::None;
	MenuButtonType CurButtonType = MenuButtonType::None;

	void SelectButton();
};

