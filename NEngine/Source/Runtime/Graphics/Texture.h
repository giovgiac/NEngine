/** 
 * Texture.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <FreeImage.h>
#include <glew.h>

namespace Newton {
	/**
	 * NTexture Class
	 *
	 * This class is responsible for creating 2D textures for the game and GPU.
	 *
	 */
	class NTexture {
	private:
		GLuint TextureID;
		GLsizei Width;
		GLsizei Height;

	public:
		/**
		 * NTexture Constructor
		 *
		 * This default constructor creates and loads a 2D texture in the game and GPU.
		 *
		 * @param const GLchar* InFilename: The path to the image file of the texture.
		 *
		 */
		explicit NTexture(const GLchar* InFilename);

		/**
		 * NTexture Bind
		 *
		 * This method binds the texture so that it can be used in rendering.
		 *
		 */
		void Bind(void) const;

		/**
		 * NTexture Unbind
		 *
		 * This method unbinds the texture and should be used after rendering.
		 *
		 */
		void Unbind(void) const;

		/**
		 * NTexture GetWidth
		 *
		 * This method returns the width of the selected instance of texture.
		 *
		 * @return GLsizei: The width of the texture.
		 *
		 */
		GLsizei GetWidth(void) const;

		/**
		 * NTexture GetHeight
		 *
		 * This method returns the height of the selected instance of the texture.
		 *
		 * @return GLsizei: The height of the texture.
		 *
		 */
		GLsizei GetHeight(void) const;

	private:
		/**
		 * NTexture LoadTexture
		 *
		 * This method loads a texture into the GPU.
		 *
		 * @param const GLchar* InFilename: The path to the image file of the texture.
		 *
		 */
		void LoadTexture(const GLchar* InFilename);

		/**
		 * NTexture ReadImage
		 *
		 * This method reads an image file using FreeImage.
		 *
		 * @param const GLchar* InFilename: The path to the image file of the texture.
		 *
		 * @return const FIBITMAP*: The structure that represents an image loaded by FreeImage.
		 *
		 */
		FIBITMAP* ReadImage(const GLchar* InFilename) const;
	};
}