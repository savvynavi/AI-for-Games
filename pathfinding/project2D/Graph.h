#pragma once
#include"Node.h"
#include"Vector2.h"
#include<vector>
#include<map>

class Graph{
public:
	Graph();
	~Graph();
	void addNode(Node* node);
	void removeNode(Node* node);
private:
	//change to map when op works/decided on id
	std::vector<Node*> m_nodes;
};