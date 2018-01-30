#include"Agent.h"
#include"Node.h"
#include"Graph.h"
#include"Seek.h"
#include"Wander.h"
#include<stdlib.h>
#include<time.h>

Agent::Agent(Graph graph, aie::Renderer2D* renderer, Node* startPos, float r, float g, float b, float offset){
	m_graph = graph;
	m_renderer = renderer;
	m_currentPos = startPos;
	m_agentPos = m_currentPos->getPosition();
	maxVelocity = 50;
	m_velocity = { 0, 0 };
	m_force = { 0, 0 };
	srand(time(NULL));
	m_seekPathBehav = new Seek(this);
	m_wanderBehav = new Wander(this);
	this->addBehaviour(m_seekPathBehav);

	m_r = r;
	m_g = g;
	m_b = b;
	m_offset = offset;
}

Agent::~Agent() {
	delete m_agentPos;
	delete m_renderer;
	delete m_seekPathBehav;
	delete m_endPoint;
}

Node* Agent::getPos() {
	return m_currentPos;
}

void Agent::setPos(Node* currentPos) {
	m_currentPos = currentPos;
}

void Agent::setAgentPos(Vector2 agentPosition) {
	m_agentPos = agentPosition;
}

Vector2 Agent::getAgentPos() {
	return m_agentPos;
}

float Agent::getMaxVelocity(){
	return maxVelocity;
}

void Agent::addForce(Vector2& force){
	m_force += force;
}

void Agent::addBehaviour(IBehaviour* behaviour){
	m_behaviours.push_back(behaviour);
}

//calls the graph pathfinder using it's own node pos + given end pos, tries to form a list of nodes to path it there
void Agent::setPath(Node* endPoint) {
	m_endPoint = endPoint;
	m_seekPathBehav->setEndpoint(m_endPoint);
	m_path = m_graph.calculatePath(m_currentPos, m_endPoint);
}

//returns the path it currently has
std::list<Node*>& Agent::getPath() {
	return m_path;
}

Graph Agent::getMap() {
	return m_graph;
}

void Agent::setEndpoint(Node* endpoint){
	m_endPoint = endpoint;
}

Node* Agent::getEndpoint(){
	return m_endPoint;
}

//moves the agent around each frame
void Agent::Update(float dt) {
	//loop through m_path to move the agent towards the end each frame based on pos and velocity
	m_dt = dt;

	//loops through behaviour list and calls update on each one
	for(auto it = m_behaviours.begin(); it != m_behaviours.end(); it++){
		(*it)->Update(this, m_dt);
	}

	//movement/speed controls
	m_velocity += m_force * m_dt;
	if (m_velocity.magnitude() > maxVelocity) {
		float tmp = sqrt(pow(m_velocity.x - m_force.x, 2) + pow(m_velocity.y - m_force.y, 2));
		m_velocity /= tmp;
		m_velocity *= maxVelocity;
	}

	Vector2 tmpPosVector = m_agentPos;
	tmpPosVector += m_velocity * m_dt;
	this->setAgentPos(tmpPosVector);
	m_force = { 0, 0 };
}

//draws the agent + path line
void Agent::Draw() {
	m_renderer->setRenderColour(0, 0, 1);
	m_renderer->drawCircle(m_agentPos.x, m_agentPos.y, 15);
	m_renderer->setRenderColour(m_r, m_g, m_b);
	std::list<Node*>::iterator it;
	//loops over path and draws a line from start node to end node
	Node* prev = NULL;
	for (it = m_path.begin(); it != m_path.end(); ++it) {
		Node* curr = *it;
		if (prev != NULL) {
			m_renderer->drawLine(prev->getPosition().x + m_offset, prev->getPosition().y + m_offset, curr->getPosition().x + m_offset, curr->getPosition().y + m_offset, 5);
		}
		m_renderer->drawCircle(curr->getPosition().x + m_offset,curr->getPosition().y + m_offset, 5);
		prev = curr;
	}
}