#pragma once
#include"IBehaviour.h"
#include"Vector2.h"

class Seek: public IBehaviour{
public:
	Seek(Agent *target);
	~Seek();
	virtual void Update(Agent *agent, float dt);

	Vector2 *m_targetPos;
};