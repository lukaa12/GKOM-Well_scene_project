#ifndef SKYBOX_H
#define SKYBOX_H
#include <iostream>
#include <string>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "SOIL.h"
#include "shprogram.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class Skybox
{
public:
	void start();
	void render(glm::mat4 view, glm::mat4 projection);
	void destroy();
	GLuint getCubemapTexture();
private:
	GLuint skyboxVAO, skyboxVBO;
	GLuint cubemapTexture;
	ShaderProgram* skyboxProgram;
	std::vector<std::string> faces;
	void setupBuffers(GLfloat skyboxVercities[]);
};
#endif

