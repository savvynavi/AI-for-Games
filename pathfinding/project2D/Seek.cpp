#include "Seek.h"
#include "Agent.h"
#include "Node.h"
#include <math.h>

Seek::Seek(Agent* agent, Node* targetNode){
	m_target = targetNode;
	m_agent = agent;
	m_firstRun = true;
}

Seek::~Seek(){

}

float Seek::distance(Vector2 &start, Vector2 &end) {
	return sqrt(((start.x - end.x) * (start.x - end.x)) + ((start.y - end.y) * (start.y - end.y)));
}

void Seek::Update(Agent* agent, float dt){
	//sets the path once so it doesn't keep resetting
	if (m_firstRun == true) {
		m_agent->getPath().pop_front();
		m_firstRun = false;
	}

	//if there is no path, returns
	if (m_agent->getPath().size() <= 0) {
		return;
	}

	m_targetPos = m_agent->getPath().front()->getPosition();
	m_currentPos = m_agent->getAgentPos();
	Vector2 direction = m_targetPos - m_currentPos;

	direction.normalise() *= m_agent->getMaxVelocity() * dt;
	m_agent->addForce(direction * 200);

	//when within certain distance, pops current target and changes to next one in list as long as there are nodes left to traverse
	if (distance(m_currentPos, m_targetPos) < 5.0f && m_agent->getPath().size() > 0) {
		m_agent->getPath().pop_front();
		if (m_agent->getPath().size() > 0) {
			m_targetPos = m_agent->getPath().front()->getPosition();
		}
	}
}