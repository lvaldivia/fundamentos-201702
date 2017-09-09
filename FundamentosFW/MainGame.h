#pragma once
#include <SDL\SDL.h>
#include <GL\glew.h>
#include "GLS_Program.h"
#include "Sprite.h"
#include <vector>

enum class GameState
{
	PLAY, EXIT
};


class MainGame
{
private:
	int _witdh;
	int _height;
	SDL_Window* _window;
	void init();
	vector<Sprite*> _sprites;
//	Sprite _sprite;
	void procesInput();
	GLS_Program _program;
	float _time;
public:
	MainGame();
	~MainGame();
	GameState _gameState;
	void initShaders();
	void run();
	void draw();
	void update();
};

