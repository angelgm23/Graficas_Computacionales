#include "Mesh.h"

Mesh::Mesh()
{
	_vertexArrayObject = 0;
	_positionsVertexBufferObject = 0;
	_colorsVertexBufferObject = 0;
	_vertexCount = 0;
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &_vertexArrayObject);
	glDeleteBuffers(1, &_positionsVertexBufferObject);
	glDeleteBuffers(1, &_colorsVertexBufferObject);
	_vertexCount = 0;
}

void Mesh::CreateMesh(GLint vertexCount)
{
	_vertexCount = vertexCount;
	glGenVertexArrays(1, &_vertexArrayObject);
}

void Mesh::Draw(GLenum primitive)
{

}
void Mesh::SetPositionAttribute(

	std::vector<glm::vec2> positions, GLenum usage, GLuint locationIndex)

{
	if (positions.size() == _vertexCount && positions.size() > 0)
		SetAttributeData(_positionsVertexBufferObject, positions.size() * sizeof(glm::vec2),
			positions.data(),
			usage,
			locationIndex, 2);
}
void Mesh::SetAttributeData(
	GLuint& buffer,
	const GLsizeiptr size,
	const void* data,
	GLenum usage,
	GLuint locationIndex,
	const GLint components
)
{
	if (buffer != 0)
		glDeleteBuffers(1, &buffer);

	glBindVertexArray(_vertexArrayObject);

	glGenBuffers(1, &_positionsVertexBufferObject);

	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);
	glEnableVertexAttribArray(locationIndex);
	glVertexAttribPointer(locationIndex, components, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	glBindVertexArray(0);

}