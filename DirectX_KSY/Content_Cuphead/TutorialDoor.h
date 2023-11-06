#pragma once
#include "Portal.h"

// Ό³Έν :
class TutorialDoor : public Portal
{
public:
	// constrcuter destructer
	TutorialDoor();
	~TutorialDoor();

	// delete Function
	TutorialDoor(const TutorialDoor& _Other) = delete;
	TutorialDoor(TutorialDoor&& _Other) noexcept = delete;
	TutorialDoor& operator=(const TutorialDoor& _Other) = delete;
	TutorialDoor& operator=(TutorialDoor&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:

};

