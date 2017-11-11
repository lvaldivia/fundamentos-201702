#include "GamePlayScreen.h"
#include "ScreenIndices.h"
#include "Game.h"

GamePlayScreen::GamePlayScreen(Window* window): _window(window)
{
	_screenIndex = SCREEN_INDEX_GAME;
}

GamePlayScreen::~GamePlayScreen()
{
}


void  GamePlayScreen::initSystem() {
}
void  GamePlayScreen::build() {
}

void  GamePlayScreen::onExit() {}
void  GamePlayScreen::draw() {
}
void  GamePlayScreen::destroy() {
}
void  GamePlayScreen::update() {
}

void GamePlayScreen::initGUI() {

}

void GamePlayScreen::onEntry() {
	initSystem();
}

void GamePlayScreen::checkInput() {
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		_game->onSDLEvent(evnt);

	}
}

int GamePlayScreen::getNextScreen()const {
	return SCREEN_INDEX_GAME;
}

int GamePlayScreen::getPreviousScreen()const {
	return SCREEN_INDEX_NO_SCREEN;
}

