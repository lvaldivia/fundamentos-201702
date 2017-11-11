#include "MenuScreen.h"
#include "ScreenIndices.h"
#include "Game.h"


MenuScreen::MenuScreen(Window* window): _window(window)
{
	_screenIndex = SCREEN_INDEX_MENU;
}


void MenuScreen::initGUI() {

}

void MenuScreen::build() {

}

void MenuScreen::destroy() {
	_program.unuse();
}
void MenuScreen::onExit() {

}

void MenuScreen::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_program.use();

	glActiveTexture(GL_TEXTURE0);

	GLuint pLocation =
		_program.getUniformLocation("P");

	glm::mat4 cameraMatrix = _camera2D.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	GLuint imageLocation = _program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);

	_spriteBacth.begin();

	_background->draw(_spriteBacth);
	_spriteBacth.end();
	_spriteBacth.renderBatch();

	glBindTexture(GL_TEXTURE_2D, 0);

	_program.unuse();
}

void MenuScreen::update() {
	checkInput();
	draw();
}

void MenuScreen::initSystem() {
	_program.compileShaders("Shaders/colorShaderVert.txt",
		"Shaders/colorShaderFrag.txt");
	_program.addAtribute("vertexPosition");
	_program.addAtribute("vertexColor");
	_program.addAtribute("vertexUV");
	_program.linkShader();
}

void MenuScreen::onEntry() {
	initSystem();
	_camera2D.init(_window->getScreenWidth(), _window->getScreenHeight());
	_background = new Background("hola");
}

void MenuScreen::checkInput() {
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		_game->onSDLEvent(evnt);
	}
}

int MenuScreen::getNextScreen()const {
	return SCREEN_INDEX_GAME;
}

int MenuScreen::getPreviousScreen()const {
	return SCREEN_INDEX_NO_SCREEN;
}

MenuScreen::~MenuScreen()
{
}
