class IndexBuffer
{
private:
  unsigned int m_rendererID;
  unsigned int m_count;

public:
  IndexBuffer(const unsigned int *data, const unsigned int count);
  ~IndexBuffer();

  void Bind() const;
  void Unbind() const;

  inline unsigned int GetCount() const
  {
    return m_count;
  }
};