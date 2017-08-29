#include "Flee.h"
#include"Agent.h"
#include<math.h>

Flee::Flee(Agent* agent, Agent* target){
	m_target = target;
	m_agent = agent;
	m_targetPos = m_target->getPosition();
	m_currentPos = m_agent->getPosition();
}


Flee::~Flee(){

}

void Flee::Update(Agent* agent, float dt){
	m_targetPos = m_target->getPosition();
	m_currentPos = m_agent->getPosition();

	Vector2 target(m_targetPos);
	Vector2 position(m_currentPos);

	Vector2 direction = position - target;

	direction.normalise() *= m_agent->getMaxVelocity() * dt;
	m_agent->addForce(direction * 100);
}