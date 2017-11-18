#include "Ship.h"



Ship::Ship(float agent_width, float agent_height, glm::vec2 position,std::string texture):
				Agent(agent_width,agent_height, position,texture)
{
	
}

void Ship::update(float deltaTime) {}


Ship::~Ship()
{
}
