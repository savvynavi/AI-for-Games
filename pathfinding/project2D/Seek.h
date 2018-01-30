#pragma once
#include "IBehaviour.h"
#include "Vector2.h"
#include<list>

class Node;

class Seek: public IBehaviour{
public:
	Seek(Agent* agent);
	~Seek();
	void setEndpoint(Node* endPoint);
	float distance(Vector2 &start, Vector2 &end);
	void Update(Agent* agent, float dt);
private:
	Agent* m_agent;
	Node* m_target;
	Vector2 m_targetPos;
	Vector2 m_currentPos;
	std::list<Node*> *m_currentPath;
	bool m_firstRun;
};