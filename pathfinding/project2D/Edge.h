#pragma once
class Node;

class Edge{
public:
	Edge(Node* target, float cost);
	~Edge();

	Node* getTarget();
	float getCost();
private:
	Node* m_target;
	float m_cost = 1;
};

