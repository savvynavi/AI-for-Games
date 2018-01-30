#include"WanderState.h"
#include"StateManager.h"
#include"Agent.h"

WanderState::WanderState(Agent* agent, StateManager* sm) {
	m_agent = agent;
	m_sm = sm;
	m_input = aie::Input::getInstance();
}

WanderState::~WanderState() {

}

void WanderState::onUpdate(float deltaTime) {

	m_agent->Update(deltaTime);
	if (m_input->isKeyDown(aie::INPUT_KEY_S)) {
		m_sm->popState();
		m_agent->getPath().clear();
		m_sm->pushState(SEEK);
	}
}

void WanderState::onDraw() {
	m_agent->Draw();
}

void WanderState::onEnter() {
	m_agent->m_behaviours.pop_front();
	m_agent->addBehaviour((IBehaviour*)m_agent->m_wanderBehav);
}

void WanderState::onExit() {

}