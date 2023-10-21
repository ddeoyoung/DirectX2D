#pragma once

enum class RenderOrder
{
	Background,
	BackgroundObject,
	PlayerShoot,
	Play,
	Frontground,
	FrontgroundObject,
	Max,
};

enum class CollisionOrder
{
	Player,
	PlayerAttack,
	Boss,
	BossAttack,
	ParryObject,
};