#include "ShaderProgram.h"
#include<string>


ShaderProgram::ShaderProgram() {
	_programHandle = 0;
	
}

ShaderProgram::~ShaderProgram() {
	void ShaderProgram::AttachShader(std::string path, GLenum type) {
	}

	void ShaderProgram::LinkProgram() {
	
		for (size_t i = 0; i < _attachedShaders.size(); i++)
		glAttachShader(_programHandle, _attachedShaders[i]->GetHandle());
		glLinkProgram(_programHandle);
		DeleteAndDetachShaders();
	}

	void ShaderProgram::Activate() {
		glUseProgram(_programHandle);
	}

	void ShaderProgram::Deactivate() {
		glUseProgram(0);
	}

	void ShaderProgram::SetAttribute(GLuint locationIndex, std::string name) {
		
		glBindAttribLocation(_programHandle, locationIndex, name.c_str());
	}


	void ShaderProgram::SetUniformf(std::string name, float value) {
		
		GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
		glUniform1f(uniformLocation, value);
	}

	void ShaderProgram::SetUniformf(std::string name, float x, float y) {
		
		GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
		glUniform2f(uniformLocation, x, y);
	}

	void ShaderProgram::SetUniformf(std::string name, float x, float y, float z) {
		
		GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
		glUniform3f(uniformLocation, x, y, z);
	}

	void ShaderProgram::SetUniformf(std::string name, float x, float y, float z, float w) {
		
		GLint uniformLocation = glGetUniformLocation(_programHandle, name.c_str());
		glUniform4f(uniformLocation, x, y, z, w);
	}

	void ShaderProgram::DeleteAndDetachShaders() {
		
		for (size_t i = 0; i < _attachedShaders.size(); i++)
			 glDetachShader(_programHandle, _attachedShaders[i]->GetHandle());
		
			_attachedShaders.clear();
		
	}

	void ShaderProgram::DeleteProgram() {
		
	DeleteAndDetachShaders();
	glDeleteProgram(_programHandle);



	}
