#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <glm/glm.hpp>			//OpenGL Mathematics 
#include "Vertex.h"
#include "GameElement.h"
#include <vector>

using namespace std;

class Geometry
{
	vector <GameElement> gameElements;
	Vertex *_data;
public:
	Geometry();
	~Geometry();
	void LoadScene();
	void CreateCube(int position);
	Vertex* ReturnData();
	glm::vec3 returnScale(int i);
	void Translate(int object, float x, float y, float z);
	glm::vec3 returnTranslate(int i);
};

