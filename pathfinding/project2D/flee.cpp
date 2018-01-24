#include"Flee.h"
#include"Node.h"

Flee::Flee(Agent* agent, Agent* pursuer) {
	m_agent = agent;
	m_pursuer = pursuer;
}

Flee::~Flee() {

}

void Flee::Update(Agent* agent, float dt) {
	//each frame chooses a node to move to that is not towards the pursuing agent
	//make it path find away from given point?

}