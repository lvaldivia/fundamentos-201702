#include "Button.h"
#include "ResourceManager.h"
#include <glm\glm.hpp>


Button::Button(std::string texture):_texture(texture)
{
}

void Button::draw(SpriteBacth& spritebatch) {
	static int textureID = ResourceManager::getTexture(_texture).id;
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	ColorRGBA  color;
	color.set(255, 255, 0, 255);
	glm::vec4 destRect(400, 300, 190, 49);
	spritebatch.draw(destRect, uvRect, textureID, 0.0f, color);
}

Button::~Button()
{
}
