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
	static const GLfloat DefaultSceneWidth = 160.0f;

	/**
	 * This configuration sets the default height for the scenes.
	 */
	static const GLfloat DefaultSceneHeight = 120.0f;

	/** 
	 * This configuration sets the default width for windows.
	 */
	static const GLsizei DefaultWindowWidth = 1280;

	/**
	 * This configuration sets the default height for windows.
	 */
	static const GLsizei DefaultWindowHeight = 768;

	/**
	 * This configuration sets the default title for windows.
	 */
	static const GLchar* DefaultWindowTitle = "Newton Game";

	/**
	 * This configuration sets whether the window is fullscreen by default.
	 */
	static const GLboolean DefaultWindowFullscreen = false;
}