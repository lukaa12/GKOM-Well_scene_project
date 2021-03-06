#include "Transform.h"

Transform::Transform()
{
	position = glm::vec3(0.0f);
	rotation = glm::vec3(0.0f);
	scale = glm::vec3(1.0f);
}

void Transform::setPosition(const glm::vec3 &position)
{
	this->position = position;
}

void Transform::setRotation(const glm::vec3 &rotation)
{
	this->rotation = rotation;
}

void Transform::setScale(const glm::vec3 &scale)
{
	this->scale = scale;
}

void Transform::setPosition(float x, float y, float z)
{
	setPosition(glm::vec3(x, y, z));
}

void Transform::setRotation(float x, float y, float z)
{
	setRotation(glm::vec3(x, y, z));
}

void Transform::setScale(float x, float y, float z)
{
	setScale(glm::vec3(x, y, z));
}

void Transform::setScale(float scale)
{
	setScale(glm::vec3(scale, scale, scale));
}

void Transform::translate(const glm::vec3 &position)
{
	this->position += position;
}

void Transform::rotate(const glm::vec3 &rotation)
{
	this->rotation += rotation;
}

//void Transform::scale(const glm::vec3 &scale)
//{
//	this->scale *= scale;
//}

void Transform::translate(float x, float y, float z)
{
	translate(glm::vec3(x, y, z));
}

void Transform::rotate(float x, float y, float z)
{
	rotate(glm::vec3(x, y, z));
}

//void Transform::scale(float x, float y, float z)
//{
//	scale(glm::vec3(x, y, z));
//}

glm::vec3 Transform::getPosition() const
{
	return position;
}

glm::vec3 Transform::getRotation() const
{
	return rotation;
}

glm::vec3 Transform::getScale() const
{
	return scale;
}

glm::vec3 Transform::getGlobalPosition() const
{
	return lastGlobalPosition;
}

glm::vec3 Transform::getGlobalRotation() const
{
	return lastGlobalRotation;
}

glm::vec3 Transform::getGlobalScale() const
{
	return lastGlobalScale;
}

glm::mat4 Transform::getTransform()
{
	return getTransform(glm::mat4());
}

//glm::vec4 Transform::getTransform(const Transform &parentTransform)
//{
//	return getTransform(parentTransform.getLastTransform());
//}

glm::mat4 Transform::getTransform(const glm::mat4 &parentTransform)
{
	lastGlobalPosition = glm::vec3(glm::vec4(position, 1.0f) * parentTransform);
	lastGlobalRotation = glm::vec3(glm::vec4(rotation, 1.0f) * parentTransform);
	lastGlobalScale = glm::vec3(glm::vec4(scale, 1.0f) * parentTransform);

	glm::mat4 temp = glm::mat4(1.0f);

	temp = glm::translate(temp, position);

	temp = glm::rotate(temp, glm::radians(rotation.y), glm::vec3(0, 1, 0));
	temp = glm::rotate(temp, glm::radians(rotation.x), glm::vec3(1, 0, 0));
	temp = glm::rotate(temp, glm::radians(rotation.z), glm::vec3(0, 0, 1));

	temp = glm::scale(temp, scale);

	return parentTransform * temp;
}