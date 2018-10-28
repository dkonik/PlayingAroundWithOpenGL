#pragma once
#include "IndexBuffer.h"
#include "Renderer.h"
#include <GL/glew.h>
#include "OpenGLHelper.h"

IndexBuffer::IndexBuffer(const unsigned int *data, const unsigned int count)
    : m_count(count)
{
    glGenBuffers(1, &m_rendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_rendererID));
}

void IndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID);
}

void IndexBuffer::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}