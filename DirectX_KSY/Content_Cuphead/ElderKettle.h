#pragma once

// ���� :
class ElderKettle : public ContentActor
{
public:
	// constrcuter destructer
	ElderKettle();
	~ElderKettle();

	// delete Function
	ElderKettle(const ElderKettle& _Other) = delete;
	ElderKettle(ElderKettle&& _Other) noexcept = delete;
	ElderKettle& operator=(const ElderKettle& _Other) = delete;
	ElderKettle& operator=(ElderKettle&& _Other) noexcept = delete;

protected:

private:

};
