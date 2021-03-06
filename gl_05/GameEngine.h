#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#define GLEW_STATIC
#include <GL/glew.h>
#include "shprogram.h"
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "InputManagers.h"
#include "Skybox.h"
#include "WellScene.h"
#include "Light.h"

class GameEngine
{
public:
	static GameEngine &getInstance();

	void init();
	void run();

private:
	static GameEngine *instance;
	GLFWwindow *window;
	ShaderProgram *theProgram;
	ShaderProgram *lightSrcProgram;
	ShaderProgram *waterProgram;
	GameScene *gameScene;

	GLuint cubemapTexture;
	glm::vec3 cameraPosition;
	glm::vec2 cameraRotation;

	GameEngine();

	GLuint screenWidth = 1280, screenHeight = 720, controll = 0;
	GLfloat lightIntensity;

	double currentFrame, deltaTime, lastFrame;

	std::pair<glm::mat4, glm::mat4> setCamera();
	void updateDeltaTime();

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void window_size_callback(GLFWwindow* window, int width, int height);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

	void handleKeyboardEvent();
	void handleMouseEvent();
	void handleScreenResizeEvent(int widht, int height);
	void decreaseLight();
	void increaseLight();

	KeyboardManager keyboardManager;
	MouseManager mouseManager;
};

#endif