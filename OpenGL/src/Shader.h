#pragma once

#include <string>
#include <unordered_map>

class Shader {
private:
	const std::string& m_VertexShader;
	const std::string& m_FragmentShader;
	unsigned int m_RendererID;
	std::unordered_map<std::string, int> m_UniformLocationCache;
	// caching for uniforms;
public:
	Shader(
		const std::string& vertexShader,
		const std::string& fragmentShader
	);
	~Shader();

	void Bind() const;
	void UnBind() const;

	void SetUniform4f(
		const std::string& name,
		float v0,
		float v1,
		float v2,
		float v3
	);

private:
	unsigned int CompileShader(int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	int GetUniformLocation(const std::string& name);
};