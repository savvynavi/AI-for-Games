#include"Agent.h"
#include"IBehaviour.h"
#include"Seek.h"
#include<iostream>

Agent::Agent(aie::Texture *texture, Vector2 &position, aie::Renderer2D *renderer): m_position(position){
	m_renderer = renderer;
	m_texture = texture;
	m_velocity = {0, 0};
	m_force = {0, 0};
	m_maxVelocity = 5000;
}

Agent::~Agent(){

}

//controls how agent moves
void Agent::addForce(Vector2& force){
	m_force += force;
}

//returns this velocity
Vector2 Agent::getVelocity(){
	return m_velocity;
}

//returns this position
Vector2 Agent::getPosition(){
	return m_position;
}

//returns the max velocity
float Agent::getMaxVelocity(){
	return m_maxVelocity;
}

//adds a behaviour to the agent to do
void Agent::addBehaviour(IBehaviour* behaviour){
	m_behaviours.push_back(behaviour);
}

//agent should know how it moves, don't take out into a behaviour, just make movement less shit/add some behaviours to change to
void Agent::Update(float dt){
	//Acting:
	m_dt = dt;
	for(auto iter = m_behaviours.begin(); iter != m_behaviours.end(); iter++){
		(*iter)->Update(this, m_dt);
	}
	//movement update
	m_velocity += m_force * m_dt;
	if(m_velocity.magnitude() > m_maxVelocity){
		//fix norm so it isn't taking mag from the origin but in fact from the 2 vectors
		//m_velocity.normalise() *= m_maxVelocity;

		//non-jittery motion
		float tmp = sqrt(pow(m_velocity.x - m_force.x, 2) + pow(m_velocity.x - m_force.x, 2));
		m_velocity /= tmp;
		m_velocity *= m_maxVelocity;
	}
	m_position += m_velocity * m_dt;
	m_force = {0, 0};
}

//draws agent texture
void Agent::Draw(){
	m_renderer->drawSprite(m_texture, m_position.x, m_position.y);
}