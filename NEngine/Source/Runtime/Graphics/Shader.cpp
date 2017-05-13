/**
 * Shader.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "Shader.h"

namespace Newton {
	NShader::NShader(void) {
		LoadShader(DefaultVertexFilename, DefaultFragmentFilename);
	}

	NShader::NShader(const GLchar* InVertexFilename, const GLchar* InFragmentFilename) {
		LoadShader(InVertexFilename, InFragmentFilename);
	}

	void NShader::LoadShader(const GLchar* InVertexFilename, const GLchar* InFragmentFilename) {
		GLuint VertexID;
		GLuint FragmentID;

		// Read Shaders from Files
		GLchar* Vertex = ReadFile(InVertexFilename);
		GLchar* Fragment = ReadFile(InFragmentFilename);

		// Get Shader IDs from OpenGL
		ShaderID = glCreateProgram();
		VertexID = glCreateShader(GL_VERTEX_SHADER);
		FragmentID = glCreateShader(GL_FRAGMENT_SHADER);

		// Feed Shader Source Code into OpenGL
		glShaderSource(VertexID, 1, &Vertex, nullptr);
		glShaderSource(FragmentID, 1, &Fragment, nullptr);

		// Compile Vertex and Fragment Shaders
		glCompileShader(VertexID);
		glCompileShader(FragmentID);
		CheckCompile(VertexID);
		CheckCompile(FragmentID);

		// Attach Vertex and Fragment Shaders to NShader
		glAttachShader(ShaderID, VertexID);
		glAttachShader(ShaderID, FragmentID);

		glLinkProgram(ShaderID);
		CheckLink();

		glValidateProgram(ShaderID);
		CheckValidate();
	}

	void NShader::CheckCompile(const GLuint InID) const {
		GLint Status;

		glGetShaderiv(InID, GL_COMPILE_STATUS, &Status);
		if (Status == GL_FALSE) {
			GLchar Buffer[256];

			glGetShaderInfoLog(InID, 256, 0, Buffer);
			fprintf(stderr, "ERROR: Shader Compilation Failed\n%s", Buffer);
		}
	}

	void NShader::CheckLink(void) const {
		GLint Status;

		glGetProgramiv(ShaderID, GL_LINK_STATUS, &Status);
		if (Status == GL_FALSE) {
			GLchar Buffer[256];

			glGetProgramInfoLog(ShaderID, 256, 0, Buffer);
			fprintf(stderr, "ERROR: Shader Link Failed\n%s", Buffer);
		}
	}

	void NShader::CheckValidate(void) const {
		GLint Status;

		glGetProgramiv(ShaderID, GL_VALIDATE_STATUS, &Status);
		if (Status == GL_FALSE) {
			GLchar Buffer[256];

			glGetProgramInfoLog(ShaderID, 256, 0, Buffer);
			fprintf(stderr, "ERROR: Shader Validate Failed\n%s", Buffer);
		}
	}
}