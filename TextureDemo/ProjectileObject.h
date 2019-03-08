#pragma once
#include "GameObject.h"
#include "EnemyObject.h"
class ProjectileObject : public GameObject
{
public:
	ProjectileObject(glm::vec3 &entityPos, GLuint entityTexture, std::vector<GLuint> explosion,GLint entityNumElements, std::string type, EnemyObject* enemy, float angle, float s);

	// Update function for moving the player object around
	virtual void update(double deltaTime) override;
	void setCurrEnemy(EnemyObject* enemy) { target = enemy; }

	bool getExists() { return exists; }
private:
	float damage;
	float distance;
	bool exists;
	glm::vec3 orgCoord;
	EnemyObject* target;
	std::vector<GLuint> explosion_tex;
	int explosion_num;
};
