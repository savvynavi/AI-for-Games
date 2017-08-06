#pragma once

class Agent;

class IBehaviour{
	IBehaviour();
	~IBehaviour(){}
	virtual void Update(Agent *agent, float dt) = 0;
};