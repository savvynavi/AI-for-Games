#include"SeekState.h"
#include"StateManager.h"
#include"Agent.h"

SeekState::SeekState(Agent* agent, StateManager* sm) {
	m_agent = agent;
	m_sm = sm;
	m_input = aie::Input::getInstance();
	this->onEnter();
}

SeekState::~SeekState() {

}

void SeekState::onUpdate(float deltaTime) {
	m_agent->Update(deltaTime);
	if (m_input->isKeyDown(aie::INPUT_KEY_W)) {
		//calls exit condition, pops this state from sm, pushes wander state
		m_sm->popState();
		m_agent->getPath().clear();
		m_sm->pushState(WANDER);
	}
}

void SeekState::onDraw() {
	m_agent->Draw();
}

void SeekState::onEnter() {
	m_agent->m_behaviours.pop_front();
	m_agent->addBehaviour((IBehaviour*)m_agent->m_seekPathBehav);
}

void SeekState::onExit() {

}