#pragma once
#include"IBehaviour.h"
#include"Vector2.h"
#include"Input.h"


class KeyboardControler : public IBehaviour{
public:
	KeyboardControler(Agent* agent);
	~KeyboardControler();
	virtual void Update(Agent* agent, float dt);
private:
	Vector2 m_forceDir;
	aie::Input* m_input;
	Agent* m_agent;
	bool m_moving = false;
};