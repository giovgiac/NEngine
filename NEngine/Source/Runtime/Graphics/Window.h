/**
 * Window.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <glew.h>
#include <glfw3.h>
#include <stdio.h>
#include <stdlib.h>

namespace Newton {
	/** 
	 * NWindow Class
	 *
	 * This class is responsible for creating windows using the GLFW library.
	 *
	 */
	class NWindow sealed {
	private:
		GLFWwindow* Window;
		GLsizei Width;
		GLsizei Height;
		GLboolean Fullscreen;

	public:
		/**
		 * NWindow Constructor
		 *
		 * This default constructor creates a window with the given width, height, title and whether is fullscreen.
		 *
		 * @param const GLsizei InWidth: The width of the window.
		 * @param const GLsizei InHeight: The height of the window.
		 * @param const GLchar* InTitle: The title of the window.
		 * @param const GLboolean InFullscreen: Whether the window is fullscreen or not.
		 *
		 */
		explicit NWindow(const GLsizei InWidth, const GLsizei InHeight, const GLchar* InTitle, const GLboolean InFullscreen);

		/**
		 * NWindow Destructor
		 *
		 * This destructor destroys the window to clean up.
		 *
		 */
		~NWindow(void);

		/**
		 * NWindow Destroy
		 *
		 * This method destroys the GLFW window.
		 *
		 */
		inline void Destroy(void) { glfwDestroyWindow(Window); }

		/**
		 * NWindow PollEvents
		 *
		 * This method polls the keyboard, mouse and joystick events.
		 *
		 */
		inline void PollEvents(void) const { glfwPollEvents(); }

		/**
		 * NWindow SetCursorPosCallback
		 *
		 * This method sets the cursor callback to a given function.
		 *
		 * @param GLFWcursorposfun InCallback: The function to call when the cursor changes position.
		 *
		 */
		inline void SetCursorPosCallback(GLFWcursorposfun InCallback) const { glfwSetCursorPosCallback(Window, InCallback); }

		/**
		 * NWindow SetKeyCallback
		 *
		 * This method sets the key callback to a given function.
		 *
		 * @param GLFWkeyfun InCallback: The function to call when the keyboard is pressed.
		 *
		 */
		inline void SetKeyCallback(GLFWkeyfun InCallback) const { glfwSetKeyCallback(Window, InCallback); }

		/**
		 * NWindow SetMouseButtonCallback
		 *
		 * This method sets the mouse button callback to a given function.
		 *
		 * @param GLFWmousebuttonfun InCallback: The function to call when the mouse buttons are pressed.
		 *
		 */
		inline void SetMouseButtonCallback(GLFWmousebuttonfun InCallback) const { glfwSetMouseButtonCallback(Window, InCallback); }

		/**
		 * NWindow SwapBuffers
		 *
		 * This method swaps the buffers in OpenGL.
		 *
		 */
		inline void SwapBuffers(void) const { glfwSwapBuffers(Window); }

		/**
		 * NWindow UpdateViewport
		 *
		 * This method updates the OpenGL viewport.
		 *
		 */
		void UpdateViewport(void);

		/**
		 * NWindow ShouldClouse
		 *
		 * This method gets whether the window should close.
		 *
		 * @return GLboolean: Whether the window should close.
		 *
		 */
		inline GLboolean ShouldClose(void) const { return glfwWindowShouldClose(Window); }

		/**
		 * NWindow GetWidth
		 *
		 * This method gets the window current width.
		 *
		 * @return GLsizei: The window width.
		 *
		 */
		inline GLsizei GetWidth(void) const { return Width; }

		/**
		 * NWindow GetHeight
		 *
		 * This method gets the window current height.
		 *
		 * @return GLsizei: The window height.
		 *
		 */
		inline GLsizei GetHeight(void) const { return Height; }
	};
}