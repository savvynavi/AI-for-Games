#pragma once
#include"IBehaviour.h"
#include"Vector2.h"
#include<list>

class Node;
class Seek;

//coulde derive from seek?
class Wander : public IBehaviour {
public:
	Wander(Agent* agent);
	~Wander();
	void setEndpoint(Node* endPoint);
	float distance(Vector2 &start, Vector2 &end);
	void Update(Agent* m_agent, float dt);
private:
	Agent* m_agent;
	Seek* m_seek;
	Node* m_target;
	Vector2 m_targetPos;
	Vector2 m_currentPos;
	std::list<Node*> *m_currentPath;
	bool m_firstRun;
	int randIndex;
};