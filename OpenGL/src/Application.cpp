#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "VertexBufferLayout.h"
#include "Texture.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include "tests\ClearColorTest.h"
#include "tests\RenderingObjectsTest.h"

int main(void)
{
	GLFWwindow *window;

	/* Initialize the library */
	if (!glfwInit())
	{
		return -1;
	}

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Glew Init failed." << std::endl;
		return -1;
	}

	std::cout << glGetString(GL_VERSION) << std::endl;
	{
		//std::vector<float> vertices = {
		//	-50.f, -50.f, 0.0f, 0.0f,
		//	50.f, -50.f, 1.0f, 0.0f,
		//	50.f, 50.f, 1.0f, 1.0f,
		//	-50.f,50.f, 0.0f, 1.0f};

		//unsigned int indices[] = {
		//	0, 1, 2,
		//	2, 3, 0};

		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		//float redVal = 0.5f;
		//float increment = 0.05f;

		//VertexArray vertexArray;
		//VertexBuffer vertexBuffer(&vertices[0], vertices.size() * sizeof(float));
		//VertexBufferLayout bufferLayout;
		//bufferLayout.Push<float>(2);
		//bufferLayout.Push<float>(2);
		//vertexArray.AddBuffer(vertexBuffer, bufferLayout);

		//IndexBuffer indexBuffer(indices, 6);

		//glm::mat4 projMat = glm::ortho(0.f, 640.f, 0.f, 480.f, -1.f, 1.f);
		//glm::mat4 viewMat = glm::translate(glm::mat4(1.0f), glm::vec3(0.f, 0.f, 0.f));

		//Shader shader("res/shaders/Basic.shader");
		//shader.Bind();
		//shader.SetUniform4f("u_color", redVal, .3f, .8f, 1.0f);

		//Texture texture("res/img/ColorWars.PNG");
		//texture.Bind(0);

		//// Tell the shader which slot our texture is bound to
		//shader.SetUniform1i("u_texture", 0);

		//shader.Unbind();
		//vertexBuffer.Unbind();
		//indexBuffer.Unbind();

		Renderer renderer;

		ImGui::CreateContext();

		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 330 core");

		ImGui::StyleColorsDark();

		Test::RenderingObjectsTest objectsTest(renderer, "res/img/ColorWars.PNG", "res/shaders/Basic.shader");

		//bool show_demo_window = true;
		//bool show_another_window = false;
		//ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

		//glm::vec3 translationA = glm::vec3(100.f, 100.f, 0.f);
		//glm::vec3 translationB = glm::vec3(100.f, 400.f, 0.f);

		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			renderer.Clear();

			objectsTest.OnUpdate(0.f);
			objectsTest.OnRender();

			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			objectsTest.OnImGuiRender();

			//{
			//	glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
			//	glm::mat4 mvp = projMat * viewMat * model;
			//	// Dont need this since rednering a texture
			//	//shader.SetUniform4f("u_color", redVal, .3f, .8f, 1.0f);
			//	shader.Bind();
			//	shader.SetUniformMat4f("u_mvp", mvp);
			//	renderer.Draw(vertexArray, indexBuffer, shader);
			//}
			//{
			//	glm::mat4 model = glm::translate(glm::mat4(1.0f), translationB);
			//	glm::mat4 mvp = projMat * viewMat * model;
			//	// Dont need this since rednering a texture
			//	//shader.SetUniform4f("u_color", redVal, .3f, .8f, 1.0f);
			//	shader.Bind();
			//	shader.SetUniformMat4f("u_mvp", mvp);
			//	renderer.Draw(vertexArray, indexBuffer, shader);
			//}

			//if (redVal > 1.0f || redVal < 0.f)
			//{
			//	increment = -increment;
			//}

			//redVal += increment;

			//{
			//	//ImGui::Begin("Hello, world!");
			//	ImGui::SliderFloat3("TranslationA", &translationA.x, 0.0f, 960.f); 
			//	ImGui::SliderFloat3("TranslationB", &translationB.x, 0.0f, 960.f);

			//	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			//	//ImGui::End();
			//}

			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}
	}
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();
	return 0;
}