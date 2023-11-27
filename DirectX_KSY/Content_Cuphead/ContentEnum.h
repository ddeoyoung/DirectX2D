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
	PlayBack,
	Play,
	PlayFront,
	PlayerShoot,
	Player,
	Frontground,
	FrontgroundObject,
	FrontgroundObject2,
	FrontgroundObject3,
	FrontgroundObject4,
	FrontgroundEffect,
	UI,
	Max,
};

enum class CollisionOrder
{
	Player,
	PlayerAttack,
	PlayerParry,
	Boss,
	BossAttack,
	Monster,
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