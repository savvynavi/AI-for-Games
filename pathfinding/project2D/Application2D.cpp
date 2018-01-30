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

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_audio = new aie::Audio("./audio/powerup.wav");

	m_cameraX = (-1280 / 2);
	m_cameraY = (-720 / 2);
	//m_cameraX = 0;
	//m_cameraY = 0;
	m_timer = 0;

	//graph stuff
	m_graph.setNodes();

	m_agent = new Agent(m_graph, m_2dRenderer, m_graph.getSingleNode(2));
	m_mousePos = {m_agent->getPos()->getPosition().x, m_agent->getPos()->getPosition().y};

	return true;
}


void Application2D::shutdown() {
	
	delete m_audio;
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	//if mouse clicked, find if on a valid node and store vector position of this node in m_mousePos
	if(input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT)){
		 Vector2 tmpMousePos = {(float)aie::Input::getInstance()->getMouseX() - (1280 / 2), (float)aie::Input::getInstance()->getMouseY() - (720 / 2)};
		for(int i = 0; i < m_graph.getNodes().size(); i++){
			Vector2 currentNodePos = m_graph.getNodes()[i]->getPosition();
			float distance = sqrt(((currentNodePos.x - tmpMousePos.x) * (currentNodePos.x - tmpMousePos.x)) + ((currentNodePos.y - tmpMousePos.y) * (currentNodePos.y - tmpMousePos.y)));
			//if node isn't null And the node is within range of the mouse click, will set end point to be this position clicked
			if(m_graph.getNodes()[i]->getData() != "NULL" && distance < 20){
				m_mousePos = m_graph.getNodes()[i]->getPosition();
				m_agent->m_seekPathBehav->setEndpoint(m_graph.getNodes()[i]);
			}
		}
	}

	m_agent->Update(deltaTime);
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	m_graph.Draw(m_2dRenderer);
	m_agent->Draw();
	m_2dRenderer->drawCircle(m_mousePos.x, m_mousePos.y, 10);
	// done drawing sprites
	m_2dRenderer->end();
}