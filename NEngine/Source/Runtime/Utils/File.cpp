/**
 * File.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "File.h"

namespace Newton {
	GLchar* ReadFile(const GLchar* InFilename, GLuint* OutLength) {
		GLchar* Buffer;
		GLuint Size;
		FILE* File = fopen(InFilename, "rb");

		// Determine File Size in Bytes
		fseek(File, 0, SEEK_END);
		Size = ftell(File);

		// Allocate Buffer
		Buffer = new GLchar[Size + 1];

		// Copy Contents to Buffer
		fseek(File, 0, SEEK_SET);
		fread(Buffer, sizeof(GLchar), Size, File);
		fclose(File);

		if (OutLength)
			*OutLength = Size;
		Buffer[Size] = '\0';
		return Buffer;
	}
}