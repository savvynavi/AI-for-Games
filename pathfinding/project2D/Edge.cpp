#include "Edge.h"
#include"Node.h"

Edge::Edge(Node* target, float cost){
	m_target = target;
	m_cost = cost;
}

Edge::~Edge(){
	delete m_target;
}

Node* Edge::getTarget(){
	return(m_target);
}

float Edge::getCost(){
	return m_cost;
}