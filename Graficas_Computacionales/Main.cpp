#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>

//Identificador del manager del VBOs para un conjunto de vertices.
GLuint vao;

//Funcion que va a inicializar toda la memoria del programa.
void Initialize()
{
	//Vamos a crear una lista que va a almacenar las posiciones en 2 dimensiones de un triangulo.
	//Esto es en CPU y RAM, todavia no se crea en memoria.

	std::vector<glm::vec2> positions;
	positions.push_back(glm::vec2(-1.0f, -1.0));
	positions.push_back(glm::vec2(1.0f, -1.0f)); //Solo estamos metiendo los vertices con los positions
	positions.push_back(glm::vec2(0.0f, 1.0f)); //vec2=trabajamos en 2 dimensiones, vec3= trabajamos en 3 dimensiones.

	//Vamos a crear una lista para almacenar colores RGB
	//Esta lista esta en CPU y RAM
	std::vector<glm::vec3> colors;
	//RGB- rojo
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	//RGB- verde
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
    //RGB- azul
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));

	//Creamos un VAO y almacenamos el id en la variable vao.
	//Este es el manager de VBOs
	glGenVertexArrays(1, &vao);
	//Le decimos a OpenGL que queremos utilizar el manager.
	//Todos los VBOs que creemos a pártir de este punto y hasta que desactivemos este VAO, se van a asociar a este manager.
	glBindVertexArray(vao);



    GLuint positionsVBO; //Es un numero entero sin signos, aqui guardamos el identificador del VBO de posiciones. Aqui lo vamos a almacenar.
	//Cramos un VBO y almacenamos el id en la variable positionVBO
	glGenBuffers(1, &positionsVBO);
	//Le decimos a OpenGL que lo queremos utilzar como un atruibuto
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	//asignamos los datos al buffer y los mandamos a la tarjeta de video
	glBufferData (GL_ARRAY_BUFFER, sizeof(glm::vec2)* positions.size(),
		positions.data(), GL_STATIC_DRAW);
	//Quiero activar el atributo con indice 0 en la tarjeta de video.
	glEnableVertexAttribArray(0);
	//Configuramos el atributo con indice 0 en la tarjeta de video.
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	//Desactivamos el uso del VBO de posiciones.
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLuint colorsVBO;
	glGenBuffers(1, &colorsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, colorsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)* colors.size(), colors.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	
	//Ya no quiero utilizar el VAO. Ya no se asociaran mas VBOs a este VAO
	glBindVertexArray(0);

}

void MainLoop() {

	//Borramos el buffer de color y profundidd simepre al iniciio de un nuevo frame.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Paso 1: no lo podemos 

	//Paso 2: activar un VAO
	glBindVertexArray(vao);
	//Paso 3: Dibujamos
	glDrawArrays(GL_TRIANGLES, 0, 3);
	//Paso 4: Desactivamso el VAO
	glBindVertexArray(0);
	//Paso 5: aun no lo podemos hacer.
	

	//Intercambiar los buffers (el que estaba rendereando con elque se estaba mostrando)
	glutSwapBuffers();

}

int main(int argc, char* argv[]) 
{
	//Inicializamos freeglut.
	// Freeglut se encarga de generar y manejar ventanas.
	//Utilizamos freeglut para crear una ventana donde vamos a dibujar.
	glutInit(&argc, argv);

	//Tenemos que infromar que queremos trabajar con el pipelin clasico, es decir, openGL viejito.
	
	//Programable (OpenGL moderno)
	glutInitContextProfile(GLUT_CORE_PROFILE);
	//Freeglut nos permite configurar eventos que ocurren en la ventana.
	//Un evento que nos interesa es cuando alguien cierrra la ventana.
	//En este caso, simplemente dejamos de renderear y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS); //mianloop= cuando alguien pica el tache ya se deja de renderear.
	//Configuramos el framebuffer. En este caso estamos solicitando un buffer de color true color RGBA, un buffer de profundidad y un segundo buffer para 
	//renderear (evitamos parpadeos al renderear).
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	//Solicitamos una ventana de 400x400 pixeles.
	glutInitWindowSize(400, 400);
	//Creamos y abrimos la ventana con un titulo personalizado
	glutCreateWindow("Hello World OpenGL");

	//Asociar una funcion de render . Esta funcion se mandara a llamr para dibujar un frame.
	glutDisplayFunc(MainLoop);
	//Inicializamos GLEW. Esta libreria se encarga de obtener el API de OpenGL de nuestra y tarjeta de video. SHAME ON YOU MICROSOFT.
	glewInit();

	//Configurar OpenGL. Este es el color por default del buffer de color en el framebuffer. (el color es amarillo)
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);

	//Configurar la memoria que la aplicacion va a necesitar 
	Initialize();


	//Iniciamos la aplicacion grafica. El main se pausara en esta linea hasta que se cierre
	glutMainLoop();

	return 0;

}