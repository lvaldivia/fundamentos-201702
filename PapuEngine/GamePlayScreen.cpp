#include "GamePlayScreen.h"
#include "Game.h"
#include "ScreenIndices.h"

#include "ResourceManager.h"
#include <random>


bool GamePlayScreen::onExitClicked()
{
	_currentState = ScreenState::EXIT_APPLICATION;
	return true;
}

GamePlayScreen::GamePlayScreen(Window* window):
	_window(window)
{
	_screenIndex = SCREEN_INDEX_GAMEPLAY;
}

GamePlayScreen::~GamePlayScreen()
{
}

void GamePlayScreen::build() {

}

void GamePlayScreen::destroy() {

}

void GamePlayScreen::onExit() {
}

void GamePlayScreen::onEntry() {
	initWorld();
	initSystem();
	_spriteBatch.init();
	_hudBatch.init();
	initGUI();
	_camera2d.init(_window->getScreenWidth(),
		_window->getScreenHeight());
	_camera2d.setPosition(
		glm::vec2(_window->getScreenWidth() / 2.0f,
			_window->getScreenHeight() / 2.0f));
	
	_background = new Background("Textures/naves/game.png");
	_ship = new Ship(106, 79, glm::vec2(_window->getScreenWidth() / 2.0f, 100), "Textures/naves/Player.png",&_game->_inputManager);

	_hudCamera.init(_window->getScreenWidth(),
		_window->getScreenHeight());
	_hudCamera.setPosition(
		glm::vec2(_window->getScreenWidth() / 2.0f,
				_window->getScreenHeight() / 2.0f));

	_spriteFont = new SpriteFont("Fonts/arial.ttf",64);
}

void GamePlayScreen::initWorld() {
	
}

void GamePlayScreen::initGUI()
{

}

void GamePlayScreen::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_program.use();
	GLuint pLocation =
		_program.getUniformLocation("P");

	glm::mat4 cameraMatrix = _camera2d.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	GLuint imageLocation = _program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);
	_spriteBatch.begin();

	_ship->draw(_spriteBatch);
	_background->draw(_spriteBatch);
	_spriteBatch.end();
	_spriteBatch.renderBatch();

	drawHUD();
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);
	_program.unuse();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
void GamePlayScreen::update() {
	_camera2d.update();
	_hudCamera.update();
	_ship->update(1.0f);
	checkInput();
}

void  GamePlayScreen::drawHUD() {
	GLuint pLocation =
		_program.getUniformLocation("P");

	glm::mat4 cameraMatrix = _hudCamera.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	char buffer[256];

	_hudBatch.begin();
	sprintf_s(buffer, " BULLETS %d", 10);
	_spriteFont->draw(_hudBatch, buffer, glm::vec2(0, 0),
		glm::vec2(0.5), 0.0f, ColorRGBA(255, 255, 255, 255));
	sprintf_s(buffer, " SCORE %d", 10);
	_spriteFont->draw(_hudBatch, buffer, glm::vec2(0, 36),
		glm::vec2(0.5), 0.0f, ColorRGBA(255, 255, 255, 255));
	_hudBatch.end();
	_hudBatch.renderBatch();

}

void GamePlayScreen::initSystem()
{
	_program.compileShaders("Shaders/colorShaderVert.txt",
		"Shaders/colorShaderFrag.txt");
	_program.addAtribute("vertexPosition");
	_program.addAtribute("vertexColor");
	_program.addAtribute("vertexUV");
	_program.linkShader();
}


void GamePlayScreen::checkInput() {
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		_game->onSDLEvent(evnt);
	}
}

int GamePlayScreen::getNextScreen() const {
	return SCREEN_INDEX_NO_SCREEN;
};

int GamePlayScreen::getPreviousScreen() const {
	return SCREEN_INDEX_MENU;
}
