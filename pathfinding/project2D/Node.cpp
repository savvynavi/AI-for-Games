#include "Node.h"

Node::Node(std::string data) : m_data(data){
	
}

Node::~Node(){
	delete m_parent;
}

//checks if the edge has been added before for this node
bool Node::checkEdge(Node *other){
	for(int i = 0; i < this->m_connections.size(); i++){
		if(m_connections[i]->getTarget() == other){
			return true;
		}
	}
	return false;
}

//if both don't have an edge going between them, it will add 2 new edge to create an undirected link
void Node::addEdge(Node* node){
	if((this->checkEdge(node) == false) || (node->checkEdge(this) == false)){
		this->m_connections.push_back(new Edge(node, 1));
		//node->getEdges().push_back(new Edge(this, 1));
		node->addEdge(this);
	}
}

//takes in a node and removes the connections to/from it
void Node::removeEdge(Node *other){
	for(int i = 0; i < this->m_connections.size(); i++){
		if(m_connections[i]->getTarget() == other){
			this->m_connections.erase(m_connections.begin() + i);
		}
	}
}

std::vector<Edge*> Node::getEdges(){
	return m_connections;
}

//returns to cost to move
float Node::getGScore(){
	return m_gScore;
}

void Node::setGScore(float gScore){
	m_gScore = gScore;
}

std::string Node::getData(){
	return m_data;
}

void Node::setPosition(Vector2 pos) {
	m_position = pos;
}

Vector2 Node::getPosition() {
	return m_position;
}

//returns the parent to this node
Node* Node::getParent(){
	return m_parent;
}

//sets the parent of this node
void Node::setParent(Node* node){
	m_parent = node;
}