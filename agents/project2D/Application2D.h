#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"

#include"Agent.h"
#include"KeyboardControler.h"
#include"Seek.h"
#include"Flee.h"

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
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	aie::Audio*			m_audio;

	Agent*				m_agentTEST;
	Agent*				m_followAgent;
	Agent*				m_fleeAgent;

	Vector2				m_agentPos;
	Vector2				m_followPos;
	Vector2				m_fleePos;

	KeyboardControler*	m_keyboardControlBehav;
	Seek*				m_seekBehav;
	Flee*				m_fleeBehav;

	//Vector2				m_mousePos;

	float m_cameraX, m_cameraY;
	float m_timer;
};