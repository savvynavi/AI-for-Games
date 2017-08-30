#include "Graph.h"


Graph::Graph(){

}


Graph::~Graph(){

}

void Graph::addNode(Node* node){
	m_nodes.push_back(node);
}

//go through vector, erase node with same id
void Graph::removeNode(Node* node){
	for(int i = 0; i < m_nodes.size(); i++){
		if(m_nodes[i]->getTag() == node->getTag()){
			//remove all edges to the node then remove the node from list
			
			return;
		}
	}
}