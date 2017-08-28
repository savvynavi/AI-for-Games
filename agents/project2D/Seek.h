#pragma once
#include"IBehaviour.h"
#include"Vector2.h"

class Seek: public IBehaviour{
public:
	Seek(Agent *agent, Agent *target);
	Seek (Agent *agent, Vector2& target);
	~Seek();
	void Update(Agent *target, float dt);
private:
	Agent* m_target;
	Agent* m_agent;
	Vector2 m_targetPos;
	Vector2 m_currentPos;
};