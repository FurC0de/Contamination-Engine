#include "shader.h"

Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
{
	//���������� ����������
	//�������� �� ����� � string

}

void Shader::Use()
{
	glUseProgram(this->Program);
}
