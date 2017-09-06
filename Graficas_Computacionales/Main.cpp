#include <iostream>
#include <GL/glew.h>
#include<GL/freeglut.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>
template <typename genType>

GLuint vao;
float radianA = 1.0f; float radianB = 0.5f;



void Initialize() {
	std::vector<glm::vec2> positions;

	positions.push_back(glm::cos(306.0f));
    positions.push_back(glm::cos(306.0f));
	positions.push_back(glm::cos(18.0f));
	positions.push_back(glm::cos(18.0f));
	positions.push_back(glm::cos(90.0f));
	positions.push_back(glm::cos(162.0));
	positions.push_back(glm::cos(162.0));
	positions.push_back(glm::cos(234.0));
	positions.push_back(glm::cos(234.0));
	positions.push_back(glm::cos(306.0));
	positions.push_back(glm::cos(306.0));


	//colores

	std::vector<glm::vec3> colors;

	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
}

void MainLoop() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBindVertexArray();
		
		glDrawArrays(GL_TRIANGLES, );
		
		glBindVertexArray(0);
}

