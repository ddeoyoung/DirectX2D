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
	Hit,
	Dash,
	Jump,
	Parry,
	Intro,
	Ghost,
	Death,
	Max,
};