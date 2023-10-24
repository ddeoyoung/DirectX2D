#pragma once

enum class RenderOrder
{
	Background,
	BackgroundObject,
	PlayEffect,
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

enum class ObjectOrder
{
	None,
	Marker,
};