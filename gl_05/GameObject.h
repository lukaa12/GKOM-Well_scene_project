#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <vector>
#include <algorithm>
#include "Transform.h"
#include "MeshRenderer.h"
#include "GameScene.h"
#include"Texture.h"

class GameScene;

class GameObject
{
public:
	GameObject(GameObject *parent);
	GameObject(GameScene *scene);
	virtual ~GameObject();

	Transform transform;

	void startObject();
	void destroyObject();
	void renderObject(const glm::mat4 &parentTransform);
	void updateObject(float delta);

	void addChild(GameObject *child);
	void removeChild(GameObject *child);

	virtual void start();
	virtual void destroy();
	virtual void render();
	virtual void update(float delta);

private:
	Texture *texture;

protected:
	GameObject *parent;
	GameScene *scene;

	std::vector<GameObject*> children;
	std::vector<MeshRenderer*> meshes;

	void setTexture(const char *fileName);
};

#endif