#ifndef CHAIN_H
#define CHAIN_H

#include "GameObject.h"
#include "ChLinkMesh.h"
#include "CubeMesh.h"

class Chain : public GameObject
{
public:
	Chain(GameObject* parent);
	Chain(GameObject* parent, unsigned int lenght, float rollerRadius);

	void start();
	void update(float delta);
	void unroll(float radius);
	void tellRotation(GLfloat);
private:
	const unsigned int lenght;
	unsigned int freeLinks;

	GLfloat rollerRadius;
	GLfloat rotation;
	GLfloat lastRotation;

	bool state;
	GameObject* hook;
	GameObject* stateChanger;
};

#endif // !CHAIN_H

