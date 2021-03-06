#include "WellScene.h"
#include <string>

WellScene::WellScene(ShaderProgram *shader, ShaderProgram *shader2, ShaderProgram *shader3) : GameScene(shader, shader2, shader3)
{

}

void WellScene::start()
{
	well = new Ground(rootObject);
	well->transform.setPosition(0, 0, 0);

	well2 = new Well(well);
	well2->transform.setPosition(-30, 0, -20);

	GameObject* rim = new GameObject(well2);
	rim->addMesh(new TubeMesh(3.0f, 1.925f, 0.1f));
	rim->setTexture("textures/ring.png");
	rim->transform.translate(0.0f, 1.1f, 0.0f);


	createAvenue();
	GameObject* bench = new Bench(rootObject);
	bench->transform.setPosition(-33.0f, 0.0f, -15.0f);
	
	createForest(-120, 10, 30, 6, 20);
	createForest(-120, -60, 30, 6, 20);
	createForest(-100, -20, 10, 2, 6);
	createForest(5, -20, 10, 2, 6);
}

void WellScene::update(float delta)
{

}

void WellScene::createAvenue()
{
	const float spaceBetweenLamps = 19;

	GameObject *avenue = new GameObject(rootObject);
	

	for (int x = -10; x <= 20; ++x)
	{
		GameObject *lamp = new Lamp(avenue);
		lamp->setTexture("textures/rusty.png");
		lamp->transform.translate(x * spaceBetweenLamps, 0, 0);
		//int tmp = x + 10;
		//auto s = std::to_string(tmp);
		//std::string point = "pointLightsPosition[" + s + "].position";
		shader->Use();
		//glUniform3f(glGetUniformLocation(shader->get_programID(), point.c_str()), x * spaceBetweenLamps , 4, 0);
	}
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition0"), -10 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition1"), -9 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition2"), -8 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition3"), -7 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition4"), -6 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition5"), -5 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition6"), -4 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition7"), -3 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition8"), -2 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition9"), -1 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition10"), -0 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition11"), 1 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition12"), 2 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition13"), 3 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition14"), 4 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition15"), 5 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition16"), 6 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition17"), 7 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition18"), 8 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition19"), 9 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition20"), 10 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition21"), 11 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition22"), 12 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition23"), 13 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition24"), 14 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition25"), 15 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition26"), 16 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition27"), 17 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition28"), 18 * spaceBetweenLamps, 4, 0);
	glUniform3f(glGetUniformLocation(shader->get_programID(), "pointLightsPosition29"), 19 * spaceBetweenLamps, 4, 0);

	GameObject* sidewalk = new GameObject(avenue);
	sidewalk->addMesh(new PlaneMesh(1000.0f, 4.0f, 1000.0f, 4.0f));
	sidewalk->setTexture("textures/asphalt.png");
	sidewalk->transform.setPosition(-10.0f, 0.01f, -5.0f);


}

void WellScene::testObject()
{

	GameObject* test = new TestObject(rootObject);

	//GameObject* object = new TestObject(test);
	test->transform.translate(10.0f, 10.0f, 10.0f);
	//test->transform.setScale(0.01f, 0.01f, 0.01f);

}

void WellScene::createForest(float transX, float transZ, float sizeX, float sizeZ, int howMany)
{
	const float dx = 6;
	const float dy = 6;

	const float tz = transZ;
	const float tx = transX;

	const int toPick = howMany;
	int sn = 0;

	std::vector<glm::vec3> spots;
	std::vector<glm::vec3> picked;
	
	for (int i = 0; i < sizeX; ++i)
	{
		for (int j = 0; j < sizeZ; ++j)
		{
			spots.push_back(glm::vec3(dx* i + tx, 0, dx * j + tz));
			sn++;
		}
	}

	for (int i = 0; i < toPick; ++i)
	{
		int r = randomInt(0, sn - i);
		std::swap(spots[r], spots[sn - i - 1]);
	}

	for (int i = sn - toPick; i < sn; ++i)
	{
		GameObject *tree = new Tree(rootObject);
		tree->transform.setPosition(spots[i]);
		tree->transform.translate(randomFloat(-1, 1), randomFloat(-1, 0), randomFloat(-1, 1));
		tree->transform.setScale(randomFloat(0.75f, 1));
	}
}