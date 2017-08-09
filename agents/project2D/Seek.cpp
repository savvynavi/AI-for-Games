#include"Seek.h"
#include"Agent.h"
#include<math.h>

Seek::Seek(Agent *agent, Agent *target){
	m_target = target;
	m_agent = agent;
	m_targetPos = m_target->getPosition();
	m_currentPos = m_agent->getPosition();
}

Seek::Seek(Agent *agent, Vector2& target){
	m_targetPos = target;
	m_agent = agent;
	m_currentPos = m_agent->getPosition();
}

Seek::~Seek(){

}

//calcs force needed to move towards a target vector
void Seek::Update(Agent *agent, float dt){
	//add seek stuff
	//Vector2 V  = m_currentPos.normalise(m_targetPos - m_currentPos) * (m_agent->getMaxVelocity());
	//m_agent->addForce(V - m_agent->getVelocity());

	//Vector2 velocity = {};


	//Vector2 tmp = m_targetPos - m_currentPos;
	//m_currentPos.normalise(tmp);
	//m_currentPos *= m_agent->getMaxVelocity();
	//m_agent->addForce(tmp - m_currentPos);
	

	float tmp = sqrt(m_currentPos.magnitude(m_targetPos));
	Vector2 velocity((m_currentPos.x / tmp), (m_currentPos.y / tmp));
	velocity *= m_agent->getMaxVelocity();
	velocity -= agent->getVelocity();
	m_agent->addForce(velocity);
	//Vector2 force(velocity);
	//m_agent->addForce(instVel - m_agent->getVelocity());
}