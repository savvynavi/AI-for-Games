#pragma once
#include"Edge.h"
#include"Vector2.h"
#include<string>
#include<vector>

class Node{
public:
	Node(std::string data);
	~Node();

	//bool checkEdge(Edge* edge);
	//void addEdge(Edge* edge);
	bool checkEdge(Node *node);
	void addEdge(Node* node);
	std::vector<Edge*> getEdges();
	void removeEdge(Node *other);
	float getGScore();
	std::string getData();
	//are these 2 needed?
	//Node* getParent();
	//void setParent(Node* node);
private:
	Vector2 m_position;
	float m_gScore;
	Node* m_parent;
	std::string m_data;
	std::vector<Edge*> m_connections;
};

