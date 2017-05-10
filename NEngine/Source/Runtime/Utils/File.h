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
	 * ...
	 *
	 * @param const GLchar* InFilename: ...
	 * @param const GLuint InBufferSize: ...
	 * @param GLchar* InBuffer: ...
	 *
	 */
	inline void ReadFile(const GLchar* InFilename, const GLuint InBufferSize, GLchar* InBuffer);
}