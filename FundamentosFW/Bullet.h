#pragma once
#include <glm\glm.hpp>
#include "SpriteBatch.h"
#include "Agent.h"

const int BULLET_RADIUS = 5;

class Bullet : public Agent
{
private :
	glm::vec2 _direction;
	float _damage;

public:
	Bullet(glm::vec2 position, glm::vec2 direction,		
					float damage, float _speed);
	void draw(SpriteBacth& spriteBatch);
	void update(std::vector<Human*> &humans,
		std::vector<Zombie*> &zombies);
	~Bullet();
};

