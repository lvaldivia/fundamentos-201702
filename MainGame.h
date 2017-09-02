#pragma once
#include <SDL\SDL.h>
#include <glew\glew.h>
#include "GLS_Program.h"
#include "Sprite.h"

enum class GameState {
	PLAY, EXIT
};

class MainGame{
private:
	int _width;
	int _height;
	void init();
	GLS_Program _program;
	Sprite _sprite;
	SDL_Window* _window;
	void processInput();
	void initShaders();
public:
	MainGame();
	~MainGame();
	GameState _gameState;
	void run();
	void draw();
	void update();
};

