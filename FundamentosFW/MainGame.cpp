#include "MainGame.h"
#include "Sprite.h"

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

	GLuint imageLocation = _program.getUniformLocation("image");
	glUniform1i(imageLocation, 0);

	for (size_t i = 0; i < _sprites.size(); i++)
	{
		_sprites[i]->draw();
	}
	//_sprite.draw();
	_program.unuse();
	_window.swapWindow();
}

void MainGame::procesInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				_gameState = GameState::EXIT;
				break;
			case SDL_MOUSEMOTION:
			break;
		}
	}

}

void MainGame::update() {

	while (_gameState != GameState::EXIT) {
		procesInput();
		draw();
		
	}
}


MainGame::MainGame() :  
						_witdh(800),_height(600),
						_gameState(GameState::PLAY),
						_time(0)
				
{
}


MainGame::~MainGame()
{
}
