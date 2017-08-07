#pragma once
#include"Vector2.h"
#include<list>
#include"Texture.h"
#include"Renderer2D.h"
class IBehaviour;

class Agent{
public:
	Agent(aie::Texture *texture, Vector2 &position, aie::Renderer2D *renderer);
	~Agent();
	//weird delay once it's at max velocity to star changing numbers again=>fix this
	void addForce();
	void setForce(Vector2& force);
	void addBehaviour(IBehaviour* behaviour);
	virtual void Update(float dt);
	virtual void Draw();
protected:
	std::list<IBehaviour*> m_behaviours;

	aie::Renderer2D* m_renderer;
	float m_dt;
	int m_timer;
	aie::Texture *m_texture;
	Vector2 m_force;
	Vector2 m_acc;
	Vector2 m_velocity;
	Vector2 m_position;
};
