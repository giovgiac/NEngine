/**
 * Game.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "Game.h"

namespace Newton {
	static NPlayer* PlayerS = nullptr;

	NGame::NGame(void) {
		InitializeGL();

		// Create Window and World
		Window = new NWindow(DefaultWindowWidth, DefaultWindowHeight, DefaultWindowTitle, DefaultWindowFullscreen);
		World = new NWorld();

		// Bind Callbacks
		Window->SetCursorPosCallback(&OnMouseMove);
		Window->SetKeyCallback(&OnKeyDown);
		Window->SetMouseButtonCallback(&OnMouseDown);
	}

	NGame::NGame(const GLchar* InTitle) {
		InitializeGL();

		// Create Window and World
		Window = new NWindow(DefaultWindowWidth, DefaultWindowHeight, InTitle, DefaultWindowFullscreen);
		World = new NWorld();

		// Bind Callbacks
		Window->SetCursorPosCallback(&OnMouseMove);
		Window->SetKeyCallback(&OnKeyDown);
		Window->SetMouseButtonCallback(&OnMouseDown);
	}

	NGame::NGame(const GLsizei InWidth, const GLsizei InHeight, const GLchar* InTitle, const GLboolean InFullscreen) {
		InitializeGL();

		// Create Window and World
		Window = new NWindow(InWidth, InHeight, InTitle, InFullscreen);
		World = new NWorld();

		// Bind Callbacks
		Window->SetCursorPosCallback(&OnMouseMove);
		Window->SetKeyCallback(&OnKeyDown);
		Window->SetMouseButtonCallback(&OnMouseDown);
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

	void NGame::SetPlayer(NPlayer* InPlayer) {
		Player = InPlayer;
		PlayerS = InPlayer;
	}

	void NGame::InitializeGL(void) const {
		// Initialize GLFW
		if (!glfwInit()) {
			fprintf(stderr, "ERROR: Failed to initialize GLFW\n");
			exit(EXIT_FAILURE);
		}
	}

	void OnKeyDown(GLFWwindow* InWindow, GLint InKey, GLint InScancode, GLint InAction, GLint InMods) {
		if (PlayerS)
			PlayerS->OnKeyDown(InKey, InScancode, InAction, InMods);
	}

	void OnMouseDown(GLFWwindow* InWindow, GLint InButton, GLint InAction, GLint InMods) {
		if (PlayerS)
			PlayerS->OnMouseDown(InButton, InAction, InMods);
	}

	void OnMouseMove(GLFWwindow* InWindow, GLdouble InX, GLdouble InY) {
		if (PlayerS)
			PlayerS->OnMouseMove(InX, InY);
	}
}