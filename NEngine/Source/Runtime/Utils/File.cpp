/**
 * File.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "File.h"

namespace Newton {
	void ReadFile(const GLchar* InFilename, const GLuint InBufferSize, GLchar* InBuffer) {
		GLuint Size;
		FILE* File = fopen(InFilename, "rb");

		// Determine File Size in Bytes
		fseek(File, 0, SEEK_END);
		Size = ftell(File);

		// Return If Not Enough Space
		if (Size >= InBufferSize) {
			fprintf(stderr, "WARNING: File didn't fit on Buffer\n");
			InBuffer = nullptr;
			return;
		}

		// Copy Contents to Buffer
		fseek(File, 0, SEEK_SET);
		fread(InBuffer, sizeof(GLchar), Size, File);
		fclose(File);

		InBuffer[Size] = '\0';
		return;
	}
}