#pragma once
#include "Test.h"

namespace Test {
	class ClearColorTest : public Test {
	public:
		ClearColorTest();
		virtual ~ClearColorTest();
		virtual void OnUpdate(float deltaTime);
		virtual void OnRender();
		virtual void OnImGuiRender();
	private:
		float m_clearColor[4];
	};
}