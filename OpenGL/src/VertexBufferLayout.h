#pragma once

#include <vector>
#include <glad/glad.h>

struct VertexBufferElement {
	unsigned int count;
	unsigned int type;
	bool normalized;
};

class VertexBufferLayout {
private:
	std::vector<VertexBufferElement> m_Elements;
public:
	VertexBufferLayout();

	template<typename T>
	void Push(int count) {
		static_assert(false);
	}

	template<>
	void Push<float>(int count, bool normalized) {
		m_Elements.push_back({ GL_FLOAT, count, false });
	}

	template<>
	void Push<unsigned int>(int count) {
		m_Elements.push_back({ GL_UNSIGNED_INT, count, false });
	}

	template<>
	void Push<unsigned char>(int count) {
		m_Elements.push_back({ GL_UNSIGNED_BYTE, count, false });
	}

	inline const std::vector<VertexBufferElement> GetElements()
	{
		return m_Elements;
	}

	inline unsigned int GetStride() const { return m_Stride; }
};