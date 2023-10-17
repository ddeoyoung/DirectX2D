#pragma once
#include <GameEngineCore/GameEngineGUI.h>
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class ContentGUI : public GameEngineGUIWindow
{
public:
	// constrcuter destructer
	ContentGUI();
	~ContentGUI();

	// delete Function
	ContentGUI(const ContentGUI& _Other) = delete;
	ContentGUI(ContentGUI&& _Other) noexcept = delete;
	ContentGUI& operator=(const ContentGUI& _Other) = delete;
	ContentGUI& operator=(ContentGUI&& _Other) noexcept = delete;

	void Start() override;
	void OnGUI(GameEngineLevel* _Level, float _DeltaTime) override;

protected:

private:

};

