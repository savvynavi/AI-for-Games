#pragma once
#include"Node.h"
#include"Vector2.h"
#include<vector>

class Graph{
public:
	Graph();
	Graph(std::vector<Node*> nodes);
	~Graph();
	bool nodeCheck(Node* node);
	void addNode(Node* node);
	void removeNode(Node* node);
	void printData();
	std::vector<Node*> getNodes();
	void setGraph();
	void printGraph();
	void setNodes();
private:
	std::vector<Node*> m_nodes;
	static const int m_size = 3;
	
	const char *m_ascii[m_size][m_size] = {
		{ "1", "1", "1" },
		{ "1", "0", "0" },
		{ "1", "1", "1" }
	};

};