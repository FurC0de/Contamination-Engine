#include "shader.h"
#include "../Utilities/fileUtilities.h"

CNE::Shaders::Shader::Shader(std::string vertexPath, std::string fragmentPath)
{
	Sources_t* code = readDoubleShaderSource(vertexPath, fragmentPath);

	GLuint vertex, fragment;
	GLint success;
	GLchar infoLog[512];

	/* --------- VERTEX --------- */
	const GLchar* vShaderCode = code->srcA->c_str();
	
	
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	} else {
		std::cout << "SHADER::VERTEX::COMPILATION_OK" << std::endl;
	}

	/* --------- FRAGMENT --------- */
	const GLchar* fShaderCode = code->srcB->c_str();

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	} else {
		std::cout << "SHADER::FRAGMENT::COMPILATION_OK" << std::endl;
	}

	/* --------- SHADER PROGRAM --------- */
	this->Program = glCreateProgram();
	glAttachShader(this->Program, vertex);
	glAttachShader(this->Program, fragment);
	glLinkProgram(this->Program);

	glGetProgramiv(this->Program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(this->Program, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	} else {
		std::cout << "SHADER::PROGRAM::LINKING_OK" << std::endl;
	}
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void CNE::Shaders::Shader::Use()
{
	glUseProgram(this->Program);
}

CNE::Sources_t* CNE::Shaders::Shader::readDoubleShaderSource(std::string vertexPath, std::string fragmentPath)
{
	Sources_t* code = new Sources_t;
	code->srcA = new std::string;
	code->srcB = new std::string;

	try
	{
		code->srcA = readSingleShaderSource(vertexPath);
		code->srcB = readSingleShaderSource(fragmentPath);
	}
	catch (...)
	{
		std::cout << "ERROR::SHADER::FILES_NOT_SUCCESFULLY_READ" << std::endl;
	}
	
	return code;
}

std::string* CNE::Shaders::Shader::readSingleShaderSource(std::string path)
{
	std::string* source = new std::string("");
	try
	{
		*source = CNE::Utilities::LoadFileASCII(path);
		return source;
	} 
	catch (...) 
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		return source;
	}
}
