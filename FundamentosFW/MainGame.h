#pragma once
#include <SDL\SDL.h>
#include <GL\glew.h>
#include "GLS_Program.h"
#include "Sprite.h"
#include "Window.h"
#include <vector>
#include "Camera2D.h"
#include "InputManager.h"

enum class GameState
{
	PLAY, EXIT
};


class MainGame
{
private:
	int _witdh;
	int _height;
	//SDL_Window* _window;
	void init();
	vector<Sprite*> _sprites;
	Camera2D _camera2D;
	InputManager _inputManager;
	Window _window;
	GLS_Program _program;
	float _time;
	void processInput();
	void handleInput();
	const float CAMERA_SPEED = 0.5f;
	const float SCALE_SPEED = 0.1f;

public:
	MainGame();
	~MainGame();
	GameState _gameState;
	void initShaders();
	void run();
	void draw();
	void update();
};

