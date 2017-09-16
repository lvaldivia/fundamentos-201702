#pragma once
#include <string>
#include <vector>
#include "SpriteBatch.h"
#include <glm\glm.hpp>

using namespace std;
const int TITLE_WIDTH = 64;

class Level
{
private:
	vector<string> _levelData;
	int _numHumas;
	void parseLevel();

public:
	glm::vec2 _playerPosition;
	std::vector<glm::vec2> _zombiesPosition;
	glm::vec2 getPlayerPosition() const {
		return _playerPosition;
	};
	std::vector<glm::vec2> getZombiesPosition()const {
		return _zombiesPosition;
	};
	Level(const std::string& fileName);
	void draw();
	SpriteBatch _spriteBatch;
	~Level();
};

