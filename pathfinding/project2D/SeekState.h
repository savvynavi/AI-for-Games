#include"State.h"
#include"Input.h"

class StateManager;
class Agent;

class SeekState : public State {
public:
	SeekState(Agent* agent, StateManager* sm);
	virtual ~SeekState();
	virtual void onUpdate(float deltaTime);
	virtual void onDraw();
	virtual void onEnter();
	virtual void onExit();
protected:
	Agent* m_agent;
	StateManager* m_sm;
	aie::Input* m_input;
};