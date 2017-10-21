#include "Gun.h"
#include <ctime>
#include <random>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm\gtx\rotate_vector.hpp>


Gun::Gun(std::string name, int fireRate,
	int bulletsPershot, float bulletDamage,
	float bulletSpeed)
	: _name(name),
	_fireRate(fireRate),
	_bulletDamage(bulletDamage),
	_bulletsPershot(bulletsPershot),
	_bulletSpeed(bulletSpeed)

{
	
}

void Gun::update(bool isMouseDown,
	const glm::vec2& position,
	const glm::vec2& direction,
	std::vector<Bullet>& bullets,
	float deltaTime
) {

	
}

void Gun::fire(const glm::vec2& direction, 
			   const glm::vec2& position,
			   std::vector<Bullet>& bullets
	
	) {
	static std::mt19937 randonEngine(time(nullptr));
	std::uniform_real_distribution<float>
		randRotate(-_spread, _spread);

	for (int i = 0; i < _bulletPerShot; i++)
	{

	}

}


Gun::~Gun()
{
}
