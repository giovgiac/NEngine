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
	 * @param GLuint* OutLength: The size of the allocated buffer with the contents.
	 *
	 */
	extern GLchar* ReadFile(const GLchar* InFilename, GLuint* OutLength = nullptr);
}