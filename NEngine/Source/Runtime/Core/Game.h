/**
 * Game.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <Audio/Source.h>
#include <Core/Event.h>
#include <Core/Player.h>
#include <Graphics/Window.h>
#include <Graphics/World.h>

namespace Newton {
	/**
	 * NGame Class
	 *
	 * This class is meant to be inherited from and to create the game using NEngine.
	 *
	 */
	class NGame {
	protected:
		NPlayer* Player;
		NWindow* Window;
		NWorld* World;

	public:
		NEventHandler<NWindow*, GLint, GLint, GLint, GLint>* OnKeyDown;
		NEventHandler<NWindow*, GLint, GLint, GLint>* OnMouseDown;
		NEventHandler<NWindow*, GLdouble, GLdouble>* OnMouseMove;

	public:
		/**
		 * NGame Constructor
		 *
		 * This default constructor creates a game with the default configurations.
		 *
		 */
		NGame(void);

		/**
		 * NGame Constructor
		 *
		 * This constructor creates a game with the given title for the window.
		 *
		 * @param const GLchar* InTitle: The title of the game window.
		 *
		 */
		explicit NGame(const GLchar* InTitle);

		/**
		 * NGame Constructor
		 *
		 * This constructor creates a game with the given configuration for the window.
		 *
		 * @param const GLsizei InWidth: The width of the window.
		 * @param const GLsizei InHeight: The height of the window.
		 * @param const GLchar* InTitle: The title of the window.
		 * @param const GLboolean InFullscreen: Whether the window is in fullscreen or not.
		 *
		 */
		explicit NGame(const GLsizei InWidth, const GLsizei InHeight, const GLchar* InTitle, const GLboolean InFullscreen);

		/**
		 * NGame Destructor
		 *
		 * This method destroys the game by cleaning up memory.
		 *
		 */
		~NGame(void);

		/**
		 * NGame BeforePlay
		 *
		 * This method is called immediately before play and the beginning of the main engine loop.
		 *
		 */
		virtual void BeforePlay(void) = 0;

		/**
		 * NGame Play
		 *
		 * This method is called to play the game and starts the main engine loop.
		 *
		 */
		void Play(void);

		/**
		 * NGame SetPlayer
		 *
		 * This method sets the current player to the given value.
		 *
		 * @param NPlayer* InPlayer: The player to set to current.
		 *
		 */
		void SetPlayer(NPlayer* InPlayer);

		/**
		 * NGame GetWindow
		 *
		 * This method gets a pointer to the window of this game.
		 *
		 * @return const NWindow*: A pointer to the window.
		 *
		 */
		inline NWindow* GetWindow(void) const { return Window; }

		/**
		 * NGame GetWorld
		 *
		 * This method gets the value of the world of this game.
		 *
		 * @return const NWorld&: A reference to the world.
		 *
		 */
		inline const NWorld& GetWorld(void) const { return *World; }

	private:
		/**
		 * NGame InitializeFMOD
		 *
		 * This method initializes FMOD through it's library.
		 *
		 */
		void InitializeFMOD(void) const;

		/**
		 * NGame InitializeGL
		 *
		 * This method initializes OpenGL through the libraries GLFW and GLEW.
		 *
		 */
		void InitializeGL(void) const;
	};
}