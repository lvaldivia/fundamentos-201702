#pragma once
#include "SpriteBacth.h"
#include <glm\glm.hpp>
#include "GLTexture.h"
#include <string>
class Background
{
private:
	std::string _texture;
public:
	void draw(SpriteBacth& spritebatch);
	Background(std::string texture);
	~Background();
};

