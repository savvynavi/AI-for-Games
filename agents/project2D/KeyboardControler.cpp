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
		m_forceDir = { 0, 10 };
		m_agent->setForce(m_forceDir);
	}
	else if(m_input->isKeyDown(aie::INPUT_KEY_RIGHT)){
		m_moving = true;
		m_forceDir = { 10, 0 };
		m_agent->setForce(m_forceDir);
	}
	else if(m_input->isKeyDown(aie::INPUT_KEY_DOWN)){
		m_moving = true;
		m_forceDir = { 0, -10 };
		m_agent->setForce(m_forceDir);
	}
	else if(m_input->isKeyDown(aie::INPUT_KEY_LEFT)){
		m_moving = true;
		m_forceDir = { -10, 0 };
		m_agent->setForce(m_forceDir);
	}

	//deacceleration stuff when keys are up
	//if(m_moving == true){
	//	if(m_input->isKeyUp(aie::INPUT_KEY_UP)){
	//		m_moving = false;
	//		m_forceDir = { 0, -10 };
	//		m_agent->setForce(m_forceDir);
	//	} else if(m_input->isKeyUp(aie::INPUT_KEY_RIGHT)){
	//		m_moving = false;
	//		m_forceDir = { -10, 0 };
	//		m_agent->setForce(m_forceDir);
	//	} else if(m_input->isKeyUp(aie::INPUT_KEY_DOWN)){
	//		m_moving = false;
	//		m_forceDir = { 0, 10 };
	//		m_agent->setForce(m_forceDir);
	//	} else if(m_input->isKeyUp(aie::INPUT_KEY_LEFT)){
	//		m_moving = false;
	//		m_forceDir = { 10, 0 };
	//		m_agent->setForce(m_forceDir);
	//	}
	//}
}