#pragma once
#include"Node.h"
#include"Vector2.h"
#include<vector>

class Graph{
public:
	Graph();
	~Graph();
	void addNode(Node* node);
	void removeNode(Node* node);
	bool nodeCheck(Node* node);
private:
	std::vector<Node*> m_nodes;
};

