#include "ClearColorTest.h"

#include "GL/glew.h"
#include "OpenGLHelper.h"
#include "imgui\imgui.h"

namespace Test {

	ClearColorTest::ClearColorTest() : m_clearColor {.2f, .3f, .8f, 1.f}
	{
	} 

	ClearColorTest::~ClearColorTest()
	{
	}

	void ClearColorTest::OnUpdate(float deltaTime)
	{
	}

	void ClearColorTest::OnRender()
	{
		GLCall(glClearColor(m_clearColor[0], m_clearColor[1], m_clearColor[2], m_clearColor[3]));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
	}

	void ClearColorTest::OnImGuiRender()
	{
		ImGui::ColorEdit4("Color", m_clearColor);
	}
}