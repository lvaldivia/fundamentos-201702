#pragma once
#include "Agent.h"
class Ship :public Agent
{
public:
	Ship(float agent_width, float agent_height, glm::vec2 position,std::string texture);
	void update(float deltaTime);
	~Ship();
};

