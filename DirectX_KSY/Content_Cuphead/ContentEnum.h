#pragma once

enum class RenderOrder
{
	Background,
	BackgroundObject,
	BackgroundObject2,
	BackgroundObject3,
	BackgroundObject4,
	BackgroundEffect,
	PlayEffect,
	PlayerShoot,
	PlayBack,
	Play,
	PlayFront,
	Frontground,
	FrontgroundObject,
	FrontgroundObject2,
	FrontgroundObject3,
	FrontgroundObject4,
	FrontgroundEffect,
	Max,
};

enum class CollisionOrder
{
	Player,
	PlayerAttack,
	Boss,
	BossAttack,
	ParryObject,
	NPC,
	Message,
	ShootObject,
	Portal,
};

enum class ObjectOrder
{
	None,
	Marker,
};