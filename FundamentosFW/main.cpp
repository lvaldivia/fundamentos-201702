#include <SDL\SDL.h>
#include "MainGame.h"
#include "App.h"

int main(int argc,char** argv) {
	SDL_Init(SDL_INIT_EVERYTHING);
	App app;
	app.run();
	/*MainGame mainge;
	mainge.run();*/
	system("PAUSE");
	return 0;
}