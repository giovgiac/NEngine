/**
 * Texture.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "Texture.h"

namespace Newton {
	NTexture::NTexture(const GLchar* InFilename) {
		LoadTexture(InFilename);
	}

	void NTexture::Bind(void) const {
		glBindTexture(GL_TEXTURE_2D, TextureID);
	}

	void NTexture::Unbind(void) const {
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	GLsizei NTexture::GetWidth(void) const { 
		return Width; 
	}

	GLsizei NTexture::GetHeight(void) const {
		return Height;
	}

	void NTexture::LoadTexture(const GLchar* InFilename) {
		BYTE* Data;
		FIBITMAP* Bitmap = ReadImage(InFilename);

		// Extract Information from Image
		Width = FreeImage_GetWidth(Bitmap);
		Height = FreeImage_GetHeight(Bitmap);
		Data = FreeImage_GetBits(Bitmap);

		// Store Texture on GPU
		glGenTextures(1, &TextureID);
		glBindTexture(GL_TEXTURE_2D, TextureID);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Width, Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, Width, Height, GL_BGRA, GL_UNSIGNED_BYTE, Data);
		glGenerateMipmap(GL_TEXTURE_2D);
		glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D, 0);

		// Release Image from Memory
		FreeImage_Unload(Bitmap);
	}

	FIBITMAP* NTexture::ReadImage(const GLchar* InFilename) const {
		FIBITMAP* Bitmap = nullptr;
		FREE_IMAGE_FORMAT ImageFormat = FIF_UNKNOWN;

		ImageFormat = FreeImage_GetFileType(InFilename, 0);
		if (ImageFormat == FIF_UNKNOWN)
			ImageFormat = FreeImage_GetFIFFromFilename(InFilename);
		if (ImageFormat == FIF_UNKNOWN)
			return nullptr;

		if (FreeImage_FIFSupportsReading(ImageFormat))
			Bitmap = FreeImage_Load(ImageFormat, InFilename);
		if (!Bitmap)
			return nullptr;

		return Bitmap;
	}
}