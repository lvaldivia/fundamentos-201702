#include "MainGame.h"
#include "Sprite.h"
#include <iostream>
#include <glm\glm.hpp>
#include "Engine.h"
#include <random>
#include <ctime>

using namespace std;
using namespace Papu;

void MainGame::run() {
	init();
	_levels.push_back(new Level("Levels/level1.txt"));
	_currentLevel = 0;
	_spriteBacth.init();
	_player = new Player();
	_player->init(0.2f, _levels[_currentLevel]->getPlayerPosition(),
			&_inputManager);
	_humans.push_back(_player);

	int numHumas = _levels[_currentLevel]->getNumHumans();

	std::mt19937 randonEngne(time(nullptr));

	std::uniform_int_distribution<int>randPosX(
		1, 20
	);

	std::uniform_int_distribution<int>randPosY(
		1,20
	);

	for (int i = 0; i < numHumas; i++)
	{
		_humans.push_back(new Human());
		glm::vec2 pos(randPosX(randonEngne) * TITLE_WIDTH,
			randPosY(randonEngne) * TITLE_WIDTH
		);
		_humans.back()->init(0.02f, pos);
	}

	for (size_t i = 0; i < _levels[_currentLevel]->getZombiesPosition().size(); i++)
	{
		_zombies.push_back(new Zombie());
		_zombies.back()->init(0.02f,_levels[_currentLevel]->getZombiesPosition()[i]);
	}
	update();
}
void MainGame::init() {

	Papu::init();
	_window.create(
			"Hola :D", _witdh, _height, 0);
	initShaders();
}

void MainGame::initShaders() {
	_program.compileShaders("Shaders/ColorShaderVert.txt",
		"Shaders/ColorShaderFrag.txt");
	_program.addAtribute("vertexPosition");
	_program.addAtribute("vertexColor");
	_program.addAtribute("verxtexUV");
	_program.linkShader();
}


void MainGame::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_program.use();
	glActiveTexture(GL_TEXTURE0);

	GLuint timeLocation = _program.getUniformLocation("time");
	glUniform1f(timeLocation, _time);
	_time += 0.0002f;

	GLuint pLocation = _program.getUniformLocation("P");

	glm::mat4 cameraMatrix = _camera2D.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	GLuint imageLocation = _program.getUniformLocation("image");
	glUniform1i(imageLocation, 0);

	_spriteBacth.begin();
	_levels[_currentLevel]->draw();

	for (size_t i = 0; i < _bullets.size(); i++)
	{
		_bullets[i]->draw(_spriteBacth);
	}

	for (size_t i = 0; i < _humans.size(); i++)
	{
		_humans[i]->draw(_spriteBacth);
	}

	for (size_t i = 0; i < _zombies.size(); i++)
	{
		_zombies[i]->draw(_spriteBacth);
	}
	_spriteBacth.end();
	_spriteBacth.renderBatch();

	_program.unuse();

	_window.swapWindow();
}

void MainGame::updateElements() {

	for (size_t i = 0; i < _bullets.size(); i++)
	{
		_bullets[i]->update(_humans, _zombies);
	}

	for (size_t i = 0; i < _humans.size(); i++)
	{
		_humans[i]->update(_levels[_currentLevel]->getLevelData(),
							_humans, _zombies);
	}

	for (size_t i = 0; i < _zombies.size(); i++)
	{
		_zombies[i]->update(
			_levels[_currentLevel]->getLevelData(), _humans, _zombies);
	}
}

void MainGame::handleInput() {
	if (_inputManager.isKeyPressed(SDLK_q)) {
		_camera2D.setScale(_camera2D.getScale() + SCALE_SPEED);
	}
	if (_inputManager.isKeyPressed(SDLK_e)) {
		_camera2D.setScale(_camera2D.getScale() - SCALE_SPEED);
	}
}

void MainGame::processInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				_gameState = GameState::EXIT;
				break;
			case SDL_MOUSEMOTION:
				_inputManager.setMouseCoords(
					event.motion.x, event.motion.y
				);
			break;
			case SDL_KEYDOWN:
				_inputManager.pressKey(
					event.key.keysym.sym);
				break;
			case SDL_KEYUP:
				_inputManager.releaseKey(
					event.key.keysym.sym);
				break;
		}
	}
	handleInput();
}

void MainGame::update() {
	while (_gameState != GameState::EXIT) {
		processInput();
		draw();
		updateElements();
		_camera2D.update();
		_camera2D.setPosition(_player->getPosition());
		
	}
}


MainGame::MainGame() :  
						_witdh(800),_height(600),
						_gameState(GameState::PLAY),
						_time(0),
						_player(nullptr)
				
{
	_camera2D.init(_witdh, _height);
}


MainGame::~MainGame()
{
}
