#pragma once
#include"Agent.h"
#include"Vector2.h"

//this class seems pointless/is never used, delete later
class SteeringForce{
public:
	SteeringForce(){};
	~SteeringForce(){};
	virtual Vector2 getForce(Agent* agent) = 0;
};