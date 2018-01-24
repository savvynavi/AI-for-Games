#pragma once

class Agent;

class IBehaviour{
public:
	IBehaviour(){}
	~IBehaviour(){}
	virtual void Update(Agent* agent, float dt) = 0;
};

//create seek, wander (could be makde by changing seek a little bit), and patrol(given start end point keeps path finding between the 2 until it can seek an enemy or something, swaps to seek state then)