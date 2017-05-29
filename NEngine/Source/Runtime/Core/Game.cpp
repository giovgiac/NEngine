/**
 * Game.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "Game.h"

namespace Newton {
	static void KeyDown(GLFWwindow* InWindow, GLint InKey, GLint InScancode, GLint InAction, GLint InMods) {
		NGame* Game = (NGame*)glfwGetWindowUserPointer(InWindow);

		if (Game)
			if (Game->OnKeyDown)
				Game->OnKeyDown->Call(Game->GetWindow(), InKey, InScancode, InAction, InMods);
	}

	static void MouseDown(GLFWwindow* InWindow, GLint InButton, GLint InAction, GLint InMods) {
		NGame* Game = (NGame*)glfwGetWindowUserPointer(InWindow);

		if (Game)
			if (Game->OnMouseDown)
				Game->OnMouseDown->Call(Game->GetWindow(), InButton, InAction, InMods);
	}

	static void MouseMove(GLFWwindow* InWindow, GLdouble InX, GLdouble InY) {
		NGame* Game = (NGame*)glfwGetWindowUserPointer(InWindow);

		if (Game)
			if (Game->OnMouseMove)
				Game->OnMouseMove->Call(Game->GetWindow(), InX, InY);
	}

	NGame::NGame(void) {
		InitializeFMOD();
		InitializeGL();

		// Create Window and World
		Window = new NWindow(DefaultWindowWidth, DefaultWindowHeight, DefaultWindowTitle, DefaultWindowFullscreen);
		World = new NWorld();

		// Bind Callbacks
		Window->SetCursorPosCallback(&MouseMove);
		Window->SetKeyCallback(&KeyDown);
		Window->SetMouseButtonCallback(&MouseDown);

		// Set User Pointer
		Window->SetWindowUserPointer(this);
	}

	NGame::NGame(const GLchar* InTitle) {
		InitializeFMOD();
		InitializeGL();

		// Create Window and World
		Window = new NWindow(DefaultWindowWidth, DefaultWindowHeight, InTitle, DefaultWindowFullscreen);
		World = new NWorld();

		// Bind Callbacks
		Window->SetCursorPosCallback(&MouseMove);
		Window->SetKeyCallback(&KeyDown);
		Window->SetMouseButtonCallback(&MouseDown);

		// Set User Pointer
		Window->SetWindowUserPointer(this);
	}

	NGame::NGame(const GLsizei InWidth, const GLsizei InHeight, const GLchar* InTitle, const GLboolean InFullscreen) {
		InitializeFMOD();
		InitializeGL();

		// Create Window and World
		Window = new NWindow(InWidth, InHeight, InTitle, InFullscreen);
		World = new NWorld();

		// Bind Callbacks
		Window->SetCursorPosCallback(&MouseMove);
		Window->SetKeyCallback(&KeyDown);
		Window->SetMouseButtonCallback(&MouseDown);

		// Set User Pointer
		Window->SetWindowUserPointer(this);
	}

	NGame::~NGame(void) {
		// Delete Event Handlers
		if (OnKeyDown)
			delete OnKeyDown;
		
		if (OnMouseDown)
			delete OnMouseDown;

		if (OnMouseMove)
			delete OnMouseMove;

		// Terminate GLFW
		glfwTerminate();

		// Terminate FMOD
		FMOD_System_Close(FMODSystem);
		FMOD_System_Release(FMODSystem);
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
			FMOD_System_Update(FMODSystem);
		}

		World->UnloadScene();
	}

	void NGame::SetPlayer(NPlayer* InPlayer) {
		Player = InPlayer;
	}

	void NGame::InitializeFMOD(void) const {
		GLuint FMODVersion = 0;
		
		if (FMOD_System_Create(&FMODSystem) != FMOD_OK) {
			fprintf(stderr, "ERROR: Failed to initialize FMOD\n");
			exit(EXIT_FAILURE);
		}

		FMOD_System_Init(FMODSystem, 36, FMOD_INIT_NORMAL, nullptr);

		// Log FMOD Information
		FMOD_System_GetVersion(FMODSystem, &FMODVersion);
		fprintf(stdout, "LOG: FMOD Version %d\n", FMODVersion);
	}

	void NGame::InitializeGL(void) const {
		// Initialize GLFW
		if (!glfwInit()) {
			fprintf(stderr, "ERROR: Failed to initialize GLFW\n");
			exit(EXIT_FAILURE);
		}
	}
}