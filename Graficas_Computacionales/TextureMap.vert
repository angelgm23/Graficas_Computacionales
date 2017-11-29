#version 330
 
 in vec3 VertexPosition;
 in vec3 VertexColor;
 in vec3 VertexNormal;
 in vec2 VertexTexCoord;
 

 
 out vec3 InterpolatedColor;
 out vec3 InterpolatedNormal;
 out vec3 _PixelPosition;
 out vec2 InterpolatedTexCoord;
 
uniform mat4 mvpMatrix;
uniform mat3 NormalMatrix;
uniform mat4 ModelMatrix;

 void main()
 {
 	InterpolatedColor = VertexColor;
	_PixelPosition = vec3 (ModelMatrix * vec4(VertexPosition, 1.0));
	gl_Position = mvpMatrix * vec4(VertexPosition, 1.0f);
	InterpolatedNormal = NormalMatrix * VertexNormal;
	InterpolatedTexCoord= VertexTexCoord;

 } 