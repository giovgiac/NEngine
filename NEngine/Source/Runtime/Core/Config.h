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
	 * This configuration sets the default vertex shader file to be loaded by the shader.
	 */
	static const GLchar* DefaultVertexFilename = "Shaders/Default.vert";

	/**
	 * This configuration sets the default fragment shader file to be loaded by the shader.
	 */
	static const GLchar* DefaultFragmentFilename = "Shaders/Default.frag";

	/**
	 * This configuration sets the default clipping number for the near of the orthographic projection.
	 */
	static const GLfloat DefaultCameraNear = -1.0f;

	/**
	 * This configuration sets the default clipping number for the far of the orthographic projection.
	 */
	static const GLfloat DefaultCameraFar = 1.0f;

	/**
	 * This configuration sets the default width for the scenes.
	 */
	static const GLfloat DefaultSceneWidth = 1280.0f;

	/**
	 * This configuration sets the default height for the scenes.
	 */
	static const GLfloat DefaultSceneHeight = 768.0f;
}