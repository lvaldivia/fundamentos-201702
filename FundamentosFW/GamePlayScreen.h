#pragma once
#include "IGameScreen.h"
#include "Window.h"
#include "GLS_Program.h"
#include "SpriteBacth.h"
#include "Camera2D.h"

class GamePlayScreen : public IGameScreen
{
private:
	Window* _window;
	GLS_Program _program;
	SpriteBacth _spriteBacth;
	Camera2D _camera2D;
public:
	GamePlayScreen(Window* window);
	void checkInput() override;
	void onEntry() override;
	void initSystem() override;
	void build() override;
	void onExit() override;
	void draw() override;
	void destroy() override;
	void update() override;
	void initGUI() override;
	int getNextScreen() const override;
	int getPreviousScreen() const override;
	~GamePlayScreen();
};

