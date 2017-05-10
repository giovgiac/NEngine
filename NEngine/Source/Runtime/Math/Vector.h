/**
 * Vector.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <glew.h>

namespace Newton {
	/**
	 * NVector Struct
	 *
	 * This data type is for holding a vector in 2-D space, using OpenGL floating-point coordinates.
	 *
	 */
	struct NVector {
		GLfloat X;
		GLfloat Y;

		/**
		 * NVector Constructor
		 *
		 * The default constructor which initializes the vector to the zero vector.
		 *
		 */
		inline NVector(void)
			: X(0.0f), Y(0.0f) {}

		/**
		 * NVector Constructor
		 * 
		 * This constructor initializes the vector with components equal to the same floating-point number.
		 *
		 * @param GLfloat InF: The value to initialize the components to.
		 *
		 */
		explicit inline NVector(GLfloat InF)
			: X(InF), Y(InF) {}

		/**
		 * NVector Constructor
		 *
		 * This constructor initializes the vector to given floating-point values.
		 *
		 * @param GLfloat InX: The value of the X coordinate.
		 * @param GLfloat InY: The value of the Y coordinate.
		 *
		 */
		explicit inline NVector(GLfloat InX, GLfloat InY)
			: X(InX), Y(InY) {}
	};
}