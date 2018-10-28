#pragma once
#include <vector>

#include "glm/glm.hpp"

#include "Test.h"
#include "Texture.h"
#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"

namespace Test {
	// A simple test class to render a simple texture multiple times.
	// Reuses the same vertex buffer and recalculates the mvp for each object, which is bad
	// because that is a separate draw call for each object. But this is just a test.
	class RenderingObjectsTest : public Test {
	public:
		RenderingObjectsTest(const Renderer& renderer, const std::string& pathToTexture, const std::string& pathToShader);
		virtual ~RenderingObjectsTest();
		virtual void OnUpdate(float deltaTime);
		virtual void OnRender();
		virtual void OnImGuiRender();

	private:
		void AddObject();		

	private:
		const Renderer& m_renderer;
		std::vector<float> m_startingVertices;
		std::vector<unsigned int> m_indices;
		VertexArray m_vertexArray;
		VertexBuffer m_vertexBuffer;
		IndexBuffer m_indexBuffer;
		VertexBufferLayout m_bufferLayout;

		Texture m_texture;
		Shader m_shader;

		glm::mat4 m_projMat;
		glm::vec3 m_viewTranslation;
		std::vector<glm::vec3> m_modelTranslations;
	};
}