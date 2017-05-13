/**
 * Camera.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <Core/Config.h>
#include <Math/Matrix.h>

namespace Newton {
	/**
	 * NCamera Class
	 *
	 * This class is responsible for creating and managing the virtual camera in the world.
	 *
	 */
	class NCamera {
	protected:
		GLfloat Left;
		GLfloat Right;
		GLfloat Bottom;
		GLfloat Top;
		GLfloat Near;
		GLfloat Far;

	public:
		/**
		 * NCamera Constructor
		 *
		 * This default constructor initializes the camera to the default configuration values.
		 *
		 */
		NCamera(void);

		/**
		 * NCamera Constructor
		 *
		 * This constructor initializes the camera with the given left, right, bottom and top planes and uses the near and far from the default configuration.
		 *
		 * @param const GLfloat InRight: The value to clip the camera at the right.
		 * @param const GLfloat InTop: The value to clip the camera at the top.
		 *
		 */
		NCamera(const GLfloat InRight, const GLfloat InTop);

		/**
		 * NCamera Constructor
		 *
		 * This constructor initializes the camera with the given left, right, bottom, top, near and far planes.
		 *
		 * @param const GLfloat InLeft: The value to clip the camera at the left.
		 * @param const GLfloat InRight: The value to clip the camera at the right.
		 * @param const GLfloat InBottom: The value to clip the camera at the bottom.
		 * @param const GLfloat InTop: The value to clip the camera at the top.
		 * @param const GLfloat InNear: The value to clip the camera at the near.
		 * @param const GLfloat InFar: The value to clip the camera at the far.
		 *
		 */
		explicit NCamera(const GLfloat InLeft, const GLfloat InRight, const GLfloat InBottom, const GLfloat InTop, const GLfloat InNear, const GLfloat InFar);

		/**
		 * NCamera SetCamera
		 *
		 * This method updates the camera clipping planes with the new given values.
		 *
		 * @param const GLfloat InLeft: The new value to clip the camera at the left.
		 * @param const GLfloat InRight: The new value to clip the camera at the right.
		 * @param const GLfloat InBottom: The new value to clip the camera at the bottom.
		 * @param const GLfloat InTop: The new value to clip the camera at the top.
		 * @param const GLfloat InNear: The new value to clip the camera at the near.
		 * @param const GLfloat InFar: The new value to clip the camera at the far.
		 *
		 */
		void SetCamera(const GLfloat InLeft, const GLfloat InRight, const GLfloat InBottom, const GLfloat InTop, const GLfloat InNear, const GLfloat InFar);

		/**
		 * NCamera GetView
		 *
		 * This method gets the view matrix from this camera.
		 *
		 * @return NMatrix: The view matrix of the camera.
		 *
		 */
		inline NMatrix GetView(void) const { return NMatrix::Identity(); }

		/**
		 * NCamera GetProjection
		 *
		 * This method gets the orthographic projection matrix from this camera.
		 *
		 * @return NMatrix: The projection matrix of the camera.
		 *
		 */
		NMatrix GetProjection(void) const { return NMatrix::Orthographic(Left, Right, Bottom, Top, Near, Far); }
	};
}