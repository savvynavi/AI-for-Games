#pragma once
#include"IBehaviour.h"

//tute does ibehaviour differently making this useless, delete later
class SteeringBehaviour : public IBehaviour{
public:
	SteeringBehaviour();
	~SteeringBehaviour();

	void Update(Agent* agent, float dt);
private:
};