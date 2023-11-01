#pragma once

// Ό³Έν :
class Attack_Card
{
public:
	// constrcuter destructer
	Attack_Card();
	~Attack_Card();

	// delete Function
	Attack_Card(const Attack_Card& _Other) = delete;
	Attack_Card(Attack_Card&& _Other) noexcept = delete;
	Attack_Card& operator=(const Attack_Card& _Other) = delete;
	Attack_Card& operator=(Attack_Card&& _Other) noexcept = delete;

protected:

private:

};

