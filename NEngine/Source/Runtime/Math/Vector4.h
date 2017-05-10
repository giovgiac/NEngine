/**
 * Vector4.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <glew.h>

namespace Newton {
	/**
	 * NVector4 Struct
	 *
	 * This data type holds a vector in 4-D space. It uses OpenGL floating-point numbers for storing the coordinates.
	 *
	 */
	struct NVector4 {
		GLfloat X;
		GLfloat Y;
		GLfloat Z;
		GLfloat W;

		/**
		 * NVector4 Constructor
		 *
		 * This default constructor initializes the vector to the zero vector.
		 *
		 */
		inline NVector4(void)
			: X(0.0f), Y(0.0f), Z(0.0f), W(0.0f) {}

		/**
		 * NVector4 Constructor
		 *
		 * This constructor initializes all coordinates in the vector with the same given floating-point value.
		 *
		 * @param GLfloat InF: The value to fill the coordinates with.
		 *
		 */
		explicit inline NVector4(GLfloat InF)
			: X(InF), Y(InF), Z(InF), W(InF) {}

		/**
		 * NVector4 Constructor
		 *
		 * This constructor initializes a vector with the given floating-point coordinates.
		 *
		 * @param GLfloat InX: The value of the X coordinate.
		 * @param GLfloat InY: The value of the Y coordinate.
		 * @param GLfloat InZ: The value of the Z coordinate.
		 * @param GLfloat InW: The value of the W coordinate.
		 *
		 */
		explicit inline NVector4(GLfloat InX, GLfloat InY, GLfloat InZ, GLfloat InW)
			: X(InX), Y(InY), Z(InZ), W(InW) {}
	};
}