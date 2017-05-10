/**
 * File.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <glew.h>
#include <stdio.h>

namespace Newton {
	/**
	 * ReadFile Function
	 *
	 * This function reads a given text file from disk and allocates a buffer to hold it in memory.
	 *
	 * @param const GLchar* InFilename: The path to the file to be read.
	 * @param GLchar* OutBuffer: The buffer to point to the contents.
	 * @param GLuint* OutLength: The size of the allocated buffer with the contents.
	 *
	 */
	inline void ReadFile(const GLchar* InFilename, GLchar* OutBuffer, GLuint* OutLength = nullptr);
}