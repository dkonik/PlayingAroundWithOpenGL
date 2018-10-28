#include "VertexArray.h"
#include "Renderer.h"
#include "VertexBufferLayout.h"
#include "OpenGLHelper.h"
#include "VertexBuffer.h"

VertexArray::VertexArray()
{
    GLCall(glGenVertexArrays(1, &m_rendererID));
}

VertexArray::~VertexArray()
{
    GLCall(glDeleteVertexArrays(1, &m_rendererID));
}

void VertexArray::Bind() const
{
    GLCall(glBindVertexArray(m_rendererID))
}
void VertexArray::Unbind() const
{
    GLCall(glBindVertexArray(0))
}

void VertexArray::AddBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout)
{
    Bind();
    vb.Bind();
    const auto &elements = layout.GetElements();
    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size(); ++i)
    {
        const auto &element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void *)offset);
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }
}