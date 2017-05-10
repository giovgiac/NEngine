/**
 * File.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "File.h"

namespace Newton {
	void ReadFile(const GLchar* InFilename, GLchar* OutBuffer, GLuint* OutLength) {
		GLuint Size;
		FILE* File = fopen(InFilename, "rb");

		// Determine File Size in Bytes
		fseek(File, 0, SEEK_END);
		Size = ftell(File);

		// Allocate Buffer
		OutBuffer = new GLchar[Size + 1];

		// Copy Contents to Buffer
		fseek(File, 0, SEEK_SET);
		fread(OutBuffer, sizeof(GLchar), Size, File);
		fclose(File);

		if (OutLength)
			*OutLength = Size;
		OutBuffer[Size] = '\0';
		return;
	}
}