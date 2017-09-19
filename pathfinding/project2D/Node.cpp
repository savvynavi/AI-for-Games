#include "Node.h"

Node::Node(){

}

Node::~Node(){

}

//checks to see if the edge has already been added
bool Node::checkEdge(Edge* edge){
	for(int i = 0; i < m_connections.size(); i++){
		if(m_connections[i] == edge){
			return true;
		}
	}
	return false;
}

//if edge is new, adds it to vector
void Node::addEdge(Edge* edge){
	if(checkEdge(edge) == false){
		m_connections.push_back(edge);
	}
}

//returns to cost to move
float Node::getGScore(){
	return m_gScore;
}

//returns the parent to this node
Node* Node::getParent(){
	return m_parent;
}

//sets the parent of this node
void Node::setParent(Node* node){

}