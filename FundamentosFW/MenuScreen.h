#pragma once
#include "SpriteBacth.h"
#include "IGameScreen.h"
#include "Window.h"
#include "GLS_Program.h"
#include "Camera2D.h"
#include "Background.h"

class MenuScreen : public IGameScreen
{
private:
	Window* _window = nullptr;
	GLS_Program _program;
	SpriteBacth _spriteBacth;
	Camera2D _camera2D;
	Background* _background;

public:
	MenuScreen(Window *window);
	 void checkInput() override;
	 void initSystem() override;
	 void build() override;
	 void onExit() override;
	 void onEntry() override;
	 void draw() override;
	 void destroy() override;
	 void update() override;
	 void initGUI() override;
	 int getNextScreen() const override;
	 int getPreviousScreen() const override;
	~MenuScreen();
};

