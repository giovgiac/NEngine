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
	const GLchar* DefaultVertexFilename = "Shaders/Default.vert";

	/**
	 * This configuration sets the default fragment shader file to be loaded by the shader.
	 */
	const GLchar* DefaultFragmentFilename = "Shaders/Default.frag";

	/**
	 * This configuration sets the default clipping number for the left of the orthographic projection.
	 */
	const GLfloat DefaultCameraLeft = 0.0f;

	/**
	 * This configuration sets the default clipping number for the right of the orthographic projection.
	 */
	const GLfloat DefaultCameraRight = 1280.0f;

	/**
	 * This configuration sets the default clipping number for the bottom of the orthographic projection.
	 */
	const GLfloat DefaultCameraBottom = 0.0f;

	/**
	 * This configuration sets the default clipping number for the top of the orthographic projection.
	 */
	const GLfloat DefaultCameraTop = 768.0f;

	/**
	 * This configuration sets the default clipping number for the near of the orthographic projection.
	 */
	const GLfloat DefaultCameraNear = -1.0f;

	/**
	 * This configuration sets the default clipping number for the far of the orthographic projection.
	 */
	const GLfloat DefaultCameraFar = 1.0f;
}