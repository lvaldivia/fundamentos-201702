#include "Zombie.h"
#include "Human.h"

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

	Human* closeHuman = getNearestHuma(humans);
	if (closeHuman != nullptr) {
		glm::vec2 direction = glm::normalize(
			closeHuman->getPosition() - _position);
		_position += direction*_speed;
	}
}

Human* Zombie::getNearestHuma(std::vector<Human*>& humans) {
	Human* closeHuman = nullptr;
	float smallDistance = 888888888888888888888888.0f;
	for (size_t i = 0; i < humans.size(); i++)
	{
		glm::vec2 dist = humans[i]->getPosition() - _position;
		float distance = glm::length(dist);
		if (distance < smallDistance) {
			smallDistance = distance;
			closeHuman = humans[i];
		}
	}
	return closeHuman;
}

Zombie::~Zombie()
{
}
