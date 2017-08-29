#include "Edge.h"
#include"Node.h"

Edge::Edge(Node* target, float cost){
	m_target = target;
	m_cost = cost;
}

Edge::~Edge(){

}

Node* Edge::getTarget(){
	return(m_target);
}

float Edge::getCost(){
	return m_cost;
}