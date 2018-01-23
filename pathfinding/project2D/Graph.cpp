#include "Graph.h"
#include<iostream>
#include<algorithm>
#include<list>

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
				Node* tmpNode = new Node(std::to_string((i * m_size) + j));
				m_nodes.push_back(tmpNode);
				nodeGrid[i][j] = tmpNode;
			}else{
				Node* tmpNode = new Node("NULL");
				m_nodes.push_back(tmpNode);
				nodeGrid[i][j] = tmpNode;
			}
			//sets the position of the nodes in a coord on the app
			nodeGrid[i][j]->setPosition(Vector2(j * 32, i * 32));
		}
	}

	//sets position in reverse so it draws correctly (eg not upsidedown)
	//for (int i = m_size - 1; i >= 0; i--) {
	//	for (int j = 0; j < m_size; j++) {
	//		nodeGrid[i][j]->setPosition(Vector2(j * 32, i * 32));
	//	}
	//}

	////creates edges between nodes up/down(left/right needs more checks) - Now it doesn't add edges to invalid "Null" nodes even though they're stored in m_nodes
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			if (i < m_size - 1 && nodeGrid[i][j] && nodeGrid[i + 1][j]){
				//add in horizontal edges
				if (nodeGrid[i][j]->getData() != "NULL" && nodeGrid[i + 1][j]->getData() != "NULL"){
					nodeGrid[i][j]->addEdge(nodeGrid[i + 1][j]);
				}
			}
			if(j < m_size-1 && nodeGrid[i][j] && nodeGrid[i][j+1]){
				//add vertical edges
				if (nodeGrid[i][j]->getData() != "NULL" && nodeGrid[i][j + 1]->getData() != "NULL") {
					nodeGrid[i][j]->addEdge(nodeGrid[i][j + 1]);
				}
			}
		}
	}
}

std::list<Node*> Graph::calculatePath(Node* start, Node* end){
	
	std::list<Node*> pathNodes;
	float gScore = 0;
	std::list<Node*> openList;
	std::list<Node*> closedList;

	if(start == nullptr || end == nullptr){
		return pathNodes;
	}

	openList.push_back(start);
	this->reset();
	start->setGScore(0);

	while(openList.size() > 0){
		Node* currentNode = openList.front();
		openList.pop_front();



		for(int i = 0; i < currentNode->getEdges().size(); i++){

			// make sure the connectioon is not in the closed list
			std::list<Node*>::iterator inClosedList;
			Node* currentTarget = currentNode->getEdges()[i]->getTarget();
			inClosedList = std::find(closedList.begin(), closedList.end(), currentTarget);
			
			if(inClosedList == closedList.end()){
				Node* endTarget = currentNode->getEdges()[i]->getTarget();
				if(endTarget != end){
					//calculates this gScore and compares to current one, if it's smaller it will become the new gScore and will set nodes up again
					float gScoreTmp = currentNode->getGScore() + currentNode->getEdges()[i]->getCost();
					//existing cost to get to the node 
					gScore = endTarget->getGScore();

					//if this is the best route so far
					if(gScoreTmp < gScore){
						endTarget->setParent(currentNode);
						endTarget->setGScore(gScoreTmp);

						//checks to see if the end node is in the queue, if not it adds it
						std::list<Node*>::iterator isEndThere;
						isEndThere = std::find(openList.begin(), openList.end(), endTarget);
						if(isEndThere == openList.end()){
							openList.push_back(endTarget);
						}
					}
				}else{
					//add end to the list, then add current node, step back through parents until null
					pathNodes.push_front(end);
					pathNodes.push_front(currentNode);
					Node* tmpCurrentNode = currentNode;
					while(tmpCurrentNode->getParent() != nullptr){
						pathNodes.push_front(tmpCurrentNode->getParent());
						tmpCurrentNode = tmpCurrentNode->getParent();
					}
				}
			}
		}
		// add current node to closed list
		closedList.push_back(currentNode);
	}

	return pathNodes;
}

//resets the values for pathfinding
void Graph::reset(){
	for(int i = 0; i < this->m_nodes.size(); i++){
		this->m_nodes[i]->setGScore(FLT_MAX);
		this->m_nodes[i]->setParent(nullptr);
	}
}

Node* Graph::getSingleNode(int id) {
	return m_nodes[id];
}

//draws a box differeing in colour depending if traversable or not
void Graph::Draw(aie::Renderer2D* renderer) {
	m_renderer = renderer;
	//draws the nodes at their set pos
	for (int i = 0; i < m_nodes.size(); i++) {
		if (m_nodes[i]->getData() == "NULL"){
			m_renderer->setRenderColour(1, 1, 1);
		}else {
			m_renderer->setRenderColour(0.5f, 0, 0.5f);
		}
		m_renderer->drawBox(m_nodes[i]->getPosition().x, m_nodes[i]->getPosition().y, 30.0f, 30.0f);
	}
}