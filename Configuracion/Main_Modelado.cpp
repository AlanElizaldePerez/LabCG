//Pr�ctica 04
// Elizalde P�rez Alan
//319278949
#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



// Shaders
#include "Shader.h"

void Inputs(GLFWwindow* window);


const GLint WIDTH = 800, HEIGHT = 600;
float movX = 0.0f;
float movY = 0.0f;
float movZ = -5.0f;
float rot = 0.0f;
int main() {
	glfwInit();
	//Verificaci�n de compatibilidad 
	// Set all the required options for GLFW
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);*/

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Elizalde Perez Alan Practica 4", nullptr, nullptr);

	int screenWidth, screenHeight;

	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	//Verificaci�n de errores de creacion  ventana
	if (nullptr == window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificaci�n de errores de inicializaci�n de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}


	// Define las dimensiones del viewport
	glViewport(0, 0, screenWidth, screenHeight);


	// Setup OpenGL options
	glEnable(GL_DEPTH_TEST);

	// enable alpha support
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	// Build and compile our shader program
	Shader ourShader("Shader/core.vs", "Shader/core.frag");


	// Set up vertex data (and buffer(s)) and attribute pointers



	// use with Perspective Projection
	float vertices[] = {
		// Color blanco F4F6F3
		-0.5f, -0.5f,  0.5f,  0.957f, 0.965f, 0.953f, // Frente
		 0.5f, -0.5f,  0.5f,  0.957f, 0.965f, 0.953f,
		 0.5f,  0.5f,  0.5f,  0.957f, 0.965f, 0.953f,
		 0.5f,  0.5f,  0.5f,  0.957f, 0.965f, 0.953f,
		-0.5f,  0.5f,  0.5f,  0.957f, 0.965f, 0.953f,
		-0.5f, -0.5f,  0.5f,  0.957f, 0.965f, 0.953f,

		-0.5f, -0.5f, -0.5f,  0.957f, 0.965f, 0.953f, // Atr�s
		 0.5f, -0.5f, -0.5f,  0.957f, 0.965f, 0.953f,
		 0.5f,  0.5f, -0.5f,  0.957f, 0.965f, 0.953f,
		 0.5f,  0.5f, -0.5f,  0.957f, 0.965f, 0.953f,
		-0.5f,  0.5f, -0.5f,  0.957f, 0.965f, 0.953f,
		-0.5f, -0.5f, -0.5f,  0.957f, 0.965f, 0.953f,

		 0.5f, -0.5f,  0.5f,  0.957f, 0.965f, 0.953f, // Derecha
		 0.5f, -0.5f, -0.5f,  0.957f, 0.965f, 0.953f,
		 0.5f,  0.5f, -0.5f,  0.957f, 0.965f, 0.953f,
		 0.5f,  0.5f, -0.5f,  0.957f, 0.965f, 0.953f,
		 0.5f,  0.5f,  0.5f,  0.957f, 0.965f, 0.953f,
		 0.5f, -0.5f,  0.5f,  0.957f, 0.965f, 0.953f,

		-0.5f,  0.5f,  0.5f,  0.957f, 0.965f, 0.953f, // Izquierda
		-0.5f,  0.5f, -0.5f,  0.957f, 0.965f, 0.953f,
		-0.5f, -0.5f, -0.5f,  0.957f, 0.965f, 0.953f,
		-0.5f, -0.5f, -0.5f,  0.957f, 0.965f, 0.953f,
		-0.5f, -0.5f,  0.5f,  0.957f, 0.965f, 0.953f,
		-0.5f,  0.5f,  0.5f,  0.957f, 0.965f, 0.953f,

		-0.5f, -0.5f, -0.5f,  0.957f, 0.965f, 0.953f, // Abajo
		 0.5f, -0.5f, -0.5f,  0.957f, 0.965f, 0.953f,
		 0.5f, -0.5f,  0.5f,  0.957f, 0.965f, 0.953f,
		 0.5f, -0.5f,  0.5f,  0.957f, 0.965f, 0.953f,
		-0.5f, -0.5f,  0.5f,  0.957f, 0.965f, 0.953f,
		-0.5f, -0.5f, -0.5f,  0.957f, 0.965f, 0.953f,

		-0.5f,  0.5f, -0.5f,  0.957f, 0.965f, 0.953f, // Arriba
		 0.5f,  0.5f, -0.5f,  0.957f, 0.965f, 0.953f,
		 0.5f,  0.5f,  0.5f,  0.957f, 0.965f, 0.953f,
		 0.5f,  0.5f,  0.5f,  0.957f, 0.965f, 0.953f,
		-0.5f,  0.5f,  0.5f,  0.957f, 0.965f, 0.953f,
		-0.5f,  0.5f, -0.5f,  0.957f, 0.965f, 0.953f,
	};

	float verticesVerdes[] = {
		 // Colores Verde #5BD101
		-0.5f, -0.5f,  0.5f,  0.357f, 0.820f, 0.004f, // Frente
		 0.5f, -0.5f,  0.5f,  0.357f, 0.820f, 0.004f,
		 0.5f,  0.5f,  0.5f,  0.357f, 0.820f, 0.004f,
		 0.5f,  0.5f,  0.5f,  0.357f, 0.820f, 0.004f,
		-0.5f,  0.5f,  0.5f,  0.357f, 0.820f, 0.004f,
		-0.5f, -0.5f,  0.5f,  0.357f, 0.820f, 0.004f,

		-0.5f, -0.5f, -0.5f,  0.357f, 0.820f, 0.004f, // Atr�s
		 0.5f, -0.5f, -0.5f,  0.357f, 0.820f, 0.004f,
		 0.5f,  0.5f, -0.5f,  0.357f, 0.820f, 0.004f,
		 0.5f,  0.5f, -0.5f,  0.357f, 0.820f, 0.004f,
		-0.5f,  0.5f, -0.5f,  0.357f, 0.820f, 0.004f,
		-0.5f, -0.5f, -0.5f,  0.357f, 0.820f, 0.004f,

		 0.5f, -0.5f,  0.5f,  0.357f, 0.820f, 0.004f, // Derecha
		 0.5f, -0.5f, -0.5f,  0.357f, 0.820f, 0.004f,
		 0.5f,  0.5f, -0.5f,  0.357f, 0.820f, 0.004f,
		 0.5f,  0.5f, -0.5f,  0.357f, 0.820f, 0.004f,
		 0.5f,  0.5f,  0.5f,  0.357f, 0.820f, 0.004f,
		 0.5f, -0.5f,  0.5f,  0.357f, 0.820f, 0.004f,

		-0.5f,  0.5f,  0.5f,  0.357f, 0.820f, 0.004f, // Izquierda
		-0.5f,  0.5f, -0.5f,  0.357f, 0.820f, 0.004f,
		-0.5f, -0.5f, -0.5f,  0.357f, 0.820f, 0.004f,
		-0.5f, -0.5f, -0.5f,  0.357f, 0.820f, 0.004f,
		-0.5f, -0.5f,  0.5f,  0.357f, 0.820f, 0.004f,
		-0.5f,  0.5f,  0.5f,  0.357f, 0.820f, 0.004f,

		-0.5f, -0.5f, -0.5f,  0.357f, 0.820f, 0.004f, // Abajo
		 0.5f, -0.5f, -0.5f,  0.357f, 0.820f, 0.004f,
		 0.5f, -0.5f,  0.5f,  0.357f, 0.820f, 0.004f,
		 0.5f, -0.5f,  0.5f,  0.357f, 0.820f, 0.004f,
		-0.5f, -0.5f,  0.5f,  0.357f, 0.820f, 0.004f,
		-0.5f, -0.5f, -0.5f,  0.357f, 0.820f, 0.004f,

		-0.5f,  0.5f, -0.5f,  0.357f, 0.820f, 0.004f, // Arriba
		 0.5f,  0.5f, -0.5f,  0.357f, 0.820f, 0.004f,
		 0.5f,  0.5f,  0.5f,  0.357f, 0.820f, 0.004f,
		 0.5f,  0.5f,  0.5f,  0.357f, 0.820f, 0.004f,
		-0.5f,  0.5f,  0.5f,  0.357f, 0.820f, 0.004f,
		-0.5f,  0.5f, -0.5f,  0.357f, 0.820f, 0.004f,
	};

	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	//glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	/*glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)


	glm::mat4 projection = glm::mat4(1);

	///////////////////////////////////////////////////////////////////////////////////

	GLuint VAO_Verde, VBO_Verde;
	glGenVertexArrays(1, &VAO_Verde);
	glGenBuffers(1, &VBO_Verde);

	glBindVertexArray(VAO_Verde);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_Verde);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesVerdes), verticesVerdes, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	//////////////////////////////////////////////////////////////////////////////////////////


	projection = glm::perspective(glm::radians(45.0f), (GLfloat)screenWidth / (GLfloat)screenHeight, 0.1f, 100.0f);//FOV, Radio de aspecto,znear,zfar
	//projection = glm::ortho(0.0f, (GLfloat)screenWidth, 0.0f, (GLfloat)screenHeight, 0.1f, 1000.0f);//Izq,Der,Fondo,Alto,Cercania,Lejania
	while (!glfwWindowShouldClose(window))
	{

		Inputs(window);
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		// Draw our first triangle
		ourShader.Use();
		glm::mat4 model = glm::mat4(1);
		glm::mat4 view = glm::mat4(1);


		view = glm::translate(view, glm::vec3(movX, movY, movZ));
		view = glm::rotate(view, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));

		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projecLoc = glGetUniformLocation(ourShader.Program, "projection");


		glUniformMatrix4fv(projecLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));



		//Android Robot

		/////////////////////////////////////////////

		
		glBindVertexArray(VAO_Verde);

		// Cabeza
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.0f, 0.50f, 1.0f));
		model = glm::translate(model, glm::vec3(0.0f, 2.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//Torso
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(1.0f, 1.3f, 1.0f)); //ancho, grosor, profundidad
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// Antena derecha
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.15f, 0.15f, 0.15f));
		model = glm::translate(model, glm::vec3(-1.7f, 8.75f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// Antena derecha superior
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.15f, 0.15f, 0.15f));
		model = glm::translate(model, glm::vec3(-2.7f, 9.75f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// Antena izquierda
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.15f, 0.15f, 0.15f));
		model = glm::translate(model, glm::vec3(1.7f, 8.75f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// Antena izquierda superior
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.15f, 0.15f, 0.15f));
		model = glm::translate(model, glm::vec3(2.7f, 9.75f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//Brazo derecho
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.30f, 0.9f, 0.30f)); //ancho, grosor, profundidad
		model = glm::translate(model, glm::vec3(-1.950f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//Brazo izquierdo
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.30f, 0.9f, 0.30f)); //ancho, grosor, profundidad
		model = glm::translate(model, glm::vec3(1.950f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//Pierna derecha
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.250f, 0.3f, 0.250f)); //ancho, grosor, profundidad
		model = glm::translate(model, glm::vec3(-0.80f, -2.65f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//Pierna izquierda
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.250f, 0.3f, 0.250f)); //ancho, grosor, profundidad
		model = glm::translate(model, glm::vec3(0.80f, -2.65f, 0.0f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		/////////////////////////////////////////// Blanco
		glBindVertexArray(VAO);

		//	Junta
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.80f, 0.10f, 0.80f)); // Tama�o de la pata
		model = glm::translate(model, glm::vec3(0.00f, 7.2f, 0.00f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// Ojo derecho
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.15f, 0.15f, 0.06f));
		model = glm::translate(model, glm::vec3(-1.7f, 7.30f, 8.60f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// Ojo izquierdo
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.15f, 0.15f, 0.06f));
		model = glm::translate(model, glm::vec3(1.7f, 7.30f, 8.60f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		glBindVertexArray(0);

		// Swap the screen buffers
		glfwSwapBuffers(window);

	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO_Verde);
	glDeleteBuffers(1, &VBO_Verde);

	glfwTerminate();
	return EXIT_SUCCESS;
}

void Inputs(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)  //GLFW_RELEASE
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		movX += 0.01f;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		movX -= 0.01f;
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		movY += 0.005f;
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		movY -= 0.005f;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		movZ -= 0.01f;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		movZ += 0.01f;
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		rot += 0.1f;
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		rot -= 0.1f;
}


