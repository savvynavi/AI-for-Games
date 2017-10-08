#include "Graph.h"
#include<iostream>

Graph::Graph(){

}

Graph::Graph(std::vector<Node*> nodes){
	m_nodes = nodes;

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

void Graph::printData(){
	for (int i = 0; i < m_nodes.size(); i++) {
		std::cout << m_nodes[i]->getData() << " ";
	}
}

std::vector<Node*> Graph::getNodes(){
	return m_nodes;
}

void Graph::setGraph(){
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			
		}
	}
}

void Graph::printGraph() {
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			std::cout << m_ascii[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Graph::setNodes() {

	Node* nodeGrid[m_size][m_size];

	//create nodes with either 1 or 0 lable
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			if(m_ascii[i][j] == "1"){
				Node* tmpNode = new Node("1"); //todo pass in position eg i * 32 j*32 to get basic coords without hardcoding them
				m_nodes.push_back(tmpNode);
				nodeGrid[i][j] = tmpNode;
			}else{
				nodeGrid[i][j] = NULL;
			}
		}
	}

	////creates edges between nodes up/down(left/right needs more checks)
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			if (i < m_size - 1 && nodeGrid[i][j] && nodeGrid[i + 1][j]){
				//add in horizontal edges
				nodeGrid[i][j]->addEdge(nodeGrid[i + 1][j]);
			}
			if(j < m_size-1 && nodeGrid[i][j] && nodeGrid[i][j+1]){
				//add vertical edges
				nodeGrid[i][j]->addEdge(nodeGrid[i][j + 1]);

			}
		}
	}


	//for(int i = 0; i < m_nodes.size() - 3; i++) {
	//	if(m_nodes[i]->getData() == "1" && m_nodes[i + 3]->getData() == "1"){
	//		m_nodes[i]->addEdge(m_nodes[i + 3]);
	//	}
	//}

}
