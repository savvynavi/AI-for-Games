#pragma once
#include "IBehaviour.h"

class Wander : public IBehaviour{
public:
	Wander(Agent* agent);
	~Wander();
	void Update(Agent* agent, float dt);
private:
	float m_circleDist;
	float m_radius;

	//use to get circle centre maybe? unless you want circle at rand dist away from agent
	Agent* m_agent;
};