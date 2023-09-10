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
	Aim,
	Shoot,
	Duck,
	DuckIdle,
	DuckShoot,
	Hit,
	Dash,
	Jump,
	Parry,
	Intro,
	Ghost,
	Death,
	Max,
};

enum class AttackDirection
{
	Left_Up,
	Left_DiagonalUp,
	Left_Straight,
	Left_DiagonalDown,
	Left_Down,
	Right_Up,
	Right_Diagonal_Up,
	Right_Straight,
	Right_Diagonal_Down,
	Right_Down,
};