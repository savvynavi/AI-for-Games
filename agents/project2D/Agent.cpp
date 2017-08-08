#include"Agent.h"
#include"IBehaviour.h"
#include"Seek.h"
#include<iostream>

Agent::Agent(aie::Texture *texture, Vector2 &position, aie::Renderer2D *renderer): m_position(position){
	m_renderer = renderer;
	m_texture = texture;
	m_velocity = {0, 0};
	m_acc = {0, 0};
	m_force = {0, 0};
	m_maxVelocity = 100;
}

Agent::~Agent(){

}

//controls how agent moves
void Agent::addForce(){
	//m_acc += m_force;
	//m_velocity = (m_velocity + (m_acc * m_dt));
	//m_position += m_velocity;
	m_velocity += m_force * m_dt;



	//m_velocity += m_acc;
	//if(m_velocity.x > m_maxVelocity){
	//	m_velocity.x = m_maxVelocity;
	//}
	//if(m_velocity.x < -m_maxVelocity){
	//	m_velocity.x = -m_maxVelocity;
	//}
	//if(m_velocity.y > m_maxVelocity){
	//	m_velocity.y = m_maxVelocity;
	//}
	//if(m_velocity.y < -m_maxVelocity){
	//	m_velocity.y = -m_maxVelocity;
	//}
	m_position += m_velocity * m_dt;
	//m_acc = {0, 0};
	//m_position += m_velocity * m_dt;
}

//weird lag probs from no f cap
void Agent::setForce(Vector2& force){
	m_force += force;
	//if(m_force.x > 50){
	//	m_force.x = 50;
	//}
	//if(m_force.y > 50){
	//	m_force.y = 50;
	//}
	//if(m_force.x < -50){
	//	m_force.x = -50;
	//}
	//if(m_force.y < -50){
	//	m_force.y = -50;
	//}
}

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
	this->addForce();

	//std::cout << "velocity is now {" << this->m_velocity.x << ", " << this->m_velocity.y << "}\n";
	//std::cout << "Force is now {" << this->m_force.x << ", " << this->m_force.y << "}\n";

}

void Agent::Draw(){
	m_renderer->drawSprite(m_texture, m_position.x, m_position.y);
}