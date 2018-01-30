#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"

#include "Graph.h"
#include "Agent.h"
#include "Seek.h"

#include"State.h"
#include"StateManager.h"
#include"SeekState.h"
#include"WanderState.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	aie::Audio*			m_audio;

	Graph				m_graph;
	Agent*				m_agent;
	Agent*				m_agent2;
	Seek*				m_seekBehav;

	Vector2				m_mousePos;
	
	StateManager*		m_sm;
	StateManager*		m_sm2;


	float m_cameraX, m_cameraY;
	float m_timer;
};