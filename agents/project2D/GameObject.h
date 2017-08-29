#pragma once
#include"Agent.h"

//migt not be needed tute could be referring to agent class itself
class GameObject : public Agent{
public:
	GameObject();
	~GameObject();

	void addForce(Vector2& force);
private:
	Vector2 Velocity;
	float m_maxVelocity;
	Vector2 m_force;
	float m_maxForce;
};