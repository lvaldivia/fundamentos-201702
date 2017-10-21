#pragma once
#include "Agent.h"

class Human : public Agent
{
private:
	glm::vec2 _direction;
public:
	void init(float speed, glm::vec2 position);
	Human();
	~Human();
	void update(
		const std::vector<std::string>& levelData,
		std::vector<Human*>& humans,
		std::vector<Zombie*>& zombies
	);
};

