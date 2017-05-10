/**
 * Config.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <glew.h>

namespace Newton {
	/**
	 * This configuration sets the default vertex shader file to be loaded by the Shader class.
	 */
	const GLchar* DefaultVertexFilename = "Shaders/Default.vert";

	/**
	 * This configuration sets the default fragment shader file to be loaded by the Shader class.
	 */
	const GLchar* DefaultFragmentFilename = "Shaders/Default.frag";
}