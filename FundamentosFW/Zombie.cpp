#include "Zombie.h"



Zombie::Zombie()
{

}

void Zombie::init(float speed, glm::vec2 position) {
	_speed = speed;
	_position = position;
}

void Zombie::update(const std::vector<std::string>& levelData,
	std::vector<Human*>& humans,
	std::vector<Zombie*>& zombies){

}

Zombie::~Zombie()
{
}
