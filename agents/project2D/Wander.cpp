#include "Wander.h"
#include"Agent.h"

Wander::Wander(Agent* agent){
	m_agent = agent;
}

Wander::~Wander(){

}

//picks random point on edge of circle, moves towards it, sets new rand location when it gets there?
void Wander::Update(Agent* agent, float dt){
	//define circle
}