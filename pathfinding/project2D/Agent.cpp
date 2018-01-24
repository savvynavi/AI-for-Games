#include"Agent.h"
#include"Node.h"
#include"Graph.h"
#include"Seek.h"

Agent::Agent(Graph graph, aie::Renderer2D* renderer, Node* startPos){
	m_graph = graph;
	m_renderer = renderer;
	m_currentPos = startPos;
	maxVelocity = 5000;
	m_velocity = { 0, 0 };
	m_force = { 0, 0 };
}

Agent::~Agent() {

}

Node* Agent::getPos() {
	return m_currentPos;
}

void Agent::setPos(Node* currentPos) {
	m_currentPos = currentPos;
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
	m_path = m_graph.calculatePath(m_currentPos, m_endPoint);
	m_seekPathBehav = new Seek(this, m_endPoint);
	this->addBehaviour(m_seekPathBehav);
}

//returns the path it currently has
std::list<Node*> Agent::getPath() {
	return m_path;
}

//moves the agent around each frame
void Agent::Update(float dt) {
	//loop through m_path to move the agent towards the end each frame based on pos and velocity
	m_dt = dt;
	this->setPath(m_graph.getSingleNode(8));
	for(auto it = m_behaviours.begin(); it != m_behaviours.end(); it++){
		(*it)->Update(this, m_dt);
	}

	//move towards bottom of m_path, then pop_back
	std::list<Node*>::iterator it;
	for (it = m_path.begin(); it != m_path.end(); ++it) {
		//move towards
		if ("within some buffer") {
			//pop-back, change target
		}
	}

	//movement/speed controls
	m_velocity += m_force * m_dt;
	if (m_velocity.magnitude() > maxVelocity) {
		float tmp = sqrt(pow(m_velocity.x - m_force.x, 2) + pow(m_velocity.y - m_force.y, 2));
		m_velocity /= tmp;
		m_velocity *= maxVelocity;
	}
	Vector2 tmpPosVector = m_currentPos->getPosition();
	tmpPosVector += m_velocity * m_dt;
	m_currentPos->setPosition(tmpPosVector);
	m_force = { 0, 0 };
}

//draws the agent + path line
void Agent::Draw() {
	m_renderer->setRenderColour(0, 0, 1);
	m_renderer->drawCircle(m_currentPos->getPosition().x, m_currentPos->getPosition().y, 15);
	m_renderer->setRenderColour(1, 0, 0);
	std::list<Node*>::iterator it;
	//loops over path and draws a line from start node to end node
	Node* prev = NULL;
	for (it = m_path.begin(); it != m_path.end(); ++it) {
		Node* curr = *it;
		if (prev != NULL) {
			m_renderer->drawLine(prev->getPosition().x, prev->getPosition().y, curr->getPosition().x, curr->getPosition().y, 5);
		}
		m_renderer->drawCircle(curr->getPosition().x,curr->getPosition().y, 5);
		prev = curr;
	}
}