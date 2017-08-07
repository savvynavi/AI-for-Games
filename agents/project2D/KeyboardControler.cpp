#include"KeyboardControler.h"
#include"Agent.h"

KeyboardControler::KeyboardControler(Agent* agent){
	m_intput = aie::Input::getInstance();
	m_agent = agent;
	m_forceDir = {0, 0};
}

KeyboardControler::~KeyboardControler(){

}

void KeyboardControler::Update(Agent* agent, float dt){
	//keyboard input changed force applied to agent, up/right = +ve, down/left = -ve
	//lol this is bad and it doesn't even work
	if(m_intput->isKeyDown(aie::INPUT_KEY_UP)){
		m_forceDir = { 0, 10 };
		m_agent->setForce(m_forceDir);
	}
	if(m_intput->isKeyDown(aie::INPUT_KEY_RIGHT)){
		m_forceDir = { 10, 0 };
		m_agent->setForce(m_forceDir);
	}
	if(m_intput->isKeyDown(aie::INPUT_KEY_DOWN)){
		m_forceDir = { 0, -10 };
		m_agent->setForce(m_forceDir);
	}
	if(m_intput->isKeyDown(aie::INPUT_KEY_LEFT)){
		m_forceDir = { -10, 0 };
		m_agent->setForce(m_forceDir);
	}
}