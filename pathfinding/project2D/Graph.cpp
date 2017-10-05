#include "Graph.h"


Graph::Graph(){

}

Graph::~Graph(){

}

//returns true if node already in vector, false otherwise
bool Graph::nodeCheck(Node* node){
	for(int i = 0; i < m_nodes.size(); i++){
		if(m_nodes[i] == node){
			return true;
		}
	}
	return false;
}

//adds the node if it's not already there
void Graph::addNode(Node* node){
	if(nodeCheck(node) == false){
		m_nodes.push_back(node);
	}
}

//removes node if it's in graph, as no duuplicade nodes it returns once the node is found/removed
void Graph::removeNode(Node* node){
	if(nodeCheck(node) == false){
		return;
	}

	//loops through to delete all edges leading to node, then deletes the node itself Hopefully
	for(int i = 0; i < m_nodes.size(); i++){
		if(m_nodes[i] == node){
			for(int j = 0; j < m_nodes[i]->getEdges().size(); j++){
				m_nodes[i]->getEdges()[j]->getTarget()->removeEdge(node);
			}
			m_nodes.erase(m_nodes.begin() + i);
			return;
		}
	}
}