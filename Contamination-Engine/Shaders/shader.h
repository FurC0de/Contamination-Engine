#include <GL/glew.h>
#include <string>
#include <utility>

#ifndef SHADER_H
#define SHADER_H

namespace CNE {
	struct Sources_t;

	namespace Shaders {

		class Shader
		{
		public:
			GLuint Program;
			Shader(std::string vertexPath, std::string fragmentPath);
			void Use();
		private:
			Sources_t* readDoubleShaderSource(std::string vertexPath, std::string fragmentPath);
			std::string* readSingleShaderSource(std::string path);
		};
	}
}

#endif