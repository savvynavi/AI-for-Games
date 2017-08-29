#pragma once
#include "IBehaviour.h"
#include"Vector2.h"

class Flee : public IBehaviour{
public:
	Flee(Agent* agent, Agent* target);
	~Flee();
	void Update(Agent* agent, float dt);
private:
	Agent* m_target;
	Agent* m_agent;
	Vector2 m_targetPos;
	Vector2 m_currentPos;
};

