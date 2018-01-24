#pragma once

class Agent;

class IBehaviour{
public:
	IBehaviour(){}
	~IBehaviour(){}
	virtual void Update(Agent* agent, float dt) = 0;
};