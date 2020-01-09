#include "GameObject.h"

GameObject::GameObject(GameObject* parent, GameScene *scene) : parent(parent), scene(scene)
{
	if (parent != nullptr)
		parent->addChild(this);
}

GameObject::~GameObject()
{
	parent->removeChild(this);
}

void GameObject::renderObject(const glm::mat4 &parentTransform)
{
	glm::mat4 transformMatrix = transform.getTransform(parentTransform);
	scene->setTransform(transformMatrix);

	for (const auto &mesh : meshes)
	{
		mesh->render();
	}

	render();

	for (auto &child : children)
	{
		child->renderObject(transformMatrix);
	}
}

void GameObject::updateObject(float delta)
{
	update(delta);

	for (auto &child : children)
	{
		child->updateObject(delta);
	}
}

void GameObject::startObject()
{
	start();

	for (auto &mesh : meshes)
	{
		mesh->start();
	}
}

void GameObject::render()
{
	//TODO: temp solution. Discuss setting transform in engine when iterating over all gameobjects
	//GameEngine::getInstance().setTransform(transform.getTransform());
	//glm::mat4 trans = transform.getTransform();
	//scene->setTransform(transform.getTransform(parent);

	//for (const auto &mesh : meshes)
	//{
	//	mesh->render();
	//}

	//for (auto &child : children)
	//{
	//	child->render();
	//}
}

void GameObject::update(float delta)
{

}

void GameObject::start()
{

}

void GameObject::destroy()
{

}

void GameObject::addChild(GameObject *child)
{
	auto itGameObject = find(children.begin(), children.end(), child);
	if (itGameObject != children.end()) return;

	children.push_back(child);
}

void GameObject::removeChild(GameObject *child)
{
	auto objectToRemove = find(children.begin(), children.end(), child);
	iter_swap(objectToRemove, children.end() - 1);
	children.pop_back();
}