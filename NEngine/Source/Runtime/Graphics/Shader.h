/**
 * Shader.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <Core/Config.h>
#include <Utils/File.h>

namespace Newton {
	/**
	 * NShader Class
	 *
	 * This class creates a GPU program called a Shader based on GPU programs (Shaders) which are loaded from files.
	 *
	 */
	class NShader {
	private:
		GLuint ShaderID;

	public:
		/**
		 * NShader Constructor
		 *
		 * This default constructor loads the default shaders defined in the Engine Configuration file.
		 *
		 */
		NShader(void);

		/**
		 * NShader Constructor
		 *
		 * This constructor initializes the shader with the programs passed in as arguments.
		 *
		 * @param const GLchar* InVertexFilename: The path to the file containing the vertex shader.
		 * @param const GLchar* InFragmentFilename: The path to the file containing the fragment shader.
		 *
		 */
		explicit NShader(const GLchar* InVertexFilename, const GLchar* InFragmentFilename);

		/**
		 * NShader Bind
		 *
		 * This method binds the shader so that it can be used during rendering.
		 *
		 */
		inline void Bind(void) const { glUseProgram(ShaderID); }

		/**
		 * NShader Unbind
		 *
		 * This method unbinds the shader and should be called after the rendering finishes.
		 *
		 */
		inline void Unbind(void) const { glUseProgram(0); }

		/**
		 * NShader GetAttributeLocation
		 *
		 * This method gets the index that represents a shader attribute provided you know it's name.
		 *
		 * @param const GLchar* InAttribute: The name of the attribute in the shader.
		 *
		 * @return GLint: The index of the attribute.
		 *
		 */
		inline GLint GetAttributeLocation(const GLchar* InAttribute) const { return glGetAttribLocation(ShaderID, InAttribute); }

		/**
		 * NShader GetUniformLocation
		 *
		 * This method gets the index that represents a shader uniform provided you know it's name.
		 *
		 * @param const GLchar* InUniform: The name of the uniform in the shader.
		 *
		 * @return GLint: The index of the uniform.
		 *
		 */
		inline GLint GetUniformLocation(const GLchar* InUniform) const { return glGetUniformLocation(ShaderID, InUniform); }
		
	private:
		/**
		 * NShader LoadShader
		 *
		 * This method loads the shaders found in the given paths.
		 *
		 * @param const GLchar* InVertexFilename: The path to the file containing the vertex shader.
		 * @param const GLchar* InFragmentFilename: The path to the file containing the fragment shader.
		 *
		 */
		void LoadShader(const GLchar* InVertexFilename, const GLchar* InFragmentFilename);

		/**
		 * NShader CheckCompile
		 *
		 * This method checks and logs if the compilation of a given shader was successful.
		 *
		 * @param const GLuint InID: The ID of the shader to check the compilation of.
		 *
		 */
		void CheckCompile(const GLuint InID) const;

		/**
		 * NShader CheckLink
		 *
		 * This method checks and logs if the linking of the program was successful.
		 *
		 */
		void CheckLink(void) const;

		/**
		 * NShader CheckValidate
		 *
		 * This method checks and logs if the validation of the program was successful.
		 *
		 */
		void CheckValidate(void) const;
	};
}