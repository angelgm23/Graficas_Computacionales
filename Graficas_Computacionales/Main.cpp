
#include <GL/glew.h>
#include <GL/freeglut.h>
 #include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include "Camera.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include "Texture2D.h"
#include <IL/il.h>

Camera _camera;
Mesh _mesh;
Transform _transform;
Transform _transform2;
Transform _transform3;
Transform _transform4;
Transform _transform5;
Transform _transform6;

Transform _transform2joint;
Transform _transform3joint;
Transform _transform4joint;
Transform _transform5joint;
Transform _transform6joint;

ShaderProgram _shaderProgram;

glm::vec3 _CameraPosition;
glm::vec3 _LightColor;
glm::vec3 _PixelPosition;
glm::vec3 _LightPosition;

Texture2D _myTexture;
Texture2D _Texture2;


// Función que va a inicializar toda la memoria del programa.
void Initialize()
{
	// Vamos a crear una lista que va a almacenar las posiciones
	// en 2 dimensiones de un triángulo.
	// Esto es en CPU y RAM.


	std::vector<glm::vec3> positions;
	// Cara frontal
	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f));

	// Cara lateral derecha
	positions.push_back(glm::vec3(3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f));

	//Cara Trasera
	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f));

	//Cara Lateral Izquierda
	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, 3.0f, -3.0f));

	//Cara Superior 
	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, 3.0f, -3.0f));

	//Cara Inferior
	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f));


	// Vamos a crear una lista para almacenar colores RGB
	// Esta lista está en CPU y RAM
	std::vector<glm::vec3> colors;

	// Cara frontal
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));

	// Cara lateral derecha

	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));

	//Cara Trasera
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));

	//Cara Lateral Izquierda
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));

	//Cara Superior
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));

	//Cara Inferior
	colors.push_back(glm::vec3(0.0f, 0.5f, 1.5f));
	colors.push_back(glm::vec3(0.0f, 0.5f, 1.5f));
	colors.push_back(glm::vec3(0.0f, 0.5f, 1.5f));
	colors.push_back(glm::vec3(0.0f, 0.5f, 1.5f));

	//Normales
	std::vector<glm::vec3> Normal;

	// Cara frontal
	Normal.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, 1.0f));

	// Cara lateral derecha

	Normal.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(1.0f, 0.0f, 0.0f));

	//Cara Trasera
	Normal.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	Normal.push_back(glm::vec3(0.0f, 0.0f, -1.0f));

	//Cara Lateral Izquierda
	Normal.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	Normal.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));

	//Cara Superior
	Normal.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, 1.0f, 0.0f));

	//Cara Inferior
	Normal.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	Normal.push_back(glm::vec3(0.0f, -1.0f, 0.0f));

	
	//Textura
	std::vector<glm::vec2>TextureCoord;

	//Cara Frontal
	TextureCoord.push_back(glm::vec2(0.0f, 0.0f));
	TextureCoord.push_back(glm::vec2(1.0f, 1.0f));
	TextureCoord.push_back(glm::vec2(0.0f, 1.0f));
	TextureCoord.push_back(glm::vec2(1.0f, 0.0f));

	//Cara lateral derecha
	TextureCoord.push_back(glm::vec2(0.0f, 0.0f));
	TextureCoord.push_back(glm::vec2(1.0f, 1.0f));
	TextureCoord.push_back(glm::vec2(0.0f, 1.0f));
	TextureCoord.push_back(glm::vec2(1.0f, 0.0f));

	//Cara Trasera
	TextureCoord.push_back(glm::vec2(0.0f, 0.0f));
	TextureCoord.push_back(glm::vec2(1.0f, 1.0f));
	TextureCoord.push_back(glm::vec2(0.0f, 1.0f));
	TextureCoord.push_back(glm::vec2(1.0f, 0.0f));

	//Cara lateral Izquierda
	TextureCoord.push_back(glm::vec2(0.0f, 0.0f));
	TextureCoord.push_back(glm::vec2(1.0f, 1.0f));
	TextureCoord.push_back(glm::vec2(0.0f, 1.0f));
	TextureCoord.push_back(glm::vec2(1.0f, 0.0f));

	//Cara superior
	TextureCoord.push_back(glm::vec2(0.0f, 0.0f));
	TextureCoord.push_back(glm::vec2(1.0f, 1.0f));
	TextureCoord.push_back(glm::vec2(0.0f, 1.0f));
	TextureCoord.push_back(glm::vec2(1.0f, 0.0f));

	//Cara inferior
	TextureCoord.push_back(glm::vec2(0.0f, 0.0f));
	TextureCoord.push_back(glm::vec2(1.0f, 1.0f));
	TextureCoord.push_back(glm::vec2(0.0f, 1.0f));
	TextureCoord.push_back(glm::vec2(1.0f, 0.0f));



	std::vector<unsigned int> indices = { 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7, 8, 9, 10, 8, 10, 11, 12, 13, 14, 12, 14, 15, 16, 17, 18, 16, 18, 19, 20, 23, 22, 22, 21, 20 };

	_mesh.CreateMesh(24);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	_mesh.SetNormalAttribute(Normal, GL_STATIC_DRAW, 2);
	_mesh.SetTexCoordAttribute(TextureCoord, GL_STATIC_DRAW, 3);
	_mesh.SetIndices(indices, GL_STATIC_DRAW);

	_shaderProgram.CreateProgram();
	_shaderProgram.AttachShader("TextureMap.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("TextureMap.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.SetAttribute(2, "VertexNormal");
	_shaderProgram.SetAttribute(3, "VertexTextureCoord");
	_shaderProgram.LinkProgram();


	_transform.SetPosition(0.0f, 0.0f, -20.0f);
	_transform2.SetPosition(0.0f, -10.0f, -20.0f);
	_transform3.SetPosition(0.0f, 0.0f, 6.0f);
	_transform4.SetPosition(-6.0f, 0.0f, 0.0f);
	_transform5.SetPosition(0.0f, 0.0f, -6.0f);
	_transform6.SetPosition(6.0f, 0.0f, 0.0f);

	_camera.SetPosition(0.0f, 5.0f, 20.0f);


	_transform2joint.SetPosition(0.0f, -10.0f, -20.0f);
	_transform3joint.SetPosition(0.0f, 0.0f, 1.0f);
	_transform4joint.SetPosition(-1.0f, 0.0f, 0.0f);
	_transform5joint.SetPosition(0.0f, 0.0f, -1.0f);
	_transform6joint.SetPosition(1.0f, 0.0f, 0.0f);
	


	//________________

	_LightColor = glm::vec3 (1.0f, 1.0f, 1.0f);
	_LightPosition = glm::vec3 (-5.0f, 5.0f, 5.0f);
	_CameraPosition = glm::vec3(0.0f, 5.0f, 20.0f);

	_myTexture.LoadTexture("Madera.jpg");
	_Texture2.LoadTexture("Carita Feliz.png");
	
	
	
	

}


void MainLoop()
{
	// Borramos el buffer de color y profundidad siempre al inicio de un nuevo frame.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		_transform.Rotate(0.01f, 0.01f, 0.01f, true);
	
	_shaderProgram.Activate();

	//----------------
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("s2", 1);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix());  // Proj * View * Model
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix());
	_shaderProgram.SetUniformf("_CameraPosition", _CameraPosition);
	_shaderProgram.SetUniformf("_LightColor", _LightColor);
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix()))));
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_Texture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_Texture2.Unbind();
	
	//-----------------
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("s2", 1);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()*_transform2joint.GetModelMatrix() * _transform2.GetModelMatrix());  // Proj * View * Model
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix() * _transform2joint.GetModelMatrix() * _transform2.GetModelMatrix());
	_shaderProgram.SetUniformf("_CameraPosition", _CameraPosition);
	_shaderProgram.SetUniformf("_LightColor", _LightColor);
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix() * _transform2joint.GetModelMatrix() * _transform2.GetModelMatrix()))));
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_Texture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_Texture2.Unbind();


	//-----------------
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("s2", 1);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()*_transform3joint.GetModelMatrix() * _transform3.GetModelMatrix());  // Proj * View * Model
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix() * _transform3joint.GetModelMatrix() * _transform3.GetModelMatrix());
	_shaderProgram.SetUniformf("_CameraPosition", _CameraPosition);
	_shaderProgram.SetUniformf("_LightColor", _LightColor);
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix() * _transform3joint.GetModelMatrix() * _transform3.GetModelMatrix()))));
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_Texture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_Texture2.Unbind();


	//-----------------
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("s2", 1);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()*_transform4joint.GetModelMatrix() * _transform4.GetModelMatrix());  // Proj * View * Model
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix() * _transform4joint.GetModelMatrix() * _transform4.GetModelMatrix());
	_shaderProgram.SetUniformf("_CameraPosition", _CameraPosition);
	_shaderProgram.SetUniformf("_LightColor", _LightColor);
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix() * _transform4joint.GetModelMatrix() * _transform4.GetModelMatrix()))));
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_Texture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_Texture2.Unbind();

	//----------------
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("s2", 1);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()*_transform5joint.GetModelMatrix() * _transform5.GetModelMatrix());  // Proj * View * Model
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix() * _transform5joint.GetModelMatrix() * _transform5.GetModelMatrix());
	_shaderProgram.SetUniformf("_CameraPosition", _CameraPosition);
	_shaderProgram.SetUniformf("_LightColor", _LightColor);
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix() * _transform5joint.GetModelMatrix() * _transform5.GetModelMatrix()))));
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_Texture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_Texture2.Unbind();

	//-----------------
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("s2", 1);
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix()*_transform6joint.GetModelMatrix() * _transform6.GetModelMatrix());  // Proj * View * Model
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix() * _transform6joint.GetModelMatrix() * _transform6.GetModelMatrix());
	_shaderProgram.SetUniformf("_CameraPosition", _CameraPosition);
	_shaderProgram.SetUniformf("_LightColor", _LightColor);
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix() * _transform6joint.GetModelMatrix() * _transform6.GetModelMatrix()))));
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	_Texture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	_myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	_Texture2.Unbind();


	_shaderProgram.Deactivate();
	


	_transform2.SetScale(7, 1.5, 5);
	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform2.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("ModelMatrix", _transform2.GetModelMatrix());
	_shaderProgram.SetUniformf("_LightColor", _LightColor);
	_shaderProgram.SetUniformf("_LightPosition", _LightPosition);
	_shaderProgram.SetUniformMatrix("NormalMatrix", glm::transpose(glm::inverse(glm::mat3(_transform2.GetModelMatrix()))));
	_mesh.Draw(GL_TRIANGLES);
	_shaderProgram.Deactivate();

	
		// Intercambiar los buffers (el que se estaba rendereando con el que se estaba
		// mostrando).
		glutSwapBuffers();
}

void Idle()
 {
		// Cuando OpenGL entra en modo de reposo 
			// (para guardar bateria, por ejemplo)
			// le decimos que vuelva a dibujar ->
			// Vuelve a mandar a llamar GameLoop
		glutPostRedisplay();
	}

void ReshapeWindow(int width, int height)
 {
	glViewport(0, 0, width, height);
	_camera.SetPerspective(1.0f, 1000.0f, 60.0f, (float)width / (float)height);
	}

int main(int argc, char* argv[])
{
	// Inicializamos freeglut. 
	// Freeglut se encarga de generar y manejar ventanas.
	// Utilizamos freeglut para crear una ventana donde vamos a dibujar.
	glutInit(&argc, argv);
	// Tenemos que informar que queremos trabajar con el pipeline
	// programable (OpenGL moderno).
	glutInitContextProfile(GLUT_CORE_PROFILE);
	// Freeglut nos permite configurar eventos que ocurren en la ventana.
	// Un evento que nos interesa es cuando alguien cierra la ventana.
	// En este caso, simplemente dejamos de renderear y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	// Configuramos el framebuffer. En este caso estamos solicitando un buffer
	// de color true color RGBA, un buffer de profundidad y un segundo buffer 
	// para rendererar (evitamos parpadeos al renderear).
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	// Solicitamos una ventana de 400x400 pixeles.
	glutInitWindowSize(400, 400);
	// Creamos y abrimos la ventana con un título personalizado.
	glutCreateWindow("Hello World OpenGL");
	
		// Asociar una función de render. Esta función se mandará a llamar para 
		// dibujar un frame.
		glutDisplayFunc(MainLoop);
		// Asociamos una función para el cambio de resolución
			// de la ventana. Freeglut la va a mandar a llamar
			// cuando alguien cambie el tamaño de la venta.
		glutReshapeFunc(ReshapeWindow);
		// Asociamos la función que se mandará a llamar
			// cuando OpenGL entre en modo de reposo.
		glutIdleFunc(Idle);

	// Inicializamos GLEW. Esta librería se encarga de obtener el API
	// de OpenGL de nuestra tarjeta de video. SHAME ON YOU MICROSOFT.
		glewInit();
		// COnfigurar OpenGL. Este es el color por default del buffer de color
		// en el framebuffer.
		glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
		// Ademas de solicitar el buffer de profundidad, tenemos
			// que decirle a OpenGL que lo queremos activo
		glEnable(GL_DEPTH_TEST);
	// Activamos el borrado de caras traseras.
			// Ahora todos los triangulos que dibujemos deben estar en CCW
		glEnable(GL_CULL_FACE);
		// No dibujar las caras traseras de las geometrías.
		glCullFace(GL_BACK);

	std::cout << glGetString(GL_VERSION) << std::endl;

	
	
	ilInit();
	ilEnable(IL_ORIGIN_SET);
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);

	// Configurar la memoria que la aplicación va a necesitar.
	Initialize();

	// Iniciamos la aplicacion gráfica. El main se pausará en estea línea
	// hasta que se cierre la ventana de OpenGL.
	glutMainLoop();

	return 0;
}