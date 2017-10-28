#include <iomanip> 
#include "Transform.h"
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>
#include "InputFile.h"
#include <glm/gtc/quaternion.hpp>


Transform rotation;
Transform translation;
Transform scale;
Transform combined;

void PrintTransform(Transform& t)
{
	glm::mat4 modelMatrix = t.GetModelMatrix();
	for (size_t i = 0; i < modelMatrix.length(); i++)
	{

		for (size_t j = 0; j < modelMatrix.length(); j++)
		{
			std::cout << std::setw(10) << std::left << modelMatrix[j][i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cin.get(); 
}

void Initialize()
{

	rotation.SetRotation(45, 90, 30);
	PrintTransform(rotation);

	translation.SetPosition(3, 5, -7);
	PrintTransform(translation);

	scale.SetScale(2, 3, 4);
	PrintTransform(scale);

	combined.SetRotation(45, 90, 30);
	combined.SetPosition(3, 5, -7);
	combined.SetScale(2, 3, 4);
	PrintTransform(combined);
}

int main(int argc, char* argv[])
{
	Initialize();
	return 0;
}