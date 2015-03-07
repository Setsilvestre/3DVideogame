#include "Geometry.h"
#define MAXVERTICES 36

Geometry::Geometry(){
	_data = 0;
}

Geometry::~Geometry(){
	if (_data != 0){
		delete[]_data;
	}
}

void Geometry::LoadScene(){
	fstream myfile;
	string line, x, y, z;
	GameElement myElement;
	myfile.open("Vertex.txt", ios::in);
	myfile >> line;
	int lenght;
	lenght = stoi(line);
	_data = new Vertex[lenght*(MAXVERTICES + 1)];
	for (int i = 0; i < lenght; i++){
		gameElements.push_back(myElement);
		for (int j = 0; j < 11; j++){
			if (j==0){
				myfile >> line;
				gameElements[i].idObject = stoi(line);
				if (gameElements[i].idObject == 0){
					CreateCube(i);
				}
			}
			if (j >=1 && j<=3){
				myfile >> x;
				myfile >> y;
				myfile >> z;
				gameElements[i].translate = glm::vec3(stof(x), stof(y), stof(z));
				j = 3;
			}
			if (j ==4 ){
				myfile >> x;
				gameElements[i].angle = stof(x);
			}
			if (j>=5 && j<=7 ){
				myfile >> x;
				myfile >> y;
				myfile >> z;
				gameElements[i].rotate = glm::vec3(stof(x), stof(y), stof(z));
				j = 7;
			}
			if (j >=8 && j<=10 ){
				myfile >> x;
				myfile >> y;
				myfile >> z;
				gameElements[i].scale = glm::vec3(stof(x), stof(y), stof(z));
				j = 10;
			}
		}
	}
	myfile.close();
}

void Geometry::CreateCube(int position){
	_data[position * 35 + 0].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position * 35 + 1].setPosition(-1.0f, -1.0f, 1.0f);
	_data[position * 35 + 2].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position * 35 + 3].setPosition(1.0f, 1.0f, -1.0f);
	_data[position * 35 + 4].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position * 35 + 5].setPosition(-1.0f, 1.0f, -1.0f);
	_data[position * 35 + 6].setPosition(1.0f, -1.0f, 1.0f);
	_data[position * 35 + 7].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position * 35 + 8].setPosition(1.0f, -1.0f, -1.0f);
	_data[position * 35 + 9].setPosition(1.0f, 1.0f, -1.0f);
	_data[position * 35 + 10].setPosition(1.0f, -1.0f, -1.0f);
	_data[position * 35 + 11].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position * 35 + 12].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position * 35 + 13].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position * 35 + 14].setPosition(-1.0f, 1.0f, -1.0f);
	_data[position * 35 + 15].setPosition(1.0f, -1.0f, 1.0f);
	_data[position * 35 + 16].setPosition(-1.0f, -1.0f, 1.0f);
	_data[position * 35 + 17].setPosition(-1.0f, -1.0f, -1.0f);
	_data[position * 35 + 18].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position * 35 + 19].setPosition(-1.0f, -1.0f, 1.0f);
	_data[position * 35 + 20].setPosition(1.0f, -1.0f, 1.0f);
	_data[position * 35 + 21].setPosition(1.0f, 1.0f, 1.0f);
	_data[position * 35 + 22].setPosition(1.0f, -1.0f, -1.0f);
	_data[position * 35 + 23].setPosition(1.0f, 1.0f, -1.0f);
	_data[position * 35 + 24].setPosition(1.0f, -1.0f, -1.0f);
	_data[position * 35 + 25].setPosition(1.0f, 1.0f, 1.0f);
	_data[position * 35 + 26].setPosition(1.0f, -1.0f, 1.0f);
	_data[position * 35 + 27].setPosition(1.0f, 1.0f, 1.0f);
	_data[position * 35 + 28].setPosition(1.0f, 1.0f, -1.0f);
	_data[position * 35 + 29].setPosition(-1.0f, 1.0f, -1.0f);
	_data[position * 35 + 30].setPosition(1.0f, 1.0f, 1.0f);
	_data[position * 35 + 31].setPosition(-1.0f, 1.0f, -1.0f);
	_data[position * 35 + 32].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position * 35 + 33].setPosition(1.0f, 1.0f, 1.0f);
	_data[position * 35 + 34].setPosition(-1.0f, 1.0f, 1.0f);
	_data[position * 35 + 35].setPosition(1.0f, -1.0f, 1.0f);
	for (int i = 0; i < 36; i++){
		_data[position * 35 + i].setColor(121,515,154,255);
	}
}

Vertex* Geometry::ReturnData(){
	return _data;
}

glm::vec3 Geometry::returnScale(int i){
	return gameElements[i].scale;
}

glm::vec3 Geometry::returnTranslate(int i){
	return gameElements[i].translate;
}

void Geometry::Translate(int object, float x, float y, float z){

}