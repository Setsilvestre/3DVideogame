#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <glm/glm.hpp>			//OpenGL Mathematics 
#include "Vertex.h"
#include "GameElement.h"
#include <vector>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;

class Geometry
{
	vector <GameElement> _gameElements;
	Vertex **_data;
	int _numberOfPrimitives;
public:
	Geometry();
	~Geometry();
	void LoadScene();
	void CreateCube(int position);
	Vertex* ReturnData(int position);
	glm::vec3 returnScale(int i);
	void Translate(int object, float x, float y, float z);
	glm::vec3 returnTranslate(int i);
	float returnAngle(int i);
	glm::vec3 returnRotate(int i);
	int returnPrimitives();
	void Move(int i, int j);
	void CreatePyramid(int position);
	void randomMovement();
};

