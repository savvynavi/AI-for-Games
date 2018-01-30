#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"

#include "Graph.h"
#include "Agent.h"
#include "Seek.h"

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
	Seek*				m_seekBehav;

	Vector2				m_mousePos;
	//bool				m_endPointCheck;

	float m_cameraX, m_cameraY;
	float m_timer;
};