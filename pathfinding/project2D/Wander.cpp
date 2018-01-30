#include"Wander.h"
#include"Node.h"
#include"Agent.h"
#include"Seek.h"
#include<stdlib.h>
#include<time.h>

Wander::Wander(Agent* agent) {
	m_agent = agent;
	srand(time(NULL));
	m_seek = new Seek(m_agent);
	m_firstRun = true;
}

Wander::~Wander() {
	delete m_agent;
	delete m_seek;
}

void Wander::setEndpoint(Node* endPoint){
	m_target = endPoint;
}

float Wander::distance(Vector2 &start, Vector2 &end){
	return sqrt(((start.x - end.x) * (start.x - end.x)) + ((start.y - end.y) * (start.y - end.y)));
}

void Wander::Update(Agent* agent, float dt) {

	//calls seek after randomizing the end point and setting a path
	if(m_firstRun == true){
		m_firstRun = false;
		randIndex = rand() % (m_agent->getMap().getNodes().size() - 1);
		while (m_agent->getMap().getSingleNode(randIndex)->getData() == "NULL") {
			randIndex = rand() % m_agent->getMap().getNodes().size();
		}
		m_agent->setPath(m_agent->getMap().getSingleNode(randIndex));
		m_agent->getPath().pop_front();
	}

	//if no current path, sets a new one and resets first run to true
	if (m_agent->getPath().size() <= 0) {
		m_firstRun = true;
		return;
	}

	//edited seek behavior breaks causes this call to not work now
	//m_seek->Update(m_agent, dt);

	m_targetPos = m_agent->getPath().front()->getPosition();
	m_currentPos = m_agent->getAgentPos();
	Vector2 direction = m_targetPos - m_currentPos;

	direction.normalise() *= m_agent->getMaxVelocity() * dt;
	m_agent->addForce(direction * 200);

	if(distance(m_currentPos, m_targetPos) < 2.5f && m_agent->getPath().size() > 0) {
		m_agent->setPos(agent->getPath().front());
		m_agent->getPath().pop_front();
		if(m_agent->getPath().size() > 0) {
			m_targetPos = m_agent->getPath().front()->getPosition();
		}
	}

}