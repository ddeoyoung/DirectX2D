#pragma once

// Ό³Έν :
class BaseMonster : public ContentActor
{
public:
	// constrcuter destructer
	BaseMonster();
	~BaseMonster();

	// delete Function
	BaseMonster(const BaseMonster& _Other) = delete;
	BaseMonster(BaseMonster&& _Other) noexcept = delete;
	BaseMonster& operator=(const BaseMonster& _Other) = delete;
	BaseMonster& operator=(BaseMonster&& _Other) noexcept = delete;

	void HPMinus();

	bool GetIsDeath()
	{
		return IsDeath;
	}

protected:
	int HP = 0;
	bool IsDeath = false;

private:

};

