#pragma once

#include "GameObject.h"
#include "EnemyObject.h"
#include "ProjectileObject.h"

// Inherits from GameObject
class TowerObject : public GameObject {
public:
	TowerObject(glm::vec3 &entityPos, GLuint entityTexture, GLuint turrTex,GLuint bulTex, std::vector<GLuint> explosion,GLint entityNumElements,std::string type);

	// Update function for moving the player object around
	virtual void update(double deltaTime) override;

	// Renders the GameObject using a shader
	virtual void  render(Shader &shader) override;
	void setCurrEnemy(EnemyObject* enemy) {currentEnemy = enemy; }
	
private:
	float rotationSpeed;

	//*********Finite State Machine******
	enum State {
		Init,
		Idle,
		Locate,
		Fire,
		Death
	};

	State _state;
	
	void deathAnimation();
	void locateEnemy();
	void fireEnemy();
	//***********************************
	GLuint turretTexture;
	GLuint projectileTex;

	EnemyObject* currentEnemy;

	int fireRate, frames;
	GLint size;
	std::vector<GLuint> explosion_tex;
	std::vector<ProjectileObject*> bullObjects;


};