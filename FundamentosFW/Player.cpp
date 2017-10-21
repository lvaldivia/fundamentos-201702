#include "Player.h"
#include <SDL\SDL.h>


Player::Player()
{
}


void Player::init(float speed, glm::vec2 position, InputManager* inputManager) {
	_speed = speed;
	_inputManager = inputManager;
	_position = position;
	color.set(0, 0, 185, 255);
}

void Player::update(const std::vector<std::string>& levelData,
					std::vector<Human*>& humans,
					std::vector<Zombie*>& zombie) {
	if (_inputManager->isKeyPressed(SDLK_w)) {
		_position.y += _speed;
		
	}
	if (_inputManager->isKeyPressed(SDLK_s)) {
		_position.y -= _speed;
	}
	if (_inputManager->isKeyPressed(SDLK_a)) {
		_position.x -= _speed;
	}
	if (_inputManager->isKeyPressed(SDLK_d)) {
		_position.x += _speed;
	}
	collideWithLevel(levelData);
}


Player::~Player()
{
}
