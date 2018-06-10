#pragma once
#include "steve.h"
#include "ennemy.h"
#include "myEnums.h"

class Command {
protected:
	Actions action;
public:
	virtual Actions getAction() = 0;
};

class JumpCommand : public Command{
protected:
	Actions action;
public:
	Actions getAction() {
		return action;
	}

	JumpCommand()
	{
		this->action = Jump;
	};		
};

class Attack1Command : public Command {
protected:
	Actions action;
public:
	Actions getAction() {
		return action;
	}

	Attack1Command()
	{
		this->action = SteveAttack1;
	};
};

class Attack2Command : public Command {
protected:
	Actions action;
public:
	Actions getAction() {
		return action;
	}

	Attack2Command()
	{
		this->action = SteveAttack2;
	};
};

class MoveRight : public Command {
protected:
	Actions action;
public:
	Actions getAction() {
		return action;
	}

	MoveRight()
	{
		this->action = MovementRigth;
	};
};

class MoveLeft : public Command {
protected:
	Actions action;
public:
	Actions getAction() {
		return action;
	}

	MoveLeft()
	{
		this->action = MovementLeft;
	};
};