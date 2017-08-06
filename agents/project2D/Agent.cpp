#include"Agent.h"
#include"IBehaviour.h"

Agent::Agent(){

}

Agent::~Agent(){

}

void Agent::Update(Agent* agent, float dt){

	//Acting:
	for(auto iter = m_behaviours.begin(); iter != m_behaviours.end(); iter++){
		(*iter)->Update(this, dt);
	}
}

void Agent::Draw(){

}