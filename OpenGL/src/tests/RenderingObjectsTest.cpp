#include <sstream>

#include "RenderingObjectsTest.h"

#include "glm/gtc/matrix_transform.hpp"
#include "imgui\imgui.h"

Test::RenderingObjectsTest::RenderingObjectsTest(const Renderer& renderer, const std::string & pathToTexture, const std::string & pathToShader)
	: m_renderer(renderer),
	m_startingVertices({
	-50.f, -50.f, 0.0f, 0.0f,
	50.f, -50.f, 1.0f, 0.0f,
	50.f, 50.f, 1.0f, 1.0f,
	-50.f,50.f, 0.0f, 1.0f
	}),
	m_indices({
	0, 1, 2,
	2, 3, 0
	}),
	m_vertexBuffer(&m_startingVertices[0], m_startingVertices.size() * sizeof(float)),
	m_indexBuffer(&m_indices[0], 6),
	m_texture(pathToTexture), 
	m_shader(pathToShader),
	m_projMat(glm::ortho(0.f, 640.f, 0.f, 480.f, -1.f, 1.f)),
	m_viewTranslation(glm::vec3(0.f, 0.f, 0.f))
{
	m_bufferLayout.Push<float>(2);
	m_bufferLayout.Push<float>(2);
	m_vertexArray.AddBuffer(m_vertexBuffer, m_bufferLayout);

	m_texture.Bind(0);
	m_shader.Bind();
	m_shader.SetUniform1i("u_texture", 0);
}

Test::RenderingObjectsTest::~RenderingObjectsTest()
{
}

void Test::RenderingObjectsTest::OnUpdate(float deltaTime)
{
}

void Test::RenderingObjectsTest::OnRender()
{
	m_shader.Bind();
	glm::mat4 viewMat = glm::translate(glm::mat4(1.0f), -m_viewTranslation);
	glm::mat4 modelMat;
	glm::mat4 mvp;
	for (unsigned i = 0; i < m_modelTranslations.size(); ++i) {
		modelMat = glm::translate(glm::mat4(1.0f), m_modelTranslations[i]);
		mvp = m_projMat * viewMat * modelMat;
		m_shader.SetUniformMat4f("u_mvp", mvp);
		m_renderer.Draw(m_vertexArray, m_indexBuffer, m_shader);
	}
}

void Test::RenderingObjectsTest::OnImGuiRender()
{
	ImGui::SliderFloat3("View Translation", &m_viewTranslation.x, 0.0f, 960.f);
	ImGui::TextColored(ImVec4(1, 1, 0, 1), "Models");
	ImGui::Separator();
	ImGui::BeginGroup();
	std::ostringstream stringStream;
	for (unsigned i = 0; i < m_modelTranslations.size(); ++i) {
		stringStream.clear();
		stringStream << "Model " << i;
		ImGui::SliderFloat3(stringStream.str().c_str(), &m_modelTranslations[i].x, 0.0f, 960.f);
	}
	ImGui::EndGroup();
	ImGui::Separator();
	if (ImGui::Button("AddModel")) {
		AddObject();
	}
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
}

void Test::RenderingObjectsTest::AddObject()
{
	m_modelTranslations.push_back(glm::vec3());
}
