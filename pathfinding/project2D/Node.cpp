#include "Node.h"

//takes in string id
Node::Node(std::string &id){
	m_id = id;
}

Node::~Node(){

}

//returns true if edge already in list, false otherwise
bool Node::edgeCheck(Edge& edge){
	for(int i = 0; i < m_connections.size(); i++){
		if(m_connections[i].getTarget() == edge.getTarget()){
			return true;
		}
	}
	return false;
}

//takes 1 edge in, adds it if not already added
void Node::addEdge(Edge edge){
	//add check to see if edge has already been added
	if(this->edgeCheck(edge) == false){
		m_connections.push_back(edge);

	}
}

//takes vector of edges as input, adds any edges not already attached to node
void Node::addEdge(std::vector<Edge> edges){
	for(int i = 0; i < edges.size(); i++){
		//checks if edge already in list, if not it's added
		if(this->edgeCheck(edges[i]) == false){
			m_connections.push_back(edges[i]);
		}
	}
}

//maybe move to graph class
float Node::getGScore(){
	return m_gScore;
}

//maybe delete
Node* Node::getParent(){
	return m_parent;
}

//maybe delete
void Node::setParent(Node* node){

}

//returns the nodes ID
std::string Node::getId()const{
	return m_id;
}

//map overload
bool Node::operator<(const Node& newNode)const{
	if(newNode.getId() < this -> getId()){
		return true;
	}
	return false;
}