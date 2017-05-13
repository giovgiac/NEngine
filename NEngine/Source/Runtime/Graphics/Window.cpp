/**
 * Window.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "Window.h"

namespace Newton {
	NWindow::NWindow(const GLsizei InWidth, const GLsizei InHeight, const GLchar* InTitle, const GLboolean InFullscreen)
		: Width(InWidth), Height(InHeight), Fullscreen(InFullscreen)
	{
		GLenum Status;
		const GLubyte* GLVersion;
		const GLubyte* GLSLVersion;

		Window = glfwCreateWindow(Width, Height, InTitle, InFullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);
		if (!Window)
			fprintf(stderr, "ERROR: Failed to create OpenGL Window\n"),
			glfwTerminate();
		glfwMakeContextCurrent(Window);

		// Initialize GLEW
		glewExperimental = true;
		Status = glewInit();
		if (Status != GLEW_OK) {
			fprintf(stderr, "ERROR: Failed to initialize GLEW\n");
			exit(EXIT_FAILURE);
		}

		// Log OpenGL Information
		GLVersion = glGetString(GL_VERSION);
		GLSLVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
		fprintf(stdout, "LOG: OpenGL Version %s\n", GLVersion);
		fprintf(stdout, "LOG: GLSL Version %s\n", GLSLVersion);
	}

	NWindow::~NWindow(void) {
		Destroy();
	}

	void NWindow::UpdateViewport(void) {
		glfwGetFramebufferSize(Window, &Width, &Height);
		glViewport(0, 0, Width, Height);
	}
}