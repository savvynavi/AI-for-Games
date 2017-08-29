#include "Node.h"

Node::Node(){

}

Node::~Node(){

}

void Node::addEdge(Edge edge){
	//add check to see if edge has already been added
	m_connections.push_back(edge);
}

float Node::getGScore(){
	return m_gScore;
}

Node* Node::getParent(){
	return m_parent;
}

void Node::setParent(Node* node){

}