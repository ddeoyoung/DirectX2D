#pragma once

enum class ActorDir
{
	None,
	Left,
	Right,
	Up,
	Down,
};

enum class CharacterState
{
	None,
	Idle,
	Run,
	RunShoot,
	Aim,
	Shoot,
	Duck,
	DuckIdle,
	DuckShoot,
	Hit,
	Dash,
	Jump,
	Fall,
	Parry,
	Intro,
	Ghost,
	Death,
	Max,
};

enum class AttackDir
{
	None,
	Left_Up,
	Left_Diagonal_Up,
	Left_Straight,
	Left_Diagonal_Down,
	Left_Down,
	Right_Up,
	Right_Diagonal_Up,
	Right_Straight,
	Right_Diagonal_Down,
	Right_Down,
};

enum class AttackState
{
	None,
	Spark,
	Attack,
	Death,
};

enum class CardType
{
	None,
	Club,
	Diamond,
	Heart,
	Spade,
};