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
	//normalising position vector wrt desired position
	//float mag = sqrt(pow(m_targetPos.x - m_currentPos.x, 2) + pow(m_targetPos.y - m_currentPos.y, 2));
	//Vector2 velocity = m_currentPos / mag;
	//m_agent->addForce(velocity);


	//vid stuff, maybe change to glf::vec

	Vector2 target(m_targetPos);
	Vector2 position(m_currentPos);

	Vector2 direction = target - position;

	direction.normalise() *= m_agent->getMaxVelocity();
	m_agent->addForce(direction);
}