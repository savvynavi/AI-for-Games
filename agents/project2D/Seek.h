#pragma once
#include"IBehaviour.h"
#include"Vector2.h"

class Seek: public IBehaviour{
	Seek(Agent *target);
	~Seek();
	
	Vector2 *m_targetPos;

	virtual void Update(Agent *agent, float dt){
		//add seek stuff
	}
};