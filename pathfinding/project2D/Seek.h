#pragma once
#include "IBehaviour.h"
#include "Vector2.h"
#include<list>

class Node;

class Seek: public IBehaviour{
public:
	Seek(Agent* agent, Node* targetNode);
	~Seek();
	void Update(Agent* agent, float dt);
private:
	Node* m_target;
	Agent* m_agent;
	Vector2 m_targetPos;
	Vector2 m_currentPos;
	std::list<Node*> m_currentPath;
};