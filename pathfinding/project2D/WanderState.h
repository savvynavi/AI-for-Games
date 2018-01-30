#pragma once
#include"State.h"
#include"Input.h"

class StateManager;
class Agent;

class WanderState : public State {
public:
	WanderState(Agent* agent, StateManager* sm);
	~WanderState();
	virtual void onUpdate(float deltaTime);
	virtual void onDraw();
	virtual void onEnter();
	virtual void onExit();
protected:
	Agent* m_agent;
	StateManager* m_sm;
	aie::Input* m_input;
};