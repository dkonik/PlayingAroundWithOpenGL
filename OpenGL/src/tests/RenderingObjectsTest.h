#pragma once
#include <vector>

#include "glm/glm.hpp"

#include "Test.h"


namespace Test {
	// A simple test class to render a simple texture multiple times.
	// Reuses the same vertex buffer and recalculates the mvp for each object, which is bad
	// because that is a separate draw call for each object. But this is just a test.
	class RenderingObjectsTest : public Test {
	public:
		RenderingObjectsTest();
		virtual ~RenderingObjectsTest();
		virtual void OnUpdate(float deltaTime);
		virtual void OnRender();
		virtual void OnImGuiRender();
	private:
		std::vector<glm::vec3> m_transformations;
	};
}