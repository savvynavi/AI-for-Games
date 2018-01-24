#pragma once
#include <list>
#include "Renderer2D.h"
#include "Vector2.h"
#include "Graph.h"
class Node;
class IBehaviour;
class Seek;

//takes in a position in the graph and draws a circle there, draw function will draw it's path plus the circle at new position
//has a function that calls pathfinder in graph, stores it in its own list
class Agent {
public:
	Agent(Graph graph, aie::Renderer2D* renderer, Node* startPos);
	~Agent();

	Node* getPos();
	void setPos(Node* currentPos);
	float getMaxVelocity();
	void addForce(Vector2& force);
	void addBehaviour(IBehaviour* behaviour);
	void setPath(Node* endPoint);
	std::list<Node*> getPath();

	void Update(float dt);
	void Draw();
protected:
	float m_dt;
	aie::Renderer2D* m_renderer;
	std::list<Node*> m_path;
	Node* m_currentPos;
	Node* m_endPoint;

	//agent movement
	Graph m_graph;
	float maxVelocity;
	Vector2 m_velocity;
	Vector2 m_force;

	//seek bahaviour
	Node* targetPos;
	std::list<IBehaviour*> m_behaviours;
	Seek* m_seekPathBehav;
};

//make it move towards front of m_path each frame, when it gets close to that point, pop off and set movement towards next ones pos
//(seperate this oput into behav class sometime)