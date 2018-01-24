#pragma once
#include "IBehaviour.h"
#include "Vector2.h"
#include<list>

class Node;

class Flee : public IBehaviour {
public:
	Flee(Agent* agent, Agent* pursuer);
	~Flee();
	void Update(Agent* agent, float dt);
private:
	Agent* m_pursuer;
	Agent* m_agent;
	Vector2 m_targetPos;
	Vector2 m_currentPos;
};