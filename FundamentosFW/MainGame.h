#pragma once
#include <SDL\SDL.h>
#include <GL\glew.h>
#include "GLS_Program.h"
#include "Window.h"
#include "Camera2D.h"
#include <vector>
#include "SpriteBacth.h"
#include "InputManager.h"
#include "Timing.h"
#include "Background.h"
#include "Ship.h"
#include "EnemyShip.h"

enum class GameState
{
	PLAY, EXIT
};


class MainGame
{
private:
	int _witdh;
	int _height;
	float _time;
	Window _window;
	Background* background;
	void init();
	void procesInput();
	GLS_Program _program;
	Camera2D _camera;
	SpriteBacth _spriteBacth;
	InputManager _inputManager;
	FpsLimiter _fpsLimiter;
	Ship* _ship;
	vector<EnemyShip*> _enemies;
	void gameLoop();
	float _previusTicks;
	void initLevel();
	void updateAgents(float deltaTime);
	
public:
	MainGame();
	~MainGame();
	float _fps;
	GameState _gameState;
	void initShaders();
	void run();
	void draw();
	void update();
};

