#include"KeyboardControler.h"
#include"Agent.h"

KeyboardControler::KeyboardControler(Agent* agent){
	m_input = aie::Input::getInstance();
	m_agent = agent;
	m_forceDir = {0, 0};
}

KeyboardControler::~KeyboardControler(){

}

void KeyboardControler::Update(Agent* agent, float dt){
	//keyboard input changed force applied to agent, up/right = +ve, down/left = -ve
	
	if(m_input->isKeyDown(aie::INPUT_KEY_UP)){
		m_moving = true;
		m_forceDir = { 0, 100 };
		m_agent->addForce(m_forceDir);
	}
	if(m_input->isKeyDown(aie::INPUT_KEY_RIGHT)){
		m_moving = true;
		m_forceDir = { 100, 0 };
		m_agent->addForce (m_forceDir);
	}
	if(m_input->isKeyDown(aie::INPUT_KEY_DOWN)){
		m_moving = true;
		m_forceDir = { 0, -100 };
		m_agent->addForce (m_forceDir);
	}
	if(m_input->isKeyDown(aie::INPUT_KEY_LEFT)){
		m_moving = true;
		m_forceDir = { -100, 0 };
		m_agent->addForce (m_forceDir);
	}
}