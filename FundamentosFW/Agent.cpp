#include "Agent.h"
#include "ResourceManager.h"
#include "Level.h"
#include <algorithm>


Agent::Agent()
{
}

bool Agent::collideWithLevel(const std::vector<std::string>& levelData) {

	std::vector<glm::vec2> collideTilePosition;

	checkTilePosition(levelData, collideTilePosition,
		_position.x, _position.y);

	checkTilePosition(levelData, collideTilePosition,
		_position.x + AGENT_WIDTH, _position.y);
	checkTilePosition(levelData, collideTilePosition,
		_position.x, _position.y+AGENT_WIDTH);
	checkTilePosition(levelData, collideTilePosition,
		_position.x+AGENT_WIDTH, _position.y + AGENT_WIDTH);

	if (collideTilePosition.size() == 0) return false;

	for (size_t i = 0; i < collideTilePosition.size(); i++)
	{
		collideWithTile(collideTilePosition[i]);
	}

	return true;
}

void Agent::checkTilePosition(
	const std::vector<std::string> &levelData,
	std::vector<glm::vec2>& collideTilePosition,
	float x, float y) {
	glm::vec2 cornerPos = glm::vec2(floor(x / (float)TITLE_WIDTH)
		, floor(y / (float(TITLE_WIDTH)))
	);
	if (cornerPos.x < 0 || cornerPos.x >= levelData[0].size()
		|| cornerPos.y < 0 || cornerPos.y >= levelData[0].size())
	{
		return;
	}

	if (levelData[cornerPos.y][cornerPos.x] != '.') {
		collideTilePosition.push_back(cornerPos
			* (float)TITLE_WIDTH +
			glm::vec2((float)TITLE_WIDTH / 2.0f));
	}
}

void Agent::collideWithTile(glm::vec2 tilePos) {
	const float TILE_RADIUS = (float)TITLE_WIDTH / 2.0f;
	const float MIN_DISTANCE = AGENT_RADIUS +  TILE_RADIUS;

	glm::vec2 centerPosition = _position + glm::vec2(AGENT_RADIUS);
	glm::vec2 distVec = centerPosition - tilePos;
	float xDepth = MIN_DISTANCE - abs(distVec.x);
	float yDepth = MIN_DISTANCE - abs(distVec.y);
	if (xDepth > 0 || yDepth > 0) {
		if (std::max(xDepth,0.0f) < std::max(yDepth,0.0f)) {
			if (distVec.x < 0) {
				_position.x -= xDepth;
			}
			else {
				_position.x += xDepth;
			}
		}
		else {
			if (distVec.y < 0) {
				_position.y -= yDepth;
			}
			else {
				_position.y += yDepth;
			}
		}
	}

}

bool Agent::collideWithAgent(Agent* agent) {
	return false;
}

void Agent::draw(SpriteBacth& spriteBatch) {
	static int textureID = ResourceManager::getTexture("Images/circle.png").id;
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	glm::vec4 destRect(_position.x, _position.y, AGENT_WIDTH, AGENT_WIDTH);
	spriteBatch.draw(destRect, uvRect, textureID, 0.0f, color);
}

Agent::~Agent()
{
}
