#pragma once
#include <GameEngineCore\GameEngineActor.h>

// ���� :
class Martini : public GameEngineActor
{
public:
	// constrcuter destructer
	Martini();
	~Martini();

	// delete Function
	Martini(const Martini& _Other) = delete;
	Martini(Martini&& _Other) noexcept = delete;
	Martini& operator=(const Martini& _Other) = delete;
	Martini& operator=(Martini&& _Other) noexcept = delete;

protected:

private:

};

