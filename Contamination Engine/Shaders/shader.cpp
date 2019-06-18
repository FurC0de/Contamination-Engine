#include "shader.h"

Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
{
	//объ€вление переменных
	//загрузка из файла в string

}

void Shader::Use()
{
	glUseProgram(this->Program);
}
