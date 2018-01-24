#include "Seek.h"
#include "Agent.h"
#include "Node.h"
#include <math.h>

Seek::Seek(Agent* agent, Node* targetNode){
	m_target = targetNode;
	m_agent = agent;
	//m_targetPos = m_target->getPosition();
	//m_currentPos = m_agent->getPos()->getPosition();
}

Seek::~Seek(){

}

void Seek::Update(Agent* agent, float dt){
	m_currentPath = m_agent->getPath();

	m_targetPos = m_currentPath.front()->getPosition();
	m_currentPos = m_agent->getPos()->getPosition();

	//when agent is close to current target, and if the path list isn't empty, it pops the front off so the next node will become the target position
	if(abs(m_agent->getPos()->getPosition().x - m_target->getPosition().x) < 5.0f && abs(m_agent->getPos()->getPosition().y - m_target->getPosition().y) < 5.0f && m_currentPath.size() < 0){
		m_currentPath.pop_front();
		m_targetPos = m_currentPath.front()->getPosition();
	}
	

	//Vector2 target(m_targetPos);
	//Vector2 position(m_currentPos);

	Vector2 direction = m_targetPos - m_currentPos;

	direction.normalise() *= m_agent->getMaxVelocity() * dt;
	m_agent->addForce(direction * 100);
}