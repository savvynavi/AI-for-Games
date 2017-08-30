#pragma once
#include"Edge.h"
#include"Vector2.h"
#include<vector>
#include<string>

class Node{
public:
	Node(std::string &tag);
	~Node();

	void addEdge(Edge edge);
	void addEdge(std::vector<Edge> edges);
	bool edgeCheck(Edge& edge);

	float getGScore();
	Node* getParent();
	void setParent(Node* node);
	bool operator<(const Node& newNode)const;
	std::string getId()const;
private:
	std::string m_id;
	Vector2 m_position;
	float m_gScore;
	Node* m_parent;
	std::vector<Edge> m_connections;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
//http://www.sanfoundry.com/cpp-programming-examples-graph-problems-algorithms/
//https://gist.github.com/quickgrid/d9f3f416f0dd639425dd2484f9f118f2
//http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
//https://stackoverflow.com/questions/19955150/applying-dijkstras-algorithm-on-a-graph-of-five-nodes
//////////////////////////////////////////////////////////////////////////////////////////////////////