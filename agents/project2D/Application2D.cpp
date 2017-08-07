#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_shipTexture = new aie::Texture("./textures/ship.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_audio = new aie::Audio("./audio/powerup.wav");

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	m_agentPos = {50, 50};

	m_agentTEST = new Agent(m_shipTexture, m_agentPos, m_2dRenderer);
	m_keyboardControlBehav = new KeyboardControler(m_agentTEST);
	m_agentTEST->addBehaviour(m_keyboardControlBehav);

	return true;
}

void Application2D::shutdown() {
	
	delete m_audio;
	delete m_font;
	delete m_shipTexture;
	delete m_2dRenderer;
	delete m_agentTEST;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	m_agentTEST->Update(deltaTime);
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	m_agentTEST->Draw();

	// done drawing sprites
	m_2dRenderer->end();
}