#include "Node.h"

Node::Node(std::string data) : m_data(data){

}

Node::~Node(){

}
////possible delete or leave as overloads?
//checks to see if the edge has already been added
//bool Node::checkEdge(Edge* edge){
//	for(int i = 0; i < m_connections.size(); i++){
//		if(m_connections[i] == edge){
//			return true;
//		}
//	}
//	return false;
//}
//
////if edge is new, adds it to vector
//void Node::addEdge(Edge* edge){
//	if(this->checkEdge(edge) == false){
//		m_connections.push_back(edge);
//	}
//}

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

std::string Node::getData(){
	return m_data;
}

////returns the parent to this node
//Node* Node::getParent(){
//	return m_parent;
//}
//
////sets the parent of this node
//void Node::setParent(Node* node){
//
//}