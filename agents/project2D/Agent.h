#pragma once
#include"Vector2.h"
#include<list>
class IBehaviour;

class Agent{
public:
	Agent();
	~Agent();
	void addForce();
	virtual void Update(Agent* agent, float dt);
	virtual void Draw();
protected:
	std::list<IBehaviour*> m_behaviours;

	Vector2 m_force;
	Vector2 m_acc;
	Vector2 m_velocity;
	Vector2 m_position;
};
