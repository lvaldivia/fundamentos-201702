#include "MainGame.h"
#include "Sprite.h"
#include <iostream>
#include <glm\glm.hpp>
using namespace std;

void MainGame::run() {
	init();
	_sprites.push_back(new Sprite());
	_sprites.back()->init(-1, -1, 1, 1, "Images/imagen.png");
	_sprites.push_back(new Sprite());
	_sprites.back()->init(0, -1, 1, 1, "Images/imagen.png");
	update();
}
void MainGame::init() {

	SDL_Init(SDL_INIT_EVERYTHING);
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

	for (size_t i = 0; i < _sprites.size(); i++)
	{
		_sprites[i]->draw();
	}
	_program.unuse();
	_window.swapWindow();
}

void MainGame::handleInput() {
	if (_inputManager.isKeyPressed(SDLK_w)) {
		cout << "arriba" << endl;
		_camera2D.setPosition(_camera2D.getPosition()
			+ glm::vec2(0.0, -CAMERA_SPEED));
		cout << _camera2D.getPosition().x << _camera2D.getPosition().y << endl;
	}
	if (_inputManager.isKeyPressed(SDLK_s)) {
		cout << "abajo" << endl;
		_camera2D.setPosition(_camera2D.getPosition()
			+ glm::vec2(0.0, CAMERA_SPEED));
		cout << _camera2D.getPosition().x << _camera2D.getPosition().y << endl;
	}
	if (_inputManager.isKeyPressed(SDLK_a)) {
		cout << "izquierda" << endl;
		_camera2D.setPosition(_camera2D.getPosition()
			+ glm::vec2(CAMERA_SPEED, 0.0));
		cout <<  _camera2D.getPosition().x << _camera2D.getPosition().y << endl;
	}
	if (_inputManager.isKeyPressed(SDLK_d)) {
		cout << "derecha" << endl;
		_camera2D.setPosition(_camera2D.getPosition()
			+ glm::vec2(-CAMERA_SPEED, 0.0));
		cout << _camera2D.getPosition().x << _camera2D.getPosition().y << endl;
	}
	if (_inputManager.isKeyPressed(SDLK_q)) {}
	if (_inputManager.isKeyPressed(SDLK_e)) {}
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
		_camera2D.update();
		
	}
}


MainGame::MainGame() :  
						_witdh(800),_height(600),
						_gameState(GameState::PLAY),
						_time(0)
				
{
	_camera2D.init(_witdh, _height);
}


MainGame::~MainGame()
{
}
