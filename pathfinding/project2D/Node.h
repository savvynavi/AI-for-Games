#pragma once
#include"Edge.h"
#include"Vector2.h"
#include<vector>

class Node{
public:
	Node();
	~Node();

	void addEdge(Edge edge);
	float getGScore();
	Node* getParent();
	void setParent(Node* node);
private:
	Vector2 m_position;
	float m_gScore;
	Node* m_parent;
	std::vector<Edge> m_connections;
};

