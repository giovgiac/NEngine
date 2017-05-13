/**
 * Game.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "Game.h"

namespace Newton {
	NGame::NGame(void) {
		InitializeGL();

		// Create Window and World
		Window = new NWindow(DefaultWindowWidth, DefaultWindowHeight, DefaultWindowTitle, DefaultWindowFullscreen);
		World = new NWorld();
	}

	NGame::NGame(const GLchar* InTitle) {
		InitializeGL();

		// Create Window and World
		Window = new NWindow(DefaultWindowWidth, DefaultWindowHeight, InTitle, DefaultWindowFullscreen);
		World = new NWorld();
	}

	NGame::NGame(const GLsizei InWidth, const GLsizei InHeight, const GLchar* InTitle, const GLboolean InFullscreen) {
		InitializeGL();

		// Create Window and World
		Window = new NWindow(InWidth, InHeight, InTitle, InFullscreen);
		World = new NWorld();
	}

	void NGame::Play(void) {
		BeforePlay();
		for (GLuint i = 0; i < World->GetScene().GetObjects().GetSize(); i++)
			World->GetScene().GetObjects()[i]->Start();

		// Main Engine Loop
		while (!Window->ShouldClose()) {
			Window->UpdateViewport();
			World->Draw();
			for (GLuint i = 0; i < World->GetScene().GetObjects().GetSize(); i++)
				World->GetScene().GetObjects()[i]->Tick();
			Window->SwapBuffers();
			Window->PollEvents();
		}

		World->UnloadScene();
	}

	void NGame::InitializeGL(void) const {
		// Initialize GLFW
		if (!glfwInit()) {
			fprintf(stderr, "ERROR: Failed to initialize GLFW\n");
			exit(EXIT_FAILURE);
		}
	}
}