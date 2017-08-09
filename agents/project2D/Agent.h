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
	void addForce(Vector2& force);
	Vector2 getVelocity();
	Vector2 getPosition();
	float getMaxVelocity();
	void addBehaviour(IBehaviour* behaviour);
	virtual void Update(float dt);
	virtual void Draw();
protected:
	std::list<IBehaviour*> m_behaviours;
	aie::Renderer2D* m_renderer;
	float m_dt;
	aie::Texture *m_texture;
	Vector2 m_force;
	Vector2 m_velocity;
	Vector2 m_position;
	float m_maxVelocity;
};
